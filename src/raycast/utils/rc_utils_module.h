/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils_module.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:15:21 by earendil          #+#    #+#             */
/*   Updated: 2022/12/19 23:58:20 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RC_UTILS_MODULE_H
# define RC_UTILS_MODULE_H

# include "../raycast_types.h"

//**		walk
void	ft_walk_through_nhp(t_raycast_data *rc_data);

//*		initialize
void	ft_ray_data_init(t_raycast_data *rc_data,
			t_2d_point ray, t_game *game
	);

//*		set
void	rc_ret_set_data(
	const t_raycast_data *rc_data,
	t_rc_ret_data *rc_ret_data,
	const t_2d_point *ray,
	t_game *game
	);

//*		calculations
float	perp_calc(
					float euclidean_dist,
					const t_raycast_data *rc_data
				);
float	euclid_calc(
					const t_raycast_data *rc_data
				);

//*		debug
void	ft_print_raycast_result(t_raycast_return raycast_info);
void	ft_print_raycast_data(t_raycast_data rc_data);

#endif