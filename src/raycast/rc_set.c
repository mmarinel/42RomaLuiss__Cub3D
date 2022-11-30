/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:27:49 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/30 12:43:14 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static float	perp_calc(
					const t_raycast_return *rc_ret,
					const t_raycast_data *rc_data,
					t_game *g
				);
//*		end of static declarations

void	ft_set_hp_dist(
			t_raycast_return *rc_ret,
			const t_raycast_data *rc_data,
			t_game *g
		)
{
	const float	dist_nhp_through_x
		= flt_round(
			rc_data->dist_nhp_through_x - rc_data->delta_x,
			FLT_PRECISION
		);
	const float	dist_nhp_through_y
		= flt_round(
			rc_data->dist_nhp_through_y - rc_data->delta_y,
			FLT_PRECISION
		);

	if (rc_data->side == e_VERTICAL)
		rc_ret->euclidean_dist = flt_round(dist_nhp_through_x, FLT_PRECISION);
	else
		rc_ret->euclidean_dist = flt_round(dist_nhp_through_y, FLT_PRECISION);
	rc_ret->perp_dist = flt_round(
		perp_calc(rc_ret, rc_data, g),
		FLT_PRECISION
	);
	rc_ret->side = rc_data->side;
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
				+ (rc_data->ray_dir.x * rc_ret->euclidean_dist),
				4
			);
	}
	{
		rc_ret->hit_point.y
			= flt_round(
				game->player_pos.y
				+ (rc_data->ray_dir.y * rc_ret->euclidean_dist),
				4
			);
	}
	rc_ret->square.x = rc_data->cur_sq_x;
	rc_ret->square.y = rc_data->cur_sq_y;
}

static float	perp_calc(
					const t_raycast_return *rc_ret,
					const t_raycast_data *rc_data,
					t_game *g
				)
{
	const float	pdir_modulus = ft_vec_norm(g->player_dir);
	const float	rdir_modulus = ft_vec_norm(rc_data->ray_dir);
	const float	euclid = rc_ret->euclidean_dist;

	return (
		flt_round(
			pdir_modulus * (((euclid - rdir_modulus) / rdir_modulus) + 1),
			FLT_PRECISION
		)
	);
}
