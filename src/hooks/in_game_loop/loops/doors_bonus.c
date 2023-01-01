/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:24:22 by earendil          #+#    #+#             */
/*   Updated: 2023/01/01 19:31:17 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "in_game_loops_bonus.h"

void	animate_doors(t_game *game)
{
	t_list	*cur_node;
	t_door	*door;

	cur_node = game->doors;
	while (cur_node)
	{
		door = (t_door *)cur_node->content;
		if (door)
		{
			if (e_DOOR_AJAR == door->status)
			{
				door->opening_delay_frames -= 1;
				if (0 == door->opening_delay_frames)
				{
					door->status = (door->prev_status + 1) % 2;
					door->opening_delay_frames = DOOR_OPENING_DELAY_FRAMES;
				}
			}
		}
		cur_node = cur_node->next;
	}
}
