/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:50:16 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/12 10:28:03 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

t_2d_point	ft_matrix_multiplication(t_2d_matrix matrix, t_2d_point vector)
{
	t_2d_point	product;

	product.x.val = ft_dot_product(
		ft_get_new_2dpt(matrix.col_1.x.val, matrix.col_1.x.val),
		vector
	);
	product.y.val = ft_dot_product(
		ft_get_new_2dpt(matrix.col_1.y.val, matrix.col_1.y.val),
		vector
	);
	return (product);
}

float	ft_dot_product(t_2d_point v, t_2d_point w)
{
	return (v.x.val * w.x.val + v.y.val * w.y.val);
}
