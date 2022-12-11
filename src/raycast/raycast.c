/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:03:29 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/11 12:53:49 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void				ft_walk_through_nhp(t_raycast_data *raycast_data);
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
	t_raycast_return	ret;
	t_raycast_data		raycast_data;
	t_bool				hit;

	ft_ray_data_init(&raycast_data, ray, game);
	// ft_print_raycast_data(raycast_data);
	hit = e_false;
	while (e_false == hit)
	{
		ft_walk_through_nhp(&raycast_data);
		if (e_WALL == game->\
				map_handle.map[raycast_data.cur_sq_y][raycast_data.cur_sq_x]
			)
			hit = e_true;
	}
	ft_set_hp_dist(&ret, &raycast_data);
	ft_set_hp(&ret, &raycast_data, game);
	ret.side = raycast_data.side;
	ret.view_side_direction = (raycast_data.ray_dir.x >= 0);
	ret.view_forw_direction = (raycast_data.ray_dir.y >= 0);
	ret.ray = ray;
	return (ret);
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
		rc_data->cur_sq_x = rc_data->cur_sq_x + rc_data->step_x;
		rc_data->dist_nhp_through_x += rc_data->delta_x;
		rc_data->side = e_VERTICAL;
	}
	else if (rc_data->dist_nhp_through_x == rc_data->dist_nhp_through_y)
	{
		if (e_VERTICAL == rc_data->side)
		{
			// printf(BOLDCYAN "45 VERTICAL\n" RESET);
			rc_data->cur_sq_y = rc_data->cur_sq_y + rc_data->step_y;
			rc_data->dist_nhp_through_y += rc_data->delta_y;
			rc_data->side = e_HORIZONTAL;
		}
		if (e_HORIZONTAL == rc_data->side)
		{
			// printf(BOLDCYAN "45 HORIZONTAL\n" RESET);
			rc_data->cur_sq_x = rc_data->cur_sq_x + rc_data->step_x;
			rc_data->dist_nhp_through_x += rc_data->delta_x;
			rc_data->side = e_VERTICAL;
		}
	}
	else
	{
		rc_data->cur_sq_y = rc_data->cur_sq_y + rc_data->step_y;
		rc_data->dist_nhp_through_y += rc_data->delta_y;
		rc_data->side = e_HORIZONTAL;
	}
	// ft_print_raycast_data(*rc_data);
}
