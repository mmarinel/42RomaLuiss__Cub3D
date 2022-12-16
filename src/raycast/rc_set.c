/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:27:49 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/16 21:57:32 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	ft_set_hp_dist(
			t_raycast_return *rc_ret,
			const t_raycast_data *rc_data
		)
{
	rc_ret->euclidean_dist = euclid_calc(rc_data);
	rc_ret->perp_dist = perp_calc(rc_ret->euclidean_dist, rc_data);
}

void	ft_set_hp(
			t_raycast_return *rc_ret,
			const t_raycast_data *rc_data,
			t_game *game
		)
{
	rc_ret->hit_point = ft_vec_sum(
		game->player.pos,
		ft_vec_prod(rc_data->ray, rc_ret->euclidean_dist)
	);
	rc_ret->square.x = rc_data->cur_sq.x;
	rc_ret->square.y = rc_data->cur_sq.y;
}

float	perp_calc(
					float euclidean_dist,
					const t_raycast_data *rc_data
				)
{
	const float	ray_modulus = ft_vec_norm(rc_data->ray);
	const float	euclid = euclidean_dist;

	return (
		flt_round(
			((euclid - ray_modulus) / ray_modulus) + 1,
			FLT_PRECISION
		)
	);
}

static float	get_dist_across(float dist_across, float delta_of_axis)
{
	if (dist_across < delta_of_axis)
		return (dist_across);
	else
		return (
			flt_round(
				dist_across - delta_of_axis,
				FLT_PRECISION
			)
		);
}

float	euclid_calc(
					const t_raycast_data *rc_data
				)
{
	const float	dist_nhp_through_x = get_dist_across(
		rc_data->dist_nhp_through_x, rc_data->delta_x
		);
	const float	dist_nhp_through_y = get_dist_across(
		rc_data->dist_nhp_through_y, rc_data->delta_y
		);

	if (rc_data->side == e_VERTICAL)
		return (dist_nhp_through_x);
	else
		return (dist_nhp_through_y);
}
