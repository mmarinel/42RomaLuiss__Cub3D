/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres_endpoints.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:13:32 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/12 16:15:00 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_drawing.h"

//*		we map horizontal and vertical lines as negative slope lines
int	get_angular_coefficient_sign(int delta_x, int delta_y,
		const size_t norm_delta_x, const size_t norm_delta_y)
{
	if (0 == norm_delta_x || 0 == norm_delta_y)
		return (0);
	else
		return (
			(delta_x / norm_delta_x) * (delta_y / norm_delta_y)
		);
}

//*		Mapping horizontal lines as negative ones lines
//*			has no effect;
//*		Mapping vertical lines as negative ones
//*			has the effect to order points the reverse way.
void	bres_order_pts(t_int_2d_point endpoints[2])
{
	t_int_2d_point	backup;

	if (endpoints[0].x > endpoints[1].x)
	{
		backup = endpoints[0];
		endpoints[0] = endpoints[1];
		endpoints[1] = backup;
	}
	else if (endpoints[0].x == endpoints[1].x)
	{
		if (endpoints[0].y <= endpoints[1].y)
		{
			backup = endpoints[0];
			endpoints[0] = endpoints[1];
			endpoints[1] = backup;
		}
	}
}
