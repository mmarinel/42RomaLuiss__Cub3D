/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tile_map_trim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:11:48 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/09 21:58:35 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

static size_t	ft_effective_rows(t_tile **map, size_t rows, size_t columns);
static t_bool	ft_empty_row(t_tile *row, size_t columns);
static void		ft_copy_row(t_tile **map, size_t map_row, t_tile *to_copy,
					size_t columns);
//*		end of static declarations

void	ft_trim_map(t_map_holder *map_handle)
{
	t_tile	**map;
	t_tile	**trimmed;
	size_t	trimmed_row;
	size_t	map_row;
	size_t	effective_rows;

	if (NULL == map_handle)
		return ;
	effective_rows = ft_effective_rows(
		map_handle->map, map_handle->rows,
		map_handle->columns
	);
	map = map_handle->map;
	trimmed = ft_map_init(map_handle->rows, map_handle->columns);
	trimmed_row = 0;
	map_row = 0;
	while (map_row < map_handle->rows)
	{
		if (e_false == ft_empty_row(map[map_row], map_handle->columns))
		{
			ft_copy_row(trimmed, trimmed_row, map[map_row], map_handle->columns);
			trimmed_row++;
		}
		map_row++;
	}
	map_handle->rows = effective_rows;
	map_handle->map = trimmed;
}

static t_bool	ft_empty_row(t_tile *row, size_t columns)
{
	size_t	j;

	j = 0;
	while (j < columns)
	{
		printf(GREEN"ccc"RESET);
		if (e_false == ft_isspace(row[j]))
			return (e_false);
		j++;
	}
	return (e_true);
}

static size_t	ft_effective_rows(t_tile **map, size_t rows, size_t columns)
{
	size_t	effective_rows;
	size_t	row;

	effective_rows = 0;
	row = 0;
	while (row < rows)
	{
		if (e_false == ft_empty_row(map[row], columns))
			effective_rows += 1;
		row++;
	}
	return (effective_rows);
}

static void	ft_copy_row(t_tile **map, size_t map_row, t_tile *to_copy,
				size_t columns)
{
	size_t	col;

	col = 0;
	while (col < columns)
	{
		map[map_row][col] = to_copy[col];
		printf(GREEN "%c " RESET, to_copy[col]);
		col += 1;
	}
}
