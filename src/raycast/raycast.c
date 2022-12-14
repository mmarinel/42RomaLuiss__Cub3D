/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:03:29 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/14 13:08:26 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void	ft_walk_through_nhp(t_raycast_data *rc_data);
t_enemy		*spot_enemy(
				const t_raycast_data *rc_data,
				const t_int_2d_point *pos,
				t_game *game
			);
//*		enf of static declarations

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
	ft_set_hp_dist(&rc_ret, &rc_data);
	ft_set_hp(&rc_ret, &rc_data, game);
	rc_ret.side = rc_data.side;
	rc_ret.view_side_direction = (rc_data.ray_dir.x >= 0);
	rc_ret.view_forw_direction = (rc_data.ray_dir.y >= 0);
	rc_ret.ray = ray;
	rc_ret.spotted_enemy = rc_data.spotted_enemy;
	return (rc_ret);
}

/**
 * @brief this function walks from one hit point to the next one;
 * setting the current square coordinates with respect to the current hit point
 * and updating the hit point with the next one
 * 
 * @param rc_data 
 */
static void	ft_walk_through_nhp(t_raycast_data *rc_data)
{
	// printf(GREEN "iter\n" RESET);
	// ft_print_raycast_data(*rc_data);
	if (rc_data->dist_nhp_through_x < rc_data->dist_nhp_through_y)
	{
		rc_data->cur_sq.x = rc_data->cur_sq.x + rc_data->step_x;
		rc_data->dist_nhp_through_x += rc_data->delta_x;
		rc_data->side = e_VERTICAL;
	}
	else if (rc_data->dist_nhp_through_x == rc_data->dist_nhp_through_y)
	{
		if (e_VERTICAL == rc_data->side)
		{
			// printf(BOLDCYAN "45 VERTICAL\n" RESET);
			rc_data->cur_sq.y = rc_data->cur_sq.y + rc_data->step_y;
			rc_data->dist_nhp_through_y += rc_data->delta_y;
			rc_data->side = e_HORIZONTAL;
		}
		if (e_HORIZONTAL == rc_data->side)
		{
			// printf(BOLDCYAN "45 HORIZONTAL\n" RESET);
			rc_data->cur_sq.x = rc_data->cur_sq.x + rc_data->step_x;
			rc_data->dist_nhp_through_x += rc_data->delta_x;
			rc_data->side = e_VERTICAL;
		}
	}
	else
	{
		rc_data->cur_sq.y = rc_data->cur_sq.y + rc_data->step_y;
		rc_data->dist_nhp_through_y += rc_data->delta_y;
		rc_data->side = e_HORIZONTAL;
	}
	// ft_print_raycast_data(*rc_data);
}

t_enemy	*spot_enemy(
			const t_raycast_data *rc_data,
			const t_int_2d_point *pos,
			t_game *game
		)
{
	if (rc_data->spotted_enemy)
		return (rc_data->spotted_enemy);
	else
		return (get_enemy(pos, game));
}
