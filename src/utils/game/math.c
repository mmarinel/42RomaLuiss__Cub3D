/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:50:16 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/02 12:20:56 by mmarinel         ###   ########.fr       */
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
	return (flt_round(res, FLT_PRECISION));
}

float	flt_round(float nbr, size_t dec_places)
{
	const int	shift = pow(10, dec_places);
	int			int_repr;

	int_repr = nbr * shift;
	return ((float)int_repr / shift);
}

float	ft_vec_norm(t_2d_point vector)
{
	return (sqrtf(ft_dot_product(vector, vector)));
}

t_2d_point	ft_vec_sum(t_2d_point v1, t_2d_point v2)
{
	t_2d_point	sum;

	sum.x = v1.x + v2.x;
	sum.y = v1.y + v2.y;

	return (sum);
}

t_2d_point	ft_vec_diff(t_2d_point v1, t_2d_point v2)
{
	return (ft_vec_sum(v1, ft_vec_opposite(v2)));
}

t_2d_point	ft_vec_opposite(t_2d_point vector)
{
	t_2d_point	opposite;

	opposite.x = (-1) * vector.x;
	opposite.y = (-1) * vector.y;
	return (opposite);
}
