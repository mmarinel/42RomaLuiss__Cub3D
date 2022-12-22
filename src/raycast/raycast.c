/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:03:29 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/22 18:58:44 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

/**
 * @brief this function provides the additional stopping criteria 
 * for the  raycast_wall function
 * 
 * @param hit_flag the flag indicating whether a wall has been hit until now
 * @return t_bool 
 */
static t_bool			wall_hit(const void *_, const void *hit_flag);
/**
 * @brief this function provides the additional stopping criteria 
 * for the raycast_movements function
 * 
 * @param rc_data 
 * @return t_bool 
 */
static t_bool			collided(const void *rc_data, const void *_);
static t_2d_point	rcmov_endpoint_holder(const t_2d_point *given);
//*		end of static declarations

t_raycast_return	raycast_wall(
	t_game *game, t_2d_point ray
	)
{
	return (raycast(game, ray, wall_hit));
}

t_raycast_return	raycast_movements(
	t_game *game, t_2d_point ray,
	const t_2d_point *end_point
	)
{
	rcmov_endpoint_holder(end_point);
	return (raycast(game, ray, collided));
}

static t_bool	wall_hit(const void *_, const void *hit_flag)
{
	const t_bool	*__hit_flag = (const t_bool *)hit_flag;

	if (_)
	{}
	return (e_true == *__hit_flag);
}

static t_bool	collided(const void *rc_data, const void *_)
{
	const t_raycast_data	*__rc_data = (const t_raycast_data *)rc_data;
	const t_2d_point		endpoint = rcmov_endpoint_holder(NULL);
	const t_int_2d_point	endtile = as_int_2dpt(&endpoint);
	
	if(_)
	{}
	return (
		ft_int_2d_point_equals(&__rc_data->cur_sq, &endtile)
	);
}

static t_2d_point	rcmov_endpoint_holder(const t_2d_point *given)
{
	static t_2d_point	endpoint = (t_2d_point){0.0f, 0.0f};

	if (given)
		endpoint = *given;
	return (endpoint);
}
