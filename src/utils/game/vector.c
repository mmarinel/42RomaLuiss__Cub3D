/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:50:45 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/12 12:06:59 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

t_2d_point	ft_get_new_2dpt(float x, float y)
{
	t_2d_point	pt;

	pt.x = x;
	pt.y = y;
	return (pt);
}

t_2d_matrix	ft_get_new_2dmtrx(t_2d_point row_1, t_2d_point row_2)
{
	t_2d_matrix	matrix;

	matrix.row_1 = row_1;
	matrix.row_2 = row_2;
	return (matrix);
}
