/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fx_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:53:32 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/11 12:10:27 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed_point.h"

double	_t_fixed_to_double( t_fixed this )
{
	return (
		(double)this.fixed_val.row_bits
		/ (1 << this.fixed_val.frac_bits)
	);
}

int		_t_fixed_to_int( t_fixed this )
{
	return ((int)t_fixed_to_double(this));
}
