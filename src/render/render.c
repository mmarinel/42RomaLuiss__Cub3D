/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 09:35:01 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/05 21:10:01 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_next_frame(t_game *g)
{
	if (BONUS && (g->menu.in_initial_menu || g->menu.in_end_menu))
		render_menu_next_frame(g);
	else
		render_game_next_frame(g);
}
