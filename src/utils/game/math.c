/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:50:16 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/12 12:52:17 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

t_2d_point	ft_matrix_multiplication(t_2d_matrix matrix, t_2d_point vector)
{
	t_2d_point	product;

	product.x = ft_dot_product(
		matrix.row_1,
		vector
	);
	product.y = ft_dot_product(
		matrix.row_2,
		vector
	);
	return (product);
}

float	ft_dot_product(t_2d_point vec_1, t_2d_point vec_2)
{
	float	res;

	res = vec_1.x * vec_2.x + vec_1.y * vec_2.y;
	return (flt_round(res, 6));
}

float	flt_round(float nbr, size_t dec_places)
{
	const int	shift = pow(10, dec_places);
	int			int_repr;

	int_repr = nbr * shift;
	return ((float)int_repr / shift);
}
