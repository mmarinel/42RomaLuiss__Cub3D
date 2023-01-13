/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:55:27 by earendil          #+#    #+#             */
/*   Updated: 2023/01/13 10:45:47 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "in_game_keys.h"

static void		rot_key_pressed(t_key_state *key, t_game *game);
static void		rot_key_released(t_key_state *key, t_game *game);
static float	get_rot_angle(t_key_state *key, t_game *game);
static int		get_west_shift(t_key_state *key);
//*		end of static declarations

void	in_game_rotation_key(t_key_state *key, t_game *game)
{
	if (KeyPress == key->state)
		rot_key_pressed(key, game);
	else if (KeyRelease == key->state)
		rot_key_released(key, game);
}

static void	rot_key_pressed(t_key_state *key, t_game *game)
{
	const float	rot_angle = get_rot_angle(key, game);
	const int	west_shift = get_west_shift(key);

	game->player.west_angle += (west_shift) * game->unit_rot_angle;
	game->player.\
		dir = ft_rotate(game->player.dir, rot_angle);
	game->player.\
		camera_plane = ft_rotate(game->player.camera_plane, rot_angle);
	if (game->unit_rot_angle < MAX_ROT_ANGLE)
		game->unit_rot_angle += ROT_ANGLE_INCREMENT;
}

static void	rot_key_released(t_key_state *key, t_game *game)
{
	game->unit_rot_angle = INITIAL_ROT_ANGLE;
	key->state = -1;
}

static float	get_rot_angle(t_key_state *key, t_game *game)
{
	if (e_LEFT_KEY == key->code)
		return (2 * M_PI - game->unit_rot_angle);
	else
		return (game->unit_rot_angle);
}

static int	get_west_shift(t_key_state *key)
{
	if (e_LEFT_KEY == key->code)
		return (-1);
	else
		return (+1);
}
