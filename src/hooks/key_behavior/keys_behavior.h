/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_behavior.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:24:17 by earendil          #+#    #+#             */
/*   Updated: 2022/12/21 18:01:42 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_BEHAVIOR_H
# define KEYS_BEHAVIOR_H

# include "../hooks.h"

# include "../../utils/utils_module.h"

# include "../../sys_includes.h"

//*		player
int			new_player_pos_direction(
	int key_pressed
	);
t_2d_point	new_player_pos(
	int key_pressed, t_game *game
	);
void		move_across_door(
	t_game *game, t_2d_point *guessed, t_key keycode
	);

#endif