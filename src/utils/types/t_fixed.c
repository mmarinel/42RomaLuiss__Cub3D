/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fixed.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:28:27 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/10 17:40:18 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_types.h"

static int32_t	fix_round(double val);
static void		fix_set_methods(t_fixed *fixed);
static void		fix_set_val(t_fixed *fixed, t_fixed_val val,
					t_bool inf, short sign);
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

double	t_fix_to_double( t_fixed this )
{
	return (
		(double)this.fixed_val.row_bits
		/ (1 << this.fixed_val.frac_bits)
	);
}

int		t_fix_to_int( t_fixed this )
{
	return ((int)t_fix_to_double(this));
}

t_fixed	t_fix_sum(t_fixed a, t_fixed b)
{
	t_fixed sum;

	sum.fixed_val.row_bits = a.fixed_val.row_bits + b.fixed_val.row_bits;
	fix_set_methods(&sum);
}

t_fixed	t_fix_diff(t_fixed a, t_fixed b)
{
	t_fixed diff;

	diff.fixed_val.row_bits = a.fixed_val.row_bits - b.fixed_val.row_bits;
	fix_set_methods(&diff);
}

t_fixed	t_fix_mult(t_fixed this, t_fixed val)
{
	t_fixed	mult;

	mult.fixed_val.row_bits =
		(
			(int64_t)this.fixed_val.row_bits * (int64_t)val.fixed_val.row_bits
		)
		>> this.fixed_val.frac_bits;
	fix_set_methods(&mult);
	return (mult);
}

t_fixed	t_fix_div(t_fixed this, t_fixed val)
{
	t_fixed	quotient;

	if (0 == val.fixed_val.row_bits)
	{
		val.fixed_val.row_bits = 0;
		val.fixed_val.inf = e_true;
		val.fixed_val.inf = e_false;
	}
	quotient.fixed_val.row_bits
		= ((int64_t)this.fixed_val.row_bits << this.fixed_val.frac_bits)
		/ (int64_t)val.fixed_val.row_bits;
	fix_set_methods(&quotient);
	return (quotient);
}

double	t_fix_cmp(t_fixed this, t_fixed val)
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

void	ft_print_t_fixed(t_fixed var)
{
	if (var.fixed_val.inf)
		printf("<inf> ");
	else if (var.fixed_val.neg_inf)
		printf("<neg_inf> ");
	else
		printf("%lf ", t_fix_to_double(var));
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
	fixed_new->to_double.call = t_fix_to_double;
	fixed_new->to_int.val = fixed_new->fixed_val;
	fixed_new->to_int.call = t_fix_to_int;
	fixed_new->sum.val = fixed_new->fixed_val;
	fixed_new->sum.call = t_fix_sum;
	fixed_new->diff.val = fixed_new->fixed_val;
	fixed_new->diff.call = t_fix_diff;
	fixed_new->mult.val = fixed_new->fixed_val;
	fixed_new->mult.call = t_fix_mult;
	fixed_new->div.val = fixed_new->fixed_val;
	fixed_new->div.call = t_fix_div;
	fixed_new->cmp.val = fixed_new->fixed_val;
	fixed_new->cmp.call = t_fix_cmp;
	fixed_new->print.val = fixed_new->fixed_val;
	fixed_new->print.call = ft_print_t_fixed;
}

static void		fix_set_val(t_fixed *fixed, t_fixed_val val,
					t_bool inf, short sign)
{
	if (e_false == inf)
	{
		fixed->fixed_val.row_bits = 0;
		fixed->fixed_val.frac_bits = val.frac_bits;
		fixed->fixed_val.inf = (sign > 0);
		fixed->fixed_val.neg_inf = (sign < 0);
	}
	else
	{
		fixed->fixed_val.row_bits = val.row_bits;
		fixed->fixed_val.frac_bits = val.frac_bits;
		fixed->fixed_val.inf = e_false;
		fixed->fixed_val.neg_inf = e_false;
	}
}
