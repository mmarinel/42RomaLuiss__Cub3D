/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:27:49 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/12 11:38:30 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc_utils.h"

static void	ft_set_hp_dist(
				t_rc_ret_data *rc_ret_data,
				const t_raycast_data *rc_data
				);
static void	ft_set_hp(
				t_rc_ret_data *rc_ret_data,
				const t_raycast_data *rc_data,
				const t_2d_point *pos
				);
//**		end of static declarations

void	rc_ret_set_data(
	t_rc_ret_data *rc_ret_data,
	const t_raycast_data *rc_data,
	const t_2d_point *pos,
	const t_2d_point *ray
	)
{
	ft_set_hp_dist(rc_ret_data, rc_data);
	ft_set_hp(rc_ret_data, rc_data, pos);
	rc_ret_data->side = rc_data->side;
	rc_ret_data->view_side_direction = (rc_data->ray_dir.x >= 0);
	rc_ret_data->view_forw_direction = (rc_data->ray_dir.y >= 0);
	rc_ret_data->door_obstacle = rc_data->door_obstacle;
	rc_ret_data->ray = *ray;
}

static void	ft_set_hp_dist(
			t_rc_ret_data *rc_ret_data,
			const t_raycast_data *rc_data
		)
{
	rc_ret_data->euclidean_dist = euclid_calc(rc_data);
	rc_ret_data->perp_dist = perp_calc(rc_ret_data->euclidean_dist, rc_data);
}

static void	ft_set_hp(
			t_rc_ret_data *rc_ret_data,
			const t_raycast_data *rc_data,
			const t_2d_point *pos
		)
{
	rc_ret_data->hit_point = ft_vec_sum(
			*pos,
			ft_vec_prod(rc_data->ray_dir, rc_ret_data->euclidean_dist)
			);
	rc_ret_data->square.x = rc_data->cur_sq.x;
	rc_ret_data->square.y = rc_data->cur_sq.y;
}
