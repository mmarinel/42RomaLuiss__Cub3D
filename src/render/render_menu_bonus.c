/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_menu_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:44:18 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 16:35:45 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static t_data	*get_menu(t_game *g);
//*		end of static declarations

void	render_menu_next_frame(t_game *g)
{
	mlx_put_image_to_window(
		g->screen_handle.mlx, g->screen_handle.window,
		get_menu(g)[g->menu.menu_screen].img,
		0, 0
		);
}

static t_data	*get_menu(t_game *g)
{
	if (g->menu.in_initial_menu)
		return (g->textures.menu);
	else
	{
		if (g->player.hp <= 0)
			return (g->textures.game_over);
		else
			return (g->textures.game_win);
	}
}
