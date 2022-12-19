/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorial_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:45:24 by earendil          #+#    #+#             */
/*   Updated: 2022/12/19 18:09:10 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uti_math.h"

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
	return (vec_1.x * vec_2.x + vec_1.y * vec_2.y);
}

float	ft_vec_norm(t_2d_point vector)
{
	return (sqrtf(ft_dot_product(vector, vector)));
}
