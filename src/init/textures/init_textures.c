/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 14:44:47 by earendil          #+#    #+#             */
/*   Updated: 2023/01/13 15:12:02 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_init.h"

static void	init_sun_textures(t_game *game_ref);
//*		end of static declarations

void	game_init_textures(t_game *game_ref)
{
	game_ref->textures.background.loaded = e_false;
	game_ref->textures.door.closed.loaded = e_false;
	game_ref->textures.door.ajar.loaded = e_false;
	game_ref->textures.door.open.loaded = e_false;
	game_ref->textures.enemy[0].loaded = e_false;
	game_ref->textures.enemy[1].loaded = e_false;
	game_ref->textures.game_over[MENU_NEWG].loaded = e_false;
	game_ref->textures.game_over[MENU_EXIT].loaded = e_false;
	game_ref->textures.game_win[MENU_NEWG].loaded = e_false;
	game_ref->textures.game_win[MENU_EXIT].loaded = e_false;
	game_ref->textures.item.loaded = e_false;
	game_ref->textures.menu[MENU_NEWG].loaded = e_false;
	game_ref->textures.menu[MENU_EXIT].loaded = e_false;
	init_sun_textures(game_ref);
	game_ref->textures.wall.north.loaded = e_false;
	game_ref->textures.wall.south.loaded = e_false;
	game_ref->textures.wall.west.loaded = e_false;
	game_ref->textures.wall.east.loaded = e_false;
}

static void	init_sun_textures(t_game *game_ref)
{
	game_ref->textures.sun[0].loaded = e_false;
	game_ref->textures.sun[1].loaded = e_false;
	game_ref->textures.sun[2].loaded = e_false;
	game_ref->textures.sun[3].loaded = e_false;
	game_ref->textures.sun[4].loaded = e_false;
	game_ref->textures.sun[5].loaded = e_false;
	game_ref->textures.sun[6].loaded = e_false;
	game_ref->textures.sun[7].loaded = e_false;
	game_ref->textures.sun[8].loaded = e_false;
	game_ref->textures.sun[9].loaded = e_false;
	game_ref->textures.sun[10].loaded = e_false;
	game_ref->textures.sun[11].loaded = e_false;
	game_ref->textures.sun[12].loaded = e_false;
	game_ref->textures.sun[13].loaded = e_false;
	game_ref->textures.sun[14].loaded = e_false;
	game_ref->textures.sun[15].loaded = e_false;
	game_ref->textures.sun[16].loaded = e_false;
	game_ref->textures.sun[17].loaded = e_false;
	game_ref->textures.sun[18].loaded = e_false;
}
