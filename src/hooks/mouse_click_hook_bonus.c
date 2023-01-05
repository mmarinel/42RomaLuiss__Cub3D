/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click_hook_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:37:08 by earendil          #+#    #+#             */
/*   Updated: 2023/01/05 13:55:39 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

static void	in_menu_hook(int key, const t_int_2d_point *px, t_game *game);
static void	in_game_hook(int key, const t_int_2d_point *px, t_game *game);
//*		end of static declarations

int	mouse_click_hook(int key, int x, int y, t_game *game)
{
	const t_int_2d_point	px = (t_int_2d_point){x, y};

	if (game->menu.in_end_menu || game->menu.in_initial_menu)
		in_menu_hook(key, &px, game);
	else
		in_game_hook(key, &px, game);
	return (0);
}

static void	in_menu_hook(int key, const t_int_2d_point *px, t_game *game)
{
	if (
		LEFT_CLICK == key
		&& (
			rect_button_focused(
				px,
				&game->menu.newg_btn_top_left,
				&game->menu.newg_btn_bottom_right)
			|| rect_button_focused(
				px,
				&game->menu.exit_btn_top_left,
				&game->menu.exit_btn_bottom_right)
			)
	)
	{
		game->mouse_clicked = e_true;
	}
}

static void	in_game_hook(int key, const t_int_2d_point *px, t_game *game)
{
	(void)px;
	if (LEFT_CLICK == key)
		game->mouse_clicked = e_true;
}
