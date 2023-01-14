/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 09:35:01 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/14 11:00:48 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_next_frame(t_game *g)
{
	if (BONUS && (g->menu.in_initial_menu || g->menu.in_end_menu))
		render_menu_next_frame(g);
	else
		render_game_next_frame(g);
	mlx_do_sync(g->screen_handle.mlx);
}
