/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:03:29 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/19 22:45:52 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

/**
 * @brief this function casts a ray until it hits a wall
 * 
 * @param game 
 * @param ray_angle the angle the ray forms with the camera plane
 * @return t_raycast_return 
 */
t_raycast_return	raycast(t_game *game, t_2d_point ray)
{
	t_raycast_return	rc_ret;
	t_raycast_data		rc_data;
	t_bool				hit;

	ft_ray_data_init(&rc_data, ray, game);
	// ft_print_raycast_data(rc_data);
	hit = e_false;
	while (e_false == hit)
	{
		ft_walk_through_nhp(&rc_data);
		if (e_WALL == game->\
				map_handle.map[rc_data.cur_sq.y][rc_data.cur_sq.x]
			)
			hit = e_true;
		rc_data.spotted_enemy = spot_enemy(
			&rc_data,
			&rc_data.cur_sq,
			game
		);
	}
	rc_ret_set_data(&rc_data, &rc_ret.wall, &ray, game);
	rc_ret_set_enemy(&rc_data, &rc_ret);
	return (rc_ret);
}
