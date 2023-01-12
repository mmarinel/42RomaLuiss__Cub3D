/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_calc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:15:49 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 11:07:53 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc_utils.h"

static float	get_dist_across(float dist_across, float delta_of_axis);
//**		end of static declarations

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
