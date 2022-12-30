/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:22:02 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 18:12:12 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

//*		end of static declarations

int	loop_hook(t_game *game)
{
	if (e_false == game->in_focus)
		return (0);
	if (BONUS && game->in_menu)
		in_menu_loop(game);
	else if (BONUS && game->in_end)
		in_end_loop(game);
	else
		in_game_loop(game);
	render_next_frame(game);
	return (0);
}
