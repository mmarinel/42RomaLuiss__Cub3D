/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   W_key.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:37:28 by earendil          #+#    #+#             */
/*   Updated: 2022/12/21 17:51:51 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys_behavior.h"

void	w_key_handler_pressed(t_game *game)
{
	t_2d_point		new_pos;
	t_int_2d_point	next_tile;
	
	new_pos = new_player_pos(e_W_KEY, game);
	next_tile = as_int_2dpt(&new_pos);
	if (is_free_pos(game, new_pos))
	{
		game->player.pos = new_pos;
	}
	else if (
		BONUS && is_door_map_char(
			game->map_handle.map[next_tile.y][next_tile.x]
			))
		move_across_door(game, &new_pos, e_W_KEY);
}
