/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:55:05 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/04 11:18:11 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

void	ft_free_map( t_tile ***map_ref, size_t rows )
{
	t_tile	**map;
	size_t	cursor;

	map = *map_ref;
	if (NULL == map)
		return ;
	cursor = 0;
	while (cursor < rows)
	{
		free(map[cursor]);
		cursor += 1;
	}
	free(map);
	*map_ref = NULL;
}

t_tile	**ft_map_init( size_t rows, size_t columns )
{
	t_tile	**map;
	size_t	cursor;

	map = (t_tile **) ft_calloc(rows, sizeof(t_tile *));
	if (NULL == map)
		return (NULL);
	cursor = 0;
	while (cursor < rows)
	{
		map[cursor] = (t_tile *) ft_calloc(columns, sizeof(t_tile));
		if (NULL == map[cursor])
		{
			ft_free_map(&map, cursor);
			return (NULL);
		}
		cursor++;
	}
	return (map);
}
