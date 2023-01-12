/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_sun_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:53:19 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 13:29:04 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

//*		(FOV):(screen_width)	=	(west_ax_angle):(shift)
//*
//*		shift = (west_ax_angle / FOV) * (screen_width)
int	west_axis_angle_to_px_shift(t_game *g)
{
	float	west_axis_angle;
	int		sign;

	if (g->player.west_angle < FOV)
	{
		west_axis_angle = g->player.west_angle;
		sign = -1;
	}
	else
	{
		west_axis_angle = 2 * M_PI - g->player.west_angle;
		sign = +1;
	}
	return (
		sign * roundf((west_axis_angle / FOV) * g->screen_handle.width)
	);
}

//*		rows / 2 = distance from west middle point (columns -1, rows / 2)
//*		when player is at position (x, 0)
//*
//*		This proportion gives the current wanted shift
//*		(
//*			WE WANT the sun to be shifted half the width of the screen
//*			when we look it from position (x, 0) with x any
//*		)
//*
//*		(rows / 2):(screen_width / 2)	=	(dist):(shift)
//*
//*		shift = dist * (screen_width / rows)
int	west_middle_point_dist_to_px_shift(t_game *g)
{
	const float	west_middle_pt_distance
		= g->map_handle.rows / 2.0f - g->player.pos.y;

	return (
		roundf(
			west_middle_pt_distance * (
				(float)g->screen_handle.width / g->map_handle.rows
			)
		)
	);
}
