/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:50:45 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/12 11:46:42 by mmarinel         ###   ########.fr       */
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

t_2d_matrix	ft_get_new_2dmtrx(t_2d_point col_1, t_2d_point col_2)
{
	t_2d_matrix	matrix;

	matrix.col_1 = col_1;
	matrix.col_2 = col_2;
	return (matrix);
}
