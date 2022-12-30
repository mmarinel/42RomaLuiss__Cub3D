/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_end_loop_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:10:22 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 20:49:20 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"
# include "../init/game_init_module.h"
# include <time.h>

static void	enter_leave_game(t_game *game);
static void	load_game(t_game *game, const char *lvl);
//*		end of static declarations

void	in_end_loop(t_game *game)
{
	const int	menu_frames = 2;

	if (KeyPress == game->keys[ENTER_INDEX].state)
	{
		game->keys[ENTER_INDEX].state = -1;
		enter_leave_game(game);
	}
	else if (KeyPress == game->keys[UP_INDEX].state)
		game->keys[UP_INDEX].state = -1;
	else if (KeyPress == game->keys[DOWN_INDEX].state)
		game->keys[DOWN_INDEX].state = -1;
	else
		return ;
	game->menu_screen = (game->menu_screen + 1) % menu_frames;
}

static void	enter_leave_game(t_game *game)
{
	if (MENU_EXIT == game->menu_screen)
		exit_game(game);
	else
	{
		if (game->player.hp <= 0)
			load_game(game, game->cur_lvl);
		else
			load_game(game, game->lvls[rand() % LEVELS]);
		game->in_end = e_false;
		game->in_menu = e_false;
		game->menu_screen = 0;
	}
}

static void	load_game(t_game *game, const char *lvl)
{
	clean_game(game);
	ft_game_init(lvl, game, SCREEN_WIDTH, SCREEN_HEIGHT);
}
