/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:57:04 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/11 17:43:28 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed_point.h"

//*		debug
void	t_fixed_print(t_fixed this)
{
	printf(YELLOW);
	printf("frac_bits: %d\n", this.frac_bits);
	printf("row_bits: %d\n", this.row_bits);
	if (this.inf)
		printf("calculated val: <inf>\n");
	else if (this.neg_inf)
		printf("calculated val: <neg_inf>\n");
	else
		printf("calculated val: %lf\n",t_fixed_to_double(this));
	printf(RESET);
}

int32_t	fix_round(double val)
{
	double	diff;

	diff = val - (int)val;
	if (diff < 0.5)
		return ((int)val);
	else
		return ((int)val + 1);
}

t_fixed	t_fixed_abs(t_fixed this)
{
	t_fixed	abs;

	abs = this;
	abs.row_bits *= (-1 * (abs.row_bits < 0) + 1 * (abs.row_bits >= 0));
	return (abs);
}
