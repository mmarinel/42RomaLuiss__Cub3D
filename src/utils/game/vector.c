/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 17:50:45 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/13 18:43:12 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

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

t_2d_matrix	ft_get_new_2dmtrx(t_2d_point row_1, t_2d_point row_2)
{
	t_2d_matrix	matrix;

	matrix.row_1 = row_1;
	matrix.row_2 = row_2;
	return (matrix);
}

t_bool	ft_2d_point_equals(
			const t_2d_point *p1,
			const t_2d_point *p2
		)
{
	return (
		flt_round(p1->x, FLT_PRECISION) == flt_round(p2->x, FLT_PRECISION)
		&& flt_round(p1->y, FLT_PRECISION) == flt_round(p2->y, FLT_PRECISION)
	);
}

t_bool	ft_int_2d_point_equals(
			const t_int_2d_point *p1,
			const t_int_2d_point *p2
		)
{
	return (p1->x == p2->x && p1->y == p2->y);
}

void	t_2d_point_print(const t_2d_point *pt, const char *msg)
{
	printf(YELLOW"%s: (x=%lfm y=%lf)\n" RESET, msg, pt->x, pt->y);
}
