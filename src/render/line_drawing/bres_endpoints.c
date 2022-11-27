/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres_endpoints.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 15:42:52 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/23 16:04:29 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_drawing.h"

int	get_angular_coefficient_sign(int delta_x, int delta_y,
		const size_t norm_delta_x, const size_t norm_delta_y)
{
	if (0 == norm_delta_x || 0 == norm_delta_y)//*		we map horizontal and vertical lines as negative slope lines
		return (0);
	else
		return ((delta_x/norm_delta_x) * (delta_y/norm_delta_y));
}

//*		Mapping horizontal lines as negative lines has no effect;
//*		Mapping vertical lines as negative has the effect to order points the reverse way.
void	bres_order_pts(t_int_2d_point v_1, t_int_2d_point v_2,
			t_int_2d_point *vfirst, t_int_2d_point *vlast)
{
	if (v_1.x < v_2.x)
	{
		*vfirst = v_1;
		*vlast = v_2;
	}
	else if (v_1.x > v_2.x)
	{
		*vfirst = v_2;
		*vlast = v_1;
	}
	else
	{
		if (v_1.y > v_2.y)
		{
			*vfirst = v_1;
			*vlast = v_2;
		}
		else
		{
			*vfirst = v_2;
			*vlast = v_1;
		}
	}
}