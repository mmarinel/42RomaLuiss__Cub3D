/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_module.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:05:17 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/12 11:49:23 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_MODULE_H
# define RAYCAST_MODULE_H

# include "../includes/game_types.h"
# include "../utils/math/uti_math_types.h"

//*		raycast
t_raycast_return	raycast_wall(
						t_game *game, t_2d_point ray
						);
t_raycast_return	raycast_movement(
						const t_2d_point *old_pos, const t_2d_point *end_point,
						t_game *game
						);
t_raycast_return	raycast(
						t_game *game,
						t_2d_point pos, t_2d_point ray,
						t_int_2d_point tile
						);

//*		memory
void				raycast_clean(t_raycast_return *rc_ret);

#endif