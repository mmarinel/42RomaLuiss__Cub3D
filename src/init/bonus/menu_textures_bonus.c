/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:02:41 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 11:15:31 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_init_bonus.h"

static void	load_initial_menu(t_game *game_ref, t_bool *err_flag);
static void	load_game_over_menu(t_game *game_ref, t_bool *err_flag);
static void	load_game_win_menu(t_game *game_ref, t_bool *err_flag);
//*		end of static declarations

void	load_menu_textures(t_game *game_ref, t_bool *err_flag)
{
	load_initial_menu(game_ref, err_flag);
	load_game_over_menu(game_ref, err_flag);
	load_game_win_menu(game_ref, err_flag);
}

static void	load_initial_menu(t_game *game_ref, t_bool *err_flag)
{
	open_texture(
		"./img/menus/menu_initial_newg.xpm",
		&game_ref->textures.menu[MENU_NEWG],
		game_ref, err_flag
		);
	open_texture(
		"./img/menus/menu_initial_exit.xpm",
		&game_ref->textures.menu[MENU_EXIT],
		game_ref, err_flag
		);
}

static void	load_game_over_menu(t_game *game_ref, t_bool *err_flag)
{
	open_texture(
		"./img/menus/game_over_newg.xpm",
		&game_ref->textures.game_over[MENU_NEWG],
		game_ref, err_flag
		);
	open_texture(
		"./img/menus/game_over_exit.xpm",
		&game_ref->textures.game_over[MENU_EXIT],
		game_ref, err_flag
		);
}

static void	load_game_win_menu(t_game *game_ref, t_bool *err_flag)
{
	open_texture(
		"./img/menus/game_win_newg.xpm",
		&game_ref->textures.game_win[MENU_NEWG],
		game_ref, err_flag
		);
	open_texture(
		"./img/menus/game_win_exit.xpm",
		&game_ref->textures.game_win[MENU_EXIT],
		game_ref, err_flag
		);
}
