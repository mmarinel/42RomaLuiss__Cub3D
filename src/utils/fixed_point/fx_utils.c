/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:57:04 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/11 12:10:39 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed_point.h"

//*		debug
void	_t_fixed_print(t_fixed this)
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

int32_t	_fix_round(double val)
{
	double	diff;

	diff = val - (int)val;
	if (diff < 0.5)
		return ((int)val);
	else
		return ((int)val + 1);
}

void	_fix_set_methods(t_fixed *fixed_new)
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
