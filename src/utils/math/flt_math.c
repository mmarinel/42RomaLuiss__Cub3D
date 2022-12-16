/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:50:16 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/16 22:47:55 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uti_math.h"

float	flt_round(float nbr, size_t dec_places)
{
	const int	shift = pow(10, dec_places);
	int			int_repr;

	int_repr = nbr * shift;
	return ((float)int_repr / shift);
}
