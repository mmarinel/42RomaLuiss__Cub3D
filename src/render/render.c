/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 09:35:01 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/30 12:24:49 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_next_frame(t_game *g)
{
	// mlx_clear_window(g->screen_handle.mlx, g->screen_handle.window);
	if (BONUS && g->in_menu)
		render_menu_next_frame(g);
	// else if (BONUS && g->in_end)
	// 	render_end_next_frame(g);
	else
		render_game_next_frame(g);
}
