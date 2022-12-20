/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:52:49 by earendil          #+#    #+#             */
/*   Updated: 2022/12/20 14:38:21 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_init_bonus.h"

void	scan_doors(t_game *game_ref)
{
	t_int_2d_point	pos;

	if (NULL == game_ref->map_handle.map)
		return ;
	pos.x = 0;
	while (pos.x < (int)game_ref->map_handle.columns)
	{
		pos.y = 0;
		while (pos.y < (int)game_ref->map_handle.rows)
		{
			if (e_DOOR == game_ref->map_handle.map[pos.y][pos.x])
				ft_lstadd_back(&game_ref->doors, ft_new_door_node(pos));
			pos.y++;
		}
		pos.x++;
	}
}
