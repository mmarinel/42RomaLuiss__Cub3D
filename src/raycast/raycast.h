/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:05:17 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/07 11:34:02 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "raycast_types.h"
# include "../game_types.h"

# include "../utils/utils_module.h"
# include "bonus/rc_bon_module.h"
# include "utils/rc_utils_module.h"

# include "../sys_includes.h"

//*		raycast algorithm
t_raycast_return	raycast_algorithm(
	const t_2d_point *pos, const t_2d_point *ray,
	t_rc_handlers rc_handlers,
	t_game *game
	);

float				ft_initial_delta(float p_ax_pos, float p_dir_ax_pos);
int					ft_ray_step_size(float p_dir_ax_pos);

//*		set
void				ft_set_hp_dist(
						t_raycast_return *rc_ret,
						const t_raycast_data *rc_data
					);
void				ft_set_hp(
						t_raycast_return *rc_ret,
						const t_raycast_data *rc_data,
						t_game *game
					);
float				perp_calc(
								float euclidean_dist,
								const t_raycast_data *rc_data
							);
float				euclid_calc(
								const t_raycast_data *rc_data
							);

//*		debug
void				ft_print_raycast_result(t_raycast_return rc_return);
void				ft_print_raycast_data(t_raycast_data rc_data);

#endif