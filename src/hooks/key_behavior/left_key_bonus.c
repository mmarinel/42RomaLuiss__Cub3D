/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_key_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:55:27 by earendil          #+#    #+#             */
/*   Updated: 2022/12/21 18:05:16 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys_behavior.h"

void	left_key_handler_pressed(t_game *game)
{
	game->player.west_angle -= game->unit_rot_angle;
	game->player.dir = ft_rotate(
		game->player.dir, 2 * M_PI - game->unit_rot_angle
	);
	game->player.camera_plane = ft_rotate(
		game->player.camera_plane, 2 * M_PI -  game->unit_rot_angle
	);
	if (game->unit_rot_angle < MAX_ROT_ANGLE)
		game->unit_rot_angle += ROT_ANGLE_INCREMENT;
}

void	left_key_handler_released(t_game *game)
{
	game->unit_rot_angle = INITIAL_ROT_ANGLE;
	game->keys[LEFT_INDEX].state = -1;
}
