/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_menu_move_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:08:44 by earendil          #+#    #+#             */
/*   Updated: 2023/01/05 13:53:21 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../in_menu_loop_bonus.h"

void	in_menu_move(t_key_state *key, t_game *game)
{
	const int	menu_frames = 2;

	if (
		KeyPress == key->state
		&& (e_UP_KEY == key->code || e_DOWN_KEY == key->code))
	{
		key->state = -1;
		game->menu.menu_screen = (game->menu.menu_screen + 1) % menu_frames;
	}
}
