/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fixed.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:28:27 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/11 08:57:14 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_types.h"

static int32_t	fix_round(double val);
static void		fix_set_methods(t_fixed *fixed);
//*		end of static declarations

t_fixed	t_fixed_new(double val)
{
	t_fixed	fixed_new;

	fixed_new.fixed_val.frac_bits = e_FRAC_BITS;
	fixed_new.fixed_val.row_bits
		= fix_round(val * (1 << fixed_new.fixed_val.frac_bits));
	fixed_new.fixed_val.inf = e_false;
	fixed_new.fixed_val.neg_inf = e_false;
	fix_set_methods(&fixed_new);
	return (fixed_new);
}

double	t_fixed_to_double( t_fixed this )
{
	return (
		(double)this.fixed_val.row_bits
		/ (1 << this.fixed_val.frac_bits)
	);
}

int		t_fixed_to_int( t_fixed this )
{
	return ((int)t_fixed_to_double(this));
}

t_fixed	t_fixed_sum(t_fixed this, t_fixed val)
{
	t_fixed sum;
	int		frac_bits_diff;
	short	shift_direction;

	frac_bits_diff = this.fixed_val.frac_bits - val.fixed_val.frac_bits;
	shift_direction = (frac_bits_diff > 0);
	{
		if (shift_direction > 0)
			sum.fixed_val.row_bits = this.fixed_val.row_bits + (val.fixed_val.row_bits << frac_bits_diff);
		else if (shift_direction < 0)
			sum.fixed_val.row_bits = this.fixed_val.row_bits + (val.fixed_val.row_bits >> frac_bits_diff);
		else
			sum.fixed_val.row_bits = this.fixed_val.row_bits + val.fixed_val.row_bits;
	}
	sum.fixed_val.frac_bits = this.fixed_val.frac_bits;
	fix_set_methods(&sum);
	return (sum);
}

t_fixed	t_fixed_diff(t_fixed this, t_fixed val)
{
	t_fixed diff;
	int		frac_bits_diff;
	short	shift_direction;

	frac_bits_diff = this.fixed_val.frac_bits - val.fixed_val.frac_bits;
	shift_direction = (frac_bits_diff > 0);
	{
		if (shift_direction > 0)
			diff.fixed_val.row_bits = this.fixed_val.row_bits - (val.fixed_val.row_bits << frac_bits_diff);
		else if (shift_direction < 0)
			diff.fixed_val.row_bits = this.fixed_val.row_bits - (val.fixed_val.row_bits >> frac_bits_diff);
		else
			diff.fixed_val.row_bits = this.fixed_val.row_bits - val.fixed_val.row_bits;
	}
	diff.fixed_val.frac_bits = this.fixed_val.frac_bits;
	fix_set_methods(&diff);
	return (diff);
}

t_fixed	t_fixed_mult(t_fixed this, t_fixed val)
{
	t_fixed	mult;

	mult.fixed_val.row_bits =
		(
			(int64_t)this.fixed_val.row_bits * (int64_t)val.fixed_val.row_bits
		)
		>> val.fixed_val.frac_bits;
	mult.fixed_val.frac_bits = this.fixed_val.frac_bits;
	fix_set_methods(&mult);
	return (mult);
}

t_fixed	t_fixed_div(t_fixed this, t_fixed val)
{
	t_fixed	quotient;

	if (0 == val.fixed_val.row_bits)
	{
		quotient.fixed_val.row_bits = 0;
		quotient.fixed_val.frac_bits =  this.fixed_val.frac_bits;
		quotient.fixed_val.inf = (this.fixed_val.row_bits >= 0);
		quotient.fixed_val.neg_inf = (this.fixed_val.row_bits < 0);
	}
	else
	{
		quotient.fixed_val.row_bits
			= ((int64_t)this.fixed_val.row_bits << val.fixed_val.frac_bits)
			/ (int64_t)val.fixed_val.row_bits;
		quotient.fixed_val.frac_bits = this.fixed_val.frac_bits;
		quotient.fixed_val.inf = e_false;
		quotient.fixed_val.neg_inf = e_false;
	}
	fix_set_methods(&quotient);
	return (quotient);
}

double	t_fixed_cmp(t_fixed this, t_fixed val)
{
	if (this.fixed_val.inf || val.fixed_val.neg_inf)
		return (1);
	if (val.fixed_val.inf || this.fixed_val.neg_inf)
		return (-1);
	{
		if (this.fixed_val.frac_bits != val.fixed_val.frac_bits)
			return (
				(-1) * this.fixed_val.frac_bits - this.fixed_val.frac_bits
			);
		else
			return (this.fixed_val.row_bits - val.fixed_val.row_bits);
	}
}

void	t_fixed_print(t_fixed this)
{
	printf(YELLOW);
	printf("frac_bits: %d\n", this.fixed_val.frac_bits);
	printf("row_bits: %d\n", this.fixed_val.row_bits);
	if (this.fixed_val.inf)
		printf("calculated val: <inf>\n");
	else if (this.fixed_val.neg_inf)
		printf("calculated val: <neg_inf>\n");
	else
		printf("calculated val: %lf\n", t_fixed_to_double(this));
	printf(RESET);
}

static int32_t	fix_round(double val)
{
	double	diff;

	diff = val - (int)val;
	if (diff < 0.5)
		return ((int)val);
	else
		return ((int)val + 1);
}

static void		fix_set_methods(t_fixed *fixed_new)
{
	fixed_new->to_double.val = fixed_new->fixed_val;
	fixed_new->to_double.call = t_fixed_to_double;
	fixed_new->to_int.val = fixed_new->fixed_val;
	fixed_new->to_int.call = t_fixed_to_int;
	fixed_new->sum.val = fixed_new->fixed_val;
	fixed_new->sum.call = t_fixed_sum;
	fixed_new->diff.val = fixed_new->fixed_val;
	fixed_new->diff.call = t_fixed_diff;
	fixed_new->mult.val = fixed_new->fixed_val;
	fixed_new->mult.call = t_fixed_mult;
	fixed_new->div.val = fixed_new->fixed_val;
	fixed_new->div.call = t_fixed_div;
	fixed_new->cmp.val = fixed_new->fixed_val;
	fixed_new->cmp.call = t_fixed_cmp;
	fixed_new->print.val = fixed_new->fixed_val;
	fixed_new->print.call = t_fixed_print;
}
