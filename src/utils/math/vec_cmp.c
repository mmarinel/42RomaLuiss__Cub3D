/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:51:51 by earendil          #+#    #+#             */
/*   Updated: 2022/12/16 22:52:06 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uti_math.h"

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
