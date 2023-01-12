/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sun_textures_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:54:50 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 11:32:52 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_init_bonus.h"

static void	load_first_batch(t_game *game_ref, t_bool *err_flag);
static void	load_second_batch(t_game *game_ref, t_bool *err_flag);
static void	load_third_batch(t_game *game_ref, t_bool *err_flag);
static void	load_fourth_batch(t_game *game_ref, t_bool *err_flag);
//*		end of static declarations

void	load_sun_textures(t_game *game_ref, t_bool *err_flag)
{
	load_first_batch(game_ref, err_flag);
	load_second_batch(game_ref, err_flag);
	load_third_batch(game_ref, err_flag);
	load_fourth_batch(game_ref, err_flag);
}

static void	load_first_batch(t_game *game_ref, t_bool *err_flag)
{
	open_texture(
		"./img/Sun/frame-1.xpm",
		&game_ref->textures.sun[0],
		game_ref, err_flag
		);
	open_texture(
		"./img/Sun/frame-2.xpm",
		&game_ref->textures.sun[1],
		game_ref, err_flag
		);
	open_texture(
		"./img/Sun/frame-3.xpm",
		&game_ref->textures.sun[2],
		game_ref, err_flag
		);
	open_texture(
		"./img/Sun/frame-4.xpm",
		&game_ref->textures.sun[3],
		game_ref, err_flag
		);
	open_texture(
		"./img/Sun/frame-5.xpm",
		&game_ref->textures.sun[4],
		game_ref, err_flag
		);
}

static void	load_second_batch(t_game *game_ref, t_bool *err_flag)
{
	open_texture(
		"./img/Sun/frame-6.xpm",
		&game_ref->textures.sun[5],
		game_ref, err_flag
		);
	open_texture(
		"./img/Sun/frame-7.xpm",
		&game_ref->textures.sun[6],
		game_ref, err_flag
		);
	open_texture(
		"./img/Sun/frame-8.xpm",
		&game_ref->textures.sun[7],
		game_ref, err_flag
		);
	open_texture(
		"./img/Sun/frame-9.xpm",
		&game_ref->textures.sun[8],
		game_ref, err_flag
		);
	open_texture(
		"./img/Sun/frame-10.xpm",
		&game_ref->textures.sun[9],
		game_ref, err_flag
		);
}

static void	load_third_batch(t_game *game_ref, t_bool *err_flag)
{
	open_texture(
		"./img/Sun/frame-11.xpm",
		&game_ref->textures.sun[10],
		game_ref, err_flag
		);
	open_texture(
		"./img/Sun/frame-12.xpm",
		&game_ref->textures.sun[11],
		game_ref, err_flag
		);
	open_texture(
		"./img/Sun/frame-13.xpm",
		&game_ref->textures.sun[12],
		game_ref, err_flag
		);
	open_texture(
		"./img/Sun/frame-14.xpm",
		&game_ref->textures.sun[13],
		game_ref, err_flag
		);
	open_texture(
		"./img/Sun/frame-15.xpm",
		&game_ref->textures.sun[14],
		game_ref, err_flag
		);
}

static void	load_fourth_batch(t_game *game_ref, t_bool *err_flag)
{
	open_texture(
		"./img/Sun/frame-16.xpm",
		&game_ref->textures.sun[15],
		game_ref, err_flag
		);
	open_texture(
		"./img/Sun/frame-17.xpm",
		&game_ref->textures.sun[16],
		game_ref, err_flag
		);
	open_texture(
		"./img/Sun/frame-18.xpm",
		&game_ref->textures.sun[17],
		game_ref, err_flag
		);
	open_texture(
		"./img/Sun/frame-19.xpm",
		&game_ref->textures.sun[18],
		game_ref, err_flag
		);
}
