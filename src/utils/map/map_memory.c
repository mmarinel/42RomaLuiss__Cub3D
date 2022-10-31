/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:55:05 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/31 16:08:25 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

void	ft_free_map( t_tile*** map_ref, size_t rows )
{
	t_tile	**map;
	size_t	cursor;

	map = *map_ref;
	cursor = 0;
	while (cursor < rows)
	{
		free(map[cursor]);
		cursor += 1;
	}
	free(map);
	*map_ref = NULL;
}
