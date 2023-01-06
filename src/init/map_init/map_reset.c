/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:30:14 by earendil          #+#    #+#             */
/*   Updated: 2023/01/06 13:00:38 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_init.h"

static t_bool	char_to_reset(char c);
//*		end of static declarations

void	map_reset(t_map_holder *map_handle)
{
	size_t	x;
	size_t	y;

	if (NULL == map_handle)
		return ;
	x = 0;
	while (x < map_handle->columns)
	{
		y = 0;
		while (y < map_handle->rows)
		{
			if (char_to_reset(map_handle->map[y][x]))
				map_handle->map[y][x] = e_FLOOR;
			y++;
		}
		x++;
	}
}

static t_bool	char_to_reset(char c)
{
	return (
		is_player_map_char(c)
		|| (
			BONUS && (
				is_enemy_map_char(c) || is_item_map_char(c)
			)
		)
	);
}
