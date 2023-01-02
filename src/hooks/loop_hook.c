/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:22:02 by earendil          #+#    #+#             */
/*   Updated: 2023/01/02 10:14:06 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

//*		end of static declarations

int	loop_hook(t_game *game)
{
	if (e_false == game->in_focus)
		return (0);
	if (BONUS
		&& (game->menu.in_initial_menu || game->menu.in_end_menu))
		in_menus_loop(game);
	else
		in_game_loop(game);
	render_next_frame(game);
	return (0);
}
