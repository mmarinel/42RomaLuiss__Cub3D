/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_conditions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:54:44 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/11 15:14:48 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed_point.h"

double	t_fixed_cmp(t_fixed this, t_fixed val)
{
	if (this.inf || val.neg_inf)
		return (1);
	if (val.inf || this.neg_inf)
		return (-1);
	{
		if (this.frac_bits != val.frac_bits)
			return (
				(-1) * this.frac_bits - this.frac_bits
			);
		else
			return (this.row_bits - val.row_bits);
	}
}
