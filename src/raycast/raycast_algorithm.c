/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_algorithm.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:52:45 by earendil          #+#    #+#             */
/*   Updated: 2022/12/22 19:17:33 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void	rc_process_bonus(
	t_raycast_data *rc_data,
	const t_2d_point *ray, t_bool *hit_flag,
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
t_raycast_return	raycast(
	t_game *game, t_2d_point ray,
	t_bool(*test_f)(const void *, const void *)
	)
{
	t_raycast_return	rc_ret;
	t_raycast_data		rc_data;
	t_bool				hit;

	ft_ray_data_init(&rc_data, ray, game);
	hit = e_false;
	while (e_false == hit && e_false == (*test_f)(&rc_data, &hit))
	{
		rc_data.prev_sq = rc_data.cur_sq;
		ft_walk_through_nhp(&rc_data);
		if (e_WALL == game->\
				map_handle.map[rc_data.cur_sq.y][rc_data.cur_sq.x]
			)
			hit = e_true;
		else
			rc_process_bonus(&rc_data, &ray, &hit, game);
	}
	rc_ret_set_data(&rc_data, &rc_ret.wall, &ray, game);
	rc_set_bonus(&rc_data, &rc_ret);
	return (rc_ret);
}

static void	rc_process_bonus(
	t_raycast_data *rc_data,
	const t_2d_point *ray, t_bool *hit_flag,
	t_game *game
	)
{
	if (BONUS)
	{
		*hit_flag = rc_door_wall_hit(&rc_data->prev_sq, rc_data, game);
		rc_scan_door(rc_data, ray, game);
		rc_scan_enemy(rc_data, game);
	}
}

static void	rc_set_bonus(
	const t_raycast_data *rc_data, t_raycast_return *rc_ret
	)
{
	if (BONUS)
	{
		rc_ret_set_enemy(rc_data, rc_ret);
		rc_ret_set_doors(rc_data, rc_ret);
	}
}
