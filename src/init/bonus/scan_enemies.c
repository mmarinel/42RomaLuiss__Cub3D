/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:04:24 by earendil          #+#    #+#             */
/*   Updated: 2022/12/21 13:00:02 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_init_bonus.h"

void	scan_enemies(t_game *game_ref)
{
	t_2d_point		pos;
	t_int_2d_point	tile_coordinate;
	t_tile			cur_tile;

	if (NULL == game_ref->map_handle.map)
		return ;
	pos.x = 0;
	while (pos.x < (int)game_ref->map_handle.columns)
	{
		pos.y = 0;
		while (pos.y < (int)game_ref->map_handle.rows)
		{
			tile_coordinate = as_int_2dpt(&pos);
			cur_tile = game_ref->map_handle.map\
				[tile_coordinate.y]\
				[tile_coordinate.x];
			if (is_enemy_map_char(cur_tile))
				ft_lstadd_back(&game_ref->enemies, ft_new_enemy_node(&pos));
			pos.y++;
		}
		pos.x++;
	}
}
