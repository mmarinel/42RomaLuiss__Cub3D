/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:22:02 by earendil          #+#    #+#             */
/*   Updated: 2023/01/05 13:36:25 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

int	loop_hook(t_game *game)
{
	if (e_false == game->in_focus)
		return (0);
	if (BONUS
		&& (game->menu.in_initial_menu || game->menu.in_end_menu))
		in_menus_loop(game);
	else
		in_game_loop(game);
	game->mouse_clicked = e_false;
	render_next_frame(game);
	return (0);
}
