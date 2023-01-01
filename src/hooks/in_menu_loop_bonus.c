/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_menu_loop_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:10:22 by earendil          #+#    #+#             */
/*   Updated: 2023/01/01 15:56:03 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

static void	enter_leave_game(t_game *game);
//*		end of static declarations

void	in_menu_loop(t_game *game)
{
	const int	menu_frames = 2;

	if (KeyPress == game->key_map.keys[ENTER_INDEX].state)
	{
		enter_leave_game(game);
		game->key_map.keys[ENTER_INDEX].state = -1;
	}
	else if (KeyPress == game->key_map.keys[UP_INDEX].state)
		game->key_map.keys[UP_INDEX].state = -1;
	else if (KeyPress == game->key_map.keys[DOWN_INDEX].state)
		game->key_map.keys[DOWN_INDEX].state = -1;
	else
		return ;
	game->menu_screen = (game->menu_screen + 1) % menu_frames;
	// printf("menu screen: %d\n", game->menu_screen);
}

static void	enter_leave_game(t_game *game)
{
	if (MENU_EXIT == game->menu_screen)
		exit_game(game);
	game->in_menu = e_false;
	game->menu_screen = 0;
}
