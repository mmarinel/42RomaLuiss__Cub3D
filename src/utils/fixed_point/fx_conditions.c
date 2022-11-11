/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_conditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:54:44 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/11 12:10:18 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed_point.h"

double	_t_fixed_cmp(t_fixed this, t_fixed val)
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
