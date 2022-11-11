/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:50:00 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/11 17:53:58 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

t_2d_point	ft_rotate(t_2d_point vector, t_fixed ray_angle)
{
	const t_2d_matrix	rotation_matrix = ft_get_new_2dmtrx(
			ft_get_new_2dpt(cos(t_fixed_to_double(ray_angle)), sin(t_fixed_to_double(ray_angle))),
			ft_get_new_2dpt(-sin(t_fixed_to_double(ray_angle)), cos(t_fixed_to_double(ray_angle)))
		);
	return (ft_matrix_multiplication(rotation_matrix, vector));
}
