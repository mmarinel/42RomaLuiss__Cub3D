/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:50:00 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/06 18:47:13 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

t_2d_point	ft_rotate(t_2d_point vector, double ray_angle)
{
	const t_2d_matrix	rotation_matrix = ft_get_new_2dmtrx(
			ft_get_new_2dpt(cos(ray_angle), sin(ray_angle)),
			ft_get_new_2dpt(-sin(ray_angle), cos(ray_angle))
		);
	return (ft_matrix_multiplication(rotation_matrix, vector));
}
