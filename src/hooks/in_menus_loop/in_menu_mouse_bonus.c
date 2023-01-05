/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_menu_mouse_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:55:31 by earendil          #+#    #+#             */
/*   Updated: 2023/01/05 13:54:03 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "in_menu_loop_bonus.h"

void	in_menu_mouse_handler(t_game *game)
{
	static t_int_2d_point	prev = (t_int_2d_point){-1, -1};
	t_int_2d_point			px;

	mlx_mouse_get_pos(
		game->screen_handle.mlx, game->screen_handle.window,
		&px.x, &px.y
	);
	if (e_false == ft_int_2d_point_equals(&prev, &px))
	{
		if (rect_button_focused(&px,
			&game->menu.newg_btn_top_left, &game->menu.newg_btn_bottom_right))
			game->menu.menu_screen = MENU_NEWG;
		else if (rect_button_focused(&px,
			&game->menu.exit_btn_top_left, &game->menu.exit_btn_bottom_right))
			game->menu.menu_screen = MENU_EXIT;
		else
			return ;
		prev = px;
	}
}
