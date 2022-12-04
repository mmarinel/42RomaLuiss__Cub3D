/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:27:49 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/04 10:30:24 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static float	perp_calc(
					float euclidean_dist,
					const t_raycast_data *rc_data
				);
static float	euclid_calc(
					const t_raycast_data *rc_data
				);

//*		end of static declarations

void	ft_set_hp_dist(
			t_raycast_return *rc_ret,
			const t_raycast_data *rc_data
		)
{
	rc_ret->euclidean_dist = euclid_calc(rc_data);
	rc_ret->perp_dist = perp_calc(rc_ret->euclidean_dist, rc_data);
}

//*		PERHAPS USELESS !!!!!!!!!!!
void	ft_set_hp(
			t_raycast_return *rc_ret,
			const t_raycast_data *rc_data,
			t_game *game
		)
{
	{
		rc_ret->hit_point.x
			= flt_round(
				game->player_pos.x
				+ (rc_data->ray.x * rc_ret->euclidean_dist),
				FLT_PRECISION
			);
	}
	{
		rc_ret->hit_point.y
			= flt_round(
				game->player_pos.y
				+ (rc_data->ray.y * rc_ret->euclidean_dist),
				FLT_PRECISION
			);
	}
	rc_ret->square.x = rc_data->cur_sq_x;
	rc_ret->square.y = rc_data->cur_sq_y;
}

static float	perp_calc(
					float euclidean_dist,
					const t_raycast_data *rc_data
				)
{
	const float	ray_modulus = ft_vec_norm(rc_data->ray);
	const float	euclid = euclidean_dist;

	// printf(BOLDCYAN"ray_modulus: %lf\n"RESET, ray_modulus);
	// ft_print_2d_point("ray", rc_data->ray);
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

static float	euclid_calc(
					const t_raycast_data *rc_data
				)
{
// 	const float	dist_nhp_through_x
// 		= flt_round(
// 			rc_data->dist_nhp_through_x - rc_data->delta_x,
// 			FLT_PRECISION
// 		);
// 	const float	dist_nhp_through_y
// 		= flt_round(
// 			rc_data->dist_nhp_through_y - rc_data->delta_y,
// 			FLT_PRECISION
// 		);
	const float	dist_nhp_through_x = get_dist_across(rc_data->dist_nhp_through_x, rc_data->delta_x);
	const float	dist_nhp_through_y = get_dist_across(rc_data->dist_nhp_through_y, rc_data->delta_y);

	if (rc_data->side == e_VERTICAL)
		return (dist_nhp_through_x);//(flt_round(dist_nhp_through_x, FLT_PRECISION));
	else
		return (dist_nhp_through_y);//(flt_round(dist_nhp_through_y, FLT_PRECISION));
}
