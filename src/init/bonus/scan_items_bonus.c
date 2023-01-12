/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_items_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:04:24 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 11:29:46 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_init_bonus.h"

void	scan_items(t_game *game_ref)
{
	t_2d_point		pos;
	t_int_2d_point	coord;
	t_tile			cur_tile;

	if (NULL == game_ref->map_handle.map)
		return ;
	pos.x = 0;
	while (pos.x < (int)game_ref->map_handle.columns)
	{
		pos.y = 0;
		while (pos.y < (int)game_ref->map_handle.rows)
		{
			coord = as_int_2dpt(&pos);
			cur_tile = game_ref->map_handle.map[coord.y][coord.x];
			if (is_item_map_char(cur_tile))
				ft_lstadd_back(&game_ref->items, ft_new_item_node(&pos));
			pos.y++;
		}
		pos.x++;
	}
}
