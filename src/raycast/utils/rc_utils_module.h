/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils_module.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:15:21 by earendil          #+#    #+#             */
/*   Updated: 2022/12/17 14:53:06 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RC_UTILS_MODULE_H
# define RC_UTILS_MODULE_H

# include "../raycast_types.h"

//**		walk
void	ft_walk_through_nhp(t_raycast_data *rc_data);

//*		set
void	rc_set_wall_info(
	t_raycast_data *rc_data,
	t_raycast_return *rc_ret,
	const t_2d_point *ray,
	t_game *game
	);
void	rc_set_background_info(
	t_raycast_data *rc_data,
	t_raycast_return *rc_ret,
	const t_2d_point *ray,
	t_game *game
	);
// void	rc_set_door_info(
// 	t_raycast_data *rc_data,
// 	t_raycast_return *rc_ret,
// 	const t_2d_point *ray,
// 	t_game *game
// 	);

//*		calculations
float	perp_calc(
					float euclidean_dist,
					const t_raycast_data *rc_data
				);
float	euclid_calc(
					const t_raycast_data *rc_data
				);

#endif