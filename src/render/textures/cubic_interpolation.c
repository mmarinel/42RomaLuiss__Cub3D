/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubic_interpolation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 12:06:48 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/27 12:17:13 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

float	get_third_order_term(t_px_row row);
float	get_second_order_term(t_px_row row);
float	get_first_order_term(t_px_row row);
float	get_zeroth_order_term(t_px_row row);
//*		end of static declarations

int	cubic_interpolation(t_px_row row, int x)
{
	const float	third_order_term = get_third_order_term(row);
	const float	second_order_term = get_second_order_term(row);
	const float	first_order_term = get_first_order_term(row);
	const float	zeroth_order_term = get_zeroth_order_term(row);

	return (
		roundf(
			third_order_term * pow(x, 3)
			+ second_order_term * pow(x, 2)
			+ first_order_term * x
			+ zeroth_order_term
		)
	);
}

float	get_third_order_term(t_px_row row)
{
	return (
		(-1 / 2) * row.c0.rgb
		+ (3 / 2) * row.c1.rgb
		- (3 / 2) * row.c2.rgb
		+ (1 / 2) * row.c3.rgb
	);
}

float	get_second_order_term(t_px_row row)
{
	return (
		row.c0.rgb
		- (5 / 2) * row.c1.rgb
		+ (2) * row.c2.rgb
		- (1 / 2) * row.c3.rgb
	);
}

float	get_first_order_term(t_px_row row)
{
	return (
		(-1 / 2) * row.c0.rgb
		+ (1 / 2) * row.c2.rgb
	);
}

float	get_zeroth_order_term(t_px_row row)
{
	return (
		row.c1.rgb
	);
}
