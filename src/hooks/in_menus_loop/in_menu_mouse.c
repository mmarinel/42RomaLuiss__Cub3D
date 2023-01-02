/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_menu_mouse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:55:31 by earendil          #+#    #+#             */
/*   Updated: 2023/01/01 22:21:03 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "in_menu_loop_bonus.h"

void	in_menu_mouse_handler(t_game *game)
{
	static t_int_2d_point	prev = (t_int_2d_point){-1, -1};
	const t_int_2d_point	newg[2] = {
		(t_int_2d_point){417, 282},//*	top-left
		(t_int_2d_point){862, 470},//*		bottom-right
	};
	const t_int_2d_point	exit[2] = {
		(t_int_2d_point){417, 463},//*	top-left
		(t_int_2d_point){862, 586},//*		bottom-right
	};
	t_int_2d_point	px;

	mlx_mouse_get_pos(
		game->screen_handle.mlx, game->screen_handle.window,
		&px.x, &px.y
	);
	if (e_false == ft_int_2d_point_equals(&prev, &px))
	{
		if (px.x >= newg[0].x && px.x <= newg[1].x
			&& px.y >= newg[0].y && px.y <= newg[1].y)
			game->menu_screen = MENU_NEWG;
		else if (px.x >= exit[0].x && px.x <= exit[1].x
			&& px.y >= exit[0].y && px.y <= exit[1].y)
			game->menu_screen = MENU_EXIT;
		else
			return ;
		prev = px;
	}
	ft_print_int_2d_point("px", px);
	(void)game;
	//TODO
}
