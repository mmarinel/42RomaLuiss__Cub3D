/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_bonus_module.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:36:41 by earendil          #+#    #+#             */
/*   Updated: 2022/12/20 00:06:34 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RC_BONUS_MODULE_H
# define RC_BONUS_MODULE_H

# include "../raycast_types.h"

//*		doors
void	add_door(
	t_raycast_data *rc_data,
	const t_2d_point *ray,
	t_game *game
	);

//*		enemies
void			rc_ret_set_enemy(
	const t_raycast_data* rc_data,
	t_raycast_return *rc_ret
	);
t_spotted_enemy	spot_enemy(
			const t_raycast_data *rc_data,
			const t_int_2d_point *pos,
			t_game *game
		);

#endif