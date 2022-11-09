/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tile_debug.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:38:23 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/09 19:02:37 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

void	ft_tile_map_print(t_tile **map, size_t rows, size_t columns)
{
	size_t	i;
	size_t	j;

	printf("\n");
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < columns)
		{
			if (ft_isspace(map[i][j]))
				printf("<space>\t\t");
			else if (ft_isprint(map[i][j]))
				printf("%c\t\t", map[i][j]);
			else
				printf("[garbage]\t\t");
			j += 1;
		}
		printf("\n");
		i += 1;
	}
	printf("\n");
}
