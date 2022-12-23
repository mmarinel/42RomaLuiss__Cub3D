/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_behavior.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:24:17 by earendil          #+#    #+#             */
/*   Updated: 2022/12/23 13:56:07 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_BEHAVIOR_H
# define KEYS_BEHAVIOR_H

# include "../hooks.h"

# include "../../utils/utils_module.h"

# include "../../sys_includes.h"

//*		player
t_2d_point			new_player_pos(
	t_key key_pressed, t_game *game
	);
void				move_across_door(
	t_game *game, t_2d_point *guessed, t_key keycode
	);

#endif