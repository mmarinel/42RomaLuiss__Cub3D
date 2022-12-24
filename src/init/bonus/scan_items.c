/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_items.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:04:24 by earendil          #+#    #+#             */
/*   Updated: 2022/12/24 15:16:14 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_init_bonus.h"

void	scan_items(t_game *game_ref)
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
			if (is_item_map_char(cur_tile))
				ft_lstadd_back(&game_ref->items, ft_new_item_node(&pos));
			pos.y++;
		}
		pos.x++;
	}
}
