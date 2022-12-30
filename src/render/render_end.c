/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:24:34 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 18:28:01 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static t_data	*get_menu(t_game *g);
//*		end of static declarations

void	render_end_next_frame(t_game *g)
{
	static int	prev_frame = -1;
	// printf("menu screen: %d\n", g->menu_screen);

	if (prev_frame == g->menu_screen)
		return ;
	prev_frame = g->menu_screen;
	mlx_put_image_to_window(
		g->screen_handle.mlx, g->screen_handle.window,
		get_menu(g)[g->menu_screen].img,
		0, 0
	);
}

static t_data	*get_menu(t_game *g)
{
	if (g->player.hp <= 0)
		return (g->textures.game_over);
	else
		return (g->textures.game_win);
}
