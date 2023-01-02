/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:37:28 by earendil          #+#    #+#             */
/*   Updated: 2023/01/01 21:24:52 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "in_game_keys.h"

void	in_game_movement_key(t_key_state *key, t_game *game)
{
	t_2d_point	new_pos;
	
	if (e_SHIFT_KEY == key->code)
		in_game_shift_key(key, game);
	if (KeyPress == key->state)
	{
		new_pos = new_player_pos(key->code, game);
		if (is_traversable_pos(game, &game->player.pos, &new_pos))
		{
				game->player.pos = new_pos;
		}
	}
}
