/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_bonus_module.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:36:41 by earendil          #+#    #+#             */
/*   Updated: 2022/12/22 17:36:17 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RC_BONUS_MODULE_H
# define RC_BONUS_MODULE_H

# include "../raycast_types.h"

//*		doors
void	rc_scan_door(
	t_raycast_data *rc_data,
	const t_2d_point *ray,
	t_game *game
	);
t_bool	rc_door_wall_hit(
	const t_int_2d_point *prev_square,
	const t_raycast_data *rc_data,
	t_game *game
	);
void	rc_ret_set_doors(
	const t_raycast_data* rc_data,
	t_raycast_return *rc_ret
	);

//*		enemies
void	rc_scan_enemy(
	t_raycast_data *rc_data,
	t_game *game
	);
void	rc_ret_set_enemy(
	const t_raycast_data* rc_data,
	t_raycast_return *rc_ret
	);

#endif