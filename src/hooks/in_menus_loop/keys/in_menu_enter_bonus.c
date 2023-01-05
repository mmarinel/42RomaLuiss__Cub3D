/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_menu_enter_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:06:52 by earendil          #+#    #+#             */
/*   Updated: 2023/01/05 13:53:13 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../in_menu_loop_bonus.h"

static void	enter_leave_game(t_game *game);
static void	el_initial_menu(t_game *game);
static void	el_end_menu(t_game *game);
static void	load_game(t_game *game, const char *lvl);
//*		end of static declarations

void	in_menu_enter_key(t_key_state *key, t_game *game)
{
	if (KeyPress == key->state || e_true == game->mouse_clicked)
	{
		enter_leave_game(game);
		key->state = -1;
	}
}

static void	enter_leave_game(t_game *game)
{
	if (game->menu.in_initial_menu)
		el_initial_menu(game);
	if (game->menu.in_end_menu)
		el_end_menu(game);
}

static void	el_initial_menu(t_game *game)
{
	if (MENU_EXIT == game->menu.menu_screen)
		exit_game(game);
	game->mouse_clicked = e_false;
	game->menu.in_initial_menu = e_false;
	game->menu.menu_screen = 0;
}

static void	el_end_menu(t_game *game)
{
	if (MENU_EXIT == game->menu.menu_screen)
		exit_game(game);
	else
	{
		if (game->player.hp <= 0)
			load_game(game, game->cur_lvl);
		else
			load_game(game, game->lvls[rand() % LEVELS]);
		game->mouse_clicked = e_false;
		game->menu.in_initial_menu = e_false;
		game->menu.in_end_menu = e_false;
		game->menu.menu_screen = 0;
	}
}

static void	load_game(t_game *game, const char *lvl)
{
	clean_game(game);
	ft_game_init(lvl, game, SCREEN_WIDTH, SCREEN_HEIGHT);
}
