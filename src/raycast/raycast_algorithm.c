/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:52:45 by earendil          #+#    #+#             */
/*   Updated: 2022/12/23 23:03:43 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

/**
 * @brief 
 * 
 * @param rc_data 
 * @param pos 
 * @param ray 
 * @param game 
 * @return t_bool true iff the wall-side of a door has been hit
 */
static t_bool	rc_process_bonus(
	t_raycast_data *rc_data,
	const t_2d_point *pos, const t_2d_point *ray,
	t_game *game
	);
static void	rc_set_bonus(
	const t_raycast_data *rc_data, t_raycast_return *rc_ret
	);
//*		end of static declarations

/**
 * @brief this function casts a ray until it hits a wall
 * or provided test function gives true
 * 
 * @param game 
 * @param ray_angle the angle the casted ray forms with the camera plane
 * @param test_f the additional stopping criteria for the raycast
 * @return t_raycast_return 
 */
t_raycast_return	raycast_algorithm(
	const t_2d_point *pos, const t_2d_point *ray,
	t_rc_handlers rc_handlers,
	t_game *game
	)
{
	t_raycast_return	rc_ret;
	t_raycast_data		rc_data;
	t_bool				hit;

	rc_handlers.rc_init(&rc_data, pos, ray);
	hit = e_false;
	while (e_false == hit
		&& e_false == rc_handlers.rc_stop(&rc_data, &hit))
	{
		rc_data.prev_sq = rc_data.cur_sq;
		ft_walk_through_nhp(&rc_data);
		if (e_WALL == game->map_handle\
				.map[rc_data.cur_sq.y][rc_data.cur_sq.x]
			)
			hit = e_true;
		else
			hit = rc_process_bonus(&rc_data, pos, ray, game);
	}
	rc_ret_set_data(&rc_data, &rc_ret.wall, pos, ray);
	rc_set_bonus(&rc_data, &rc_ret);
	return (rc_ret);
}

static t_bool	rc_process_bonus(
	t_raycast_data *rc_data,
	const t_2d_point *pos, const t_2d_point *ray,
	t_game *game
	)
{
	t_bool	hit;

	hit = e_false;
	if (BONUS)
	{
		if (rc_data->process_bonus_doors)
			hit = rc_scan_door(rc_data, pos, ray, game);
		if (rc_data->process_bonus_enemies)
			rc_scan_enemy(rc_data, game);
	}
	return (hit);
}

static void	rc_set_bonus(
	const t_raycast_data *rc_data, t_raycast_return *rc_ret
	)
{
	if (BONUS)
	{
		if (rc_data->process_bonus_enemies)
			rc_ret_set_enemy(rc_data, rc_ret);
		if (rc_data->process_bonus_doors)
			rc_ret_set_doors(rc_data, rc_ret);
	}
}
