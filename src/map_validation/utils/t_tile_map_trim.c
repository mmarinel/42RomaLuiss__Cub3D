/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tile_map_trim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:11:48 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/12 12:33:02 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

static size_t	ft_effective_rows(t_map_holder *map_handle);
static void		ft_fill_trim(t_tile **trimmed, size_t effective_rows,
					t_map_holder *map_handle);
static t_bool	ft_empty_row(t_tile *row, size_t columns);
static void		ft_copy_row(t_tile **map, size_t map_row, t_tile *to_copy,
					size_t columns);
//*		end of static declarations

void	ft_trim_map(t_map_holder *map_handle, t_bool *err_flag)
{
	size_t	effective_rows;
	t_tile	**trimmed;

	if (NULL == map_handle)
		return ;
	effective_rows = ft_effective_rows(map_handle);
	trimmed = ft_map_init(effective_rows, map_handle->columns);
	if (NULL == trimmed)
		*err_flag = e_true;
	else
		ft_fill_trim(trimmed, effective_rows, map_handle);
}

static size_t	ft_effective_rows(t_map_holder *map_handle)
{
	size_t	effective_rows;
	size_t	row;

	effective_rows = 0;
	row = 0;
	while (row < map_handle->rows)
	{
		if (e_false == ft_empty_row(map_handle->map[row], map_handle->columns))
			effective_rows += 1;
		row++;
	}
	return (effective_rows);
}

static void	ft_fill_trim(t_tile **trimmed, size_t effective_rows,
					t_map_holder *map_handle)
{
	t_tile	**map;
	size_t	map_row;
	size_t	trimmed_row;

	map = map_handle->map;
	trimmed_row = 0;
	map_row = 0;
	while (map_row < map_handle->rows)
	{
		if (e_false == ft_empty_row(map[map_row], map_handle->columns))
		{
			ft_copy_row(
				trimmed, trimmed_row, map[map_row], map_handle->columns
				);
			trimmed_row++;
		}
		map_row++;
	}
	ft_free_map(&map_handle->map, map_handle->rows);
	map_handle->rows = effective_rows;
	map_handle->map = trimmed;
}

static t_bool	ft_empty_row(t_tile *row, size_t columns)
{
	size_t	j;

	j = 0;
	while (j < columns)
	{
		if (e_false == ft_isspace(row[j]))
			return (e_false);
		j++;
	}
	return (e_true);
}

static void	ft_copy_row(t_tile **map, size_t map_row, t_tile *to_copy,
				size_t columns)
{
	size_t	col;

	col = 0;
	while (col < columns)
	{
		map[map_row][col] = to_copy[col];
		col += 1;
	}
}
