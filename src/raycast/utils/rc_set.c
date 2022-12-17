/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:27:49 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/17 14:31:14 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc_utils.h"

static void	ft_set_hp_dist(
			t_raycast_return *rc_ret,
			const t_raycast_data *rc_data
		);
static void	ft_set_hp(
			t_raycast_return *rc_ret,
			const t_raycast_data *rc_data,
			t_game *game
		);
//**		end of static declarations

void	rc_set_wall_info(
	t_raycast_data *rc_data,
	t_raycast_return *rc_ret,
	const t_2d_point *ray,
	t_game *game
	)
{
	ft_set_hp_dist(rc_ret, rc_data);
	ft_set_hp(rc_ret, rc_data, game);
	rc_ret->wall.side = rc_data->side;
	rc_ret->wall.view_side_direction = (rc_data->ray_dir.x >= 0);
	rc_ret->wall.view_forw_direction = (rc_data->ray_dir.y >= 0);
	rc_ret->wall.ray = *ray;
	rc_ret->spotted_enemy = rc_data->spotted_enemy;
}

static void	ft_set_hp_dist(
			t_raycast_return *rc_ret,
			const t_raycast_data *rc_data
		)
{
	rc_ret->wall.euclidean_dist = euclid_calc(rc_data);
	rc_ret->wall.perp_dist = perp_calc(rc_ret->wall.euclidean_dist, rc_data);
}

static void	ft_set_hp(
			t_raycast_return *rc_ret,
			const t_raycast_data *rc_data,
			t_game *game
		)
{
	rc_ret->wall.hit_point = ft_vec_sum(
		game->player.pos,
		ft_vec_prod(rc_data->ray, rc_ret->wall.euclidean_dist)
	);
	rc_ret->wall.square.x = rc_data->cur_sq.x;
	rc_ret->wall.square.y = rc_data->cur_sq.y;
}
