/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_to_vec_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:47:06 by earendil          #+#    #+#             */
/*   Updated: 2022/12/16 22:49:04 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uti_math.h"

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

t_2d_point	ft_vec_prod(t_2d_point vec, float lambda)
{
	t_2d_point	prod;

	prod.x = vec.x * lambda;
	prod.y = vec.y * lambda;
	return (prod);
}

t_2d_point	ft_vec_opposite(t_2d_point vector)
{
	t_2d_point	opposite;

	opposite.x = (-1) * vector.x;
	opposite.y = (-1) * vector.y;
	return (opposite);
}
