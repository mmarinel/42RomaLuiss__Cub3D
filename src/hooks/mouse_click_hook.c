/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_click_hook.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:37:08 by earendil          #+#    #+#             */
/*   Updated: 2023/01/02 10:56:39 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

int	mouse_click_hook(int key, int x, int y, t_game *game)
{
	const t_int_2d_point	px = (t_int_2d_point){x, y};

	if (
		LEFT_CLICK == key
		&& (game->menu.in_end_menu || game->menu.in_initial_menu)
		&& (
			rect_button_focused(
				&px,
				&game->menu.newg_btn_top_left,
				&game->menu.newg_btn_bottom_right)
			|| rect_button_focused(
				&px,
				&game->menu.exit_btn_top_left,
				&game->menu.exit_btn_bottom_right)
			)
	)
	{
		game->menu.mouse_clicked = e_true;
	}
	return (0);
}
