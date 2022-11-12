/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:50:16 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/12 11:48:43 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

t_2d_point	ft_matrix_multiplication(t_2d_matrix matrix, t_2d_point vector)
{
	t_2d_point	product;

	product.x = ft_dot_product(
		ft_get_new_2dpt(matrix.col_1.x, matrix.col_1.x),
		vector
	);
	product.y = ft_dot_product(
		ft_get_new_2dpt(matrix.col_1.y, matrix.col_1.y),
		vector
	);
	return (product);
}

float	ft_dot_product(t_2d_point v, t_2d_point w)
{
	return (v.x * w.x + v.y * w.y);
}
