/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_module.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:05:17 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/23 23:14:50 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_MODULE_H
# define RAYCAST_MODULE_H

// # include "raycast_types.h"
# include "../game_types.h"
# include "../utils/math/uti_math_types.h"

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

//*		debug
void				ft_print_raycast_result(t_raycast_return raycast_info);

#endif