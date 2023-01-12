/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:03:29 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/12 11:44:00 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

/**
 * @brief this function provides the stopping criteria 
 * for the raycast function
 * 
 * @param rc_data structure holding all relevant data
 * to be processed by the raycast algorithm (raycast_algorithm.c)
 * @param _ unused. Present only for compatibility reasons
 * @return t_bool 
 */
static t_bool			rc_tile_reached(const void *rc_data, const void *_);
/**
 * @brief this function provides the initialization criteria
 * for the raycast function.
 * All initialization functions must act as "decorators"
 * for the [ft_ray_data_init] function (.../utils/)
 * 
 * @param rc_data 
 * @param pos 
 * @param ray 
 */
static void				rc_init(
							void *rc_data, const void *pos, const void *ray
							);
static t_int_2d_point	rc_endpoint_holder(const t_int_2d_point *given);
//*		end of static declarations

/**
 * @brief this function performs the raycast algorithm on a given position
 * and with the additional task of checking if a particular tile
 * has been reached other than a wall.
 * 
 * @param game 
 * @param pos the position from where to execute the raycast.
 * @param ray the ray spawning from the position
 * @param tile 
 * @return t_raycast_return 
 */
t_raycast_return	raycast(
	t_game *game,
	t_2d_point pos, t_2d_point ray,
	t_int_2d_point tile
	)
{
	const t_rc_handlers	rc_handlers = (t_rc_handlers){
		rc_tile_reached, rc_init
	};

	rc_endpoint_holder(&tile);
	return (raycast_algorithm(&pos, &ray, rc_handlers, game));
}

static void	rc_init(void *rc_data, const void *pos, const void *ray)
{
	t_raycast_data *const	__rc_data = (t_raycast_data *)rc_data;
	const t_2d_point		*__pos = (const t_2d_point *)pos;
	const t_2d_point		*__ray = (const t_2d_point *)ray;

	ft_ray_data_init(__rc_data, __pos, __ray);
	__rc_data->process_bonus_doors = e_true;
	__rc_data->process_bonus_enemies = e_false;
	__rc_data->process_bonus_items = e_false;
}

static t_bool	rc_tile_reached(const void *rc_data, const void *_)
{
	const t_raycast_data	*__rc_data = (const t_raycast_data *)rc_data;
	const t_int_2d_point	endtile = rc_endpoint_holder(NULL);

	if (_)
	{
	}
	return (
		ft_int_2d_point_equals(&__rc_data->cur_sq, &endtile)
	);
}

static t_int_2d_point	rc_endpoint_holder(const t_int_2d_point *given)
{
	static t_int_2d_point	endpoint = (t_int_2d_point){0.0f, 0.0f};

	if (given)
		endpoint = *given;
	return (endpoint);
}
