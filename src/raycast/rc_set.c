/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:27:49 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/12 18:28:15 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	ft_set_hp_dist(t_raycast_return *rc_ret,
			t_raycast_data rc_data,
			float ray_angle
		)
{
	const float	dist_nhp_through_x = flt_round(rc_data.dist_nhp_through_x - rc_data.delta_x, 6);
	const float	dist_nhp_through_y = flt_round(rc_data.dist_nhp_through_y - rc_data.delta_y, 6);

	if (rc_data.side == e_VERTICAL)
		rc_ret->euclidean_dist = flt_round(dist_nhp_through_x, 6);
	else
		rc_ret->euclidean_dist = flt_round(dist_nhp_through_y, 6);
	rc_ret->perp_dist = flt_round(rc_ret->euclidean_dist * sin(ray_angle), 6);
}

void	ft_set_hp(t_raycast_return *raycast_info, t_raycast_data rc_data,
			t_game *game)
{
	{
		raycast_info->hit_point.x
			= flt_round(
				game->player_pos.x
				+ (rc_data.ray_dir.x * raycast_info->euclidean_dist),
				4
			);
	}
	{
		raycast_info->hit_point.y
			= flt_round(
				game->player_pos.y
				+ (rc_data.ray_dir.y * raycast_info->euclidean_dist),
				4
			);
	}
	raycast_info->square.x = rc_data.cur_sq_x;
	raycast_info->square.y = rc_data.cur_sq_y;
}
