/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:17:27 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 11:34:06 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_init_bonus.h"

static void	load_enemy_textures(t_game *game_ref, t_bool *err_flag);
static void	load_item_textures(t_game *game_ref, t_bool *err_flag);
static void	load_door_textures(t_game *game_ref, t_bool *err_flag);
static void	load_background_textures(t_game *game_ref, t_bool *err_flag);
//*		end	of static declarations

void	load_bonus_textures(t_game *game_ref, t_bool *err_flag)
{
	load_menu_textures(game_ref, err_flag);
	load_background_textures(game_ref, err_flag);
	load_sun_textures(game_ref, err_flag);
	load_door_textures(game_ref, err_flag);
	load_enemy_textures(game_ref, err_flag);
	load_item_textures(game_ref, err_flag);
}

static void	load_enemy_textures(t_game *game_ref, t_bool *err_flag)
{
	open_texture(
		"./img/enemy/kindpng_200x200.xpm",
		&game_ref->textures.enemy[0],
		game_ref, err_flag
		);
	open_texture(
		"./img/enemy/kindpng_dead_200x200.xpm",
		&game_ref->textures.enemy[1],
		game_ref, err_flag
		);
}

static void	load_item_textures(t_game *game_ref, t_bool *err_flag)
{
	open_texture(
		"./img/items/memory-chip-42.xpm",
		&game_ref->textures.item,
		game_ref, err_flag
		);
}

static void	load_door_textures(t_game *game_ref, t_bool *err_flag)
{
	open_texture(
		"./img/door/door_closed.xpm",
		&game_ref->textures.door.closed,
		game_ref, err_flag
		);
	open_texture(
		"./img/door/door_ajar.xpm",
		&game_ref->textures.door.ajar,
		game_ref, err_flag
		);
	open_texture(
		"./img/door/door_opened.xpm",
		&game_ref->textures.door.open,
		game_ref, err_flag
		);
}

static void	load_background_textures(t_game *game_ref, t_bool *err_flag)
{
	open_texture(
		"./img/Background/background.xpm",
		&game_ref->textures.background,
		game_ref, err_flag
		);
}
