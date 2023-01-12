/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:52:45 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 11:47:36 by mmarinel         ###   ########.fr       */
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
static void	rc_process_bonus(
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
 * @param pos the position from where to start the raycast
 * @param ray the ray spawning from the position 
 * @param rc_handlers pointers to test and init functions
 * @param game 
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
		&& e_false == rc_handlers.rc_stop(&rc_data, &hit)
		&& (e_false == (BONUS && e_true == rc_data.door_obstacle)))
	{
		rc_data.prev_sq = rc_data.cur_sq;
		ft_walk_through_nhp(&rc_data);
		if (e_WALL == game->map_handle.\
				map[rc_data.cur_sq.y][rc_data.cur_sq.x]
			)
			hit = e_true;
		else
			rc_process_bonus(&rc_data, pos, ray, game);
	}
	rc_ret_set_data(&rc_data, &rc_ret.final_tile, pos, ray);
	rc_set_bonus(&rc_data, &rc_ret);
	return (rc_ret);
}

static void	rc_process_bonus(
	t_raycast_data *rc_data,
	const t_2d_point *pos, const t_2d_point *ray,
	t_game *game
	)
{
	if (BONUS)
	{
		if (rc_data->process_bonus_doors)
			rc_scan_door(rc_data, pos, ray, game);
		if (e_false == rc_data->door_obstacle)
		{
			if (rc_data->process_bonus_enemies)
				rc_scan_enemy(rc_data, game);
			if (rc_data->process_bonus_items)
				rc_scan_item(rc_data, game);
		}
	}
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
		if (rc_data->process_bonus_items)
			rc_ret_set_item(rc_data, rc_ret);
	}
	else
	{
		rc_ret->doors = NULL;
	}
}
