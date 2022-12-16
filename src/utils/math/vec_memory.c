/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:49:38 by earendil          #+#    #+#             */
/*   Updated: 2022/12/16 22:49:56 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uti_math.h"

t_int_2d_point	ft_get_new_int_2dpt(int x, int y)
{
	t_int_2d_point	pt;

	pt.x = x;
	pt.y = y;
	return (pt);
}

t_2d_point	ft_get_new_2dpt(float x, float y)
{
	t_2d_point	pt;

	pt.x = x;
	pt.y = y;
	return (pt);
}

t_int_2d_point	as_int_2dpt(const t_2d_point *pt)
{
	t_int_2d_point	__pt;

	__pt.x = floor(pt->x);
	__pt.y = floor(pt->y);
	return (__pt);
}

t_2d_matrix	ft_get_new_2dmtrx(t_2d_point row_1, t_2d_point row_2)
{
	t_2d_matrix	matrix;

	matrix.row_1 = row_1;
	matrix.row_2 = row_2;
	return (matrix);
}
