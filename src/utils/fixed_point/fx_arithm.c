/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_arithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:51:52 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/11 12:10:13 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed_point.h"

t_fixed	_t_fixed_sum(t_fixed this, t_fixed val)
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

t_fixed	_t_fixed_diff(t_fixed this, t_fixed val)
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

t_fixed	_t_fixed_mult(t_fixed this, t_fixed val)
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

t_fixed	_t_fixed_div(t_fixed this, t_fixed val)
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
