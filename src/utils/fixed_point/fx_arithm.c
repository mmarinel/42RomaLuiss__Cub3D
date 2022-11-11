/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_arithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:51:52 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/11 15:14:36 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed_point.h"

t_fixed	t_fixed_sum(t_fixed this, t_fixed val)
{
	t_fixed sum;
	int		frac_bits_diff;
	short	shift_direction;

	frac_bits_diff = this.frac_bits - val.frac_bits;
	shift_direction = (frac_bits_diff > 0);
	{
		if (shift_direction > 0)
			sum.row_bits = this.row_bits + (val.row_bits << frac_bits_diff);
		else if (shift_direction < 0)
			sum.row_bits = this.row_bits + (val.row_bits >> frac_bits_diff);
		else
			sum.row_bits = this.row_bits + val.row_bits;
	}
	sum.frac_bits = this.frac_bits;
	return (sum);
}

t_fixed	t_fixed_diff(t_fixed this, t_fixed val)
{
	t_fixed diff;
	int		frac_bits_diff;
	short	shift_direction;

	frac_bits_diff = this.frac_bits - val.frac_bits;
	shift_direction = (frac_bits_diff > 0);
	{
		if (shift_direction > 0)
			diff.row_bits = this.row_bits - (val.row_bits << frac_bits_diff);
		else if (shift_direction < 0)
			diff.row_bits = this.row_bits - (val.row_bits >> frac_bits_diff);
		else
			diff.row_bits = this.row_bits - val.row_bits;
	}
	diff.frac_bits = this.frac_bits;
	return (diff);
}

t_fixed	t_fixed_mult(t_fixed this, t_fixed val)
{
	t_fixed	mult;

	mult.row_bits =
		(
			(int64_t)this.row_bits * (int64_t)val.row_bits
		)
		>> val.frac_bits;
	mult.frac_bits = this.frac_bits;
	return (mult);
}

t_fixed	t_fixed_div(t_fixed this, t_fixed val)
{
	t_fixed	quotient;

	if (0 == val.row_bits)
	{
		quotient.row_bits = 0;
		quotient.frac_bits =  this.frac_bits;
		quotient.inf = (this.row_bits >= 0);
		quotient.neg_inf = (this.row_bits < 0);
	}
	else
	{
		quotient.row_bits
			= ((int64_t)this.row_bits << val.frac_bits)
			/ (int64_t)val.row_bits;
		quotient.frac_bits = this.frac_bits;
		quotient.inf = e_false;
		quotient.neg_inf = e_false;
	}
	return (quotient);
}
