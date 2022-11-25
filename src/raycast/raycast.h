/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:05:17 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/25 12:34:43 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_H
# define RAYCAST_H

# include "raycast_types.h"
# include "../utils/utils_module.h"

# include <math.h>
# include <stdio.h>

//*		initialization
t_raycast_data	ft_ray_data_init(t_game *game, t_2d_point ray_dir);
float			ft_initial_delta(float p_ax_pos, float p_dir_ax_pos);
int				ft_ray_step_size(float p_dir_ax_pos);

//*		set
void			ft_set_hp_dist(
					t_raycast_return *rc_ret,
					const t_raycast_data *rc_data,
					t_game *g
				);
void			ft_set_hp(
					t_raycast_return *rc_ret,
					const t_raycast_data *rc_data,
					t_game *game
				);

//*		debug
void	ft_print_raycast_result(t_raycast_return rc_return);
void	ft_print_raycast_data(t_raycast_data rc_data);

#endif