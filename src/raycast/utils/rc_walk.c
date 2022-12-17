/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_walk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:41:11 by earendil          #+#    #+#             */
/*   Updated: 2022/12/17 14:52:29 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc_utils.h"

static void	walk_through_x(t_raycast_data *rc_data);
static void	walk_through_y(t_raycast_data *rc_data);
//**		end of static declarations

/**
 * @brief this function walks from one hit point to the next one;
 * setting the current square coordinates with respect to the current hit point
 * and updating the hit point with the next one
 * 
 * @param rc_data 
 */
void	ft_walk_through_nhp(t_raycast_data *rc_data)
{
	if (rc_data->dist_nhp_through_x < rc_data->dist_nhp_through_y)
		walk_through_x(rc_data);
	else if (rc_data->dist_nhp_through_x == rc_data->dist_nhp_through_y)
	{
		if (e_VERTICAL == rc_data->side)
			walk_through_y(rc_data);
		else if (e_HORIZONTAL == rc_data->side)
			walk_through_x(rc_data);
		else
			walk_through_y(rc_data);
	}
	else
		walk_through_y(rc_data);
}

static void	walk_through_x(t_raycast_data *rc_data)
{
	rc_data->cur_sq.x = rc_data->cur_sq.x + rc_data->step_x;
	rc_data->dist_nhp_through_x += rc_data->delta_x;
	rc_data->side = e_VERTICAL;
}

static void	walk_through_y(t_raycast_data *rc_data)
{
	rc_data->cur_sq.y = rc_data->cur_sq.y + rc_data->step_y;
	rc_data->dist_nhp_through_y += rc_data->delta_y;
	rc_data->side = e_HORIZONTAL;
}
