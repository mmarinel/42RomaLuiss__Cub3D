/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:44:18 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 12:24:20 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_menu_next_frame(t_game *g)
{
	static int	prev_frame = -1;
	// printf("menu screen: %d\n", g->menu_screen);

	if (prev_frame == g->menu_screen)
		return ;
	prev_frame = g->menu_screen;
	mlx_put_image_to_window(
		g->screen_handle.mlx, g->screen_handle.window,
		g->textures.menu[g->menu_screen].img,
		0, 0
	);
}
