/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:30:14 by earendil          #+#    #+#             */
/*   Updated: 2022/12/20 13:38:36 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

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
			if (is_player_map_char(map_handle->map[y][x]))
				map_handle->map[y][x] = e_FLOOR;
			y++;
		}
		x++;
	}
}
