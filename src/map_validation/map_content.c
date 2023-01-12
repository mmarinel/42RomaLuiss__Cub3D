/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:14:58 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 12:25:29 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

t_bool			is_map_content_ok( int map_fd, t_map_holder *map_holder);
static void		parse_map( t_map_holder *map_handle, char **map,
					t_bool *err_flag );
static void		parse_row( t_map_holder *map_handle,
					char **map, size_t row_index,
					t_bool *err_flag );
static t_bool	is_map_char_pos_valid(
					t_map_holder *map_handle,
					char **map,
					size_t row_index, size_t col_index
					);
static void		ft_fill_tile_row(
					t_map_holder *map_handle,
					char **char_map,
					size_t row_index,
					t_bool *err_flag
					);
//* end of static declarations

t_bool	is_map_content_ok( int map_fd, t_map_holder *map_holder)
{
	t_bool	error_found;
	char	**map;

	error_found = e_false;
	map = read_map(map_fd, map_holder);
	if (0 == map_holder->columns)
		error_found = e_true;
	else
	{
		parse_map(map_holder, map, &error_found);
		ft_trim_map(map_holder, &error_found);
	}
	ft_splitclear(&map);
	return (error_found == e_false);
}

static void	parse_map( t_map_holder *map_handle, char **map,
			t_bool *err_flag )
{
	size_t	cursor;

	map_handle->map = ft_map_init(map_handle->rows, map_handle->columns);
	if (NULL == map_handle->map)
		*err_flag = e_true;
	cursor = 0;
	while (map[cursor] && e_false == *err_flag)
	{
		parse_row(map_handle, map, cursor, err_flag);
		cursor += 1;
	}
	if (e_false == is_player_found())
		*err_flag = e_true;
	parse_row(NULL, NULL, (size_t)-1, NULL);
}

/**
 * @brief if map_handle is NULL, static variables are reset.
 *
 * @param map_handle
 * @param map
 * @param row_index
 * @param err_flag
 */
static void	parse_row(
	t_map_holder *map_handle,
	char **map, size_t row_index,
	t_bool *err_flag
	)
{
	static t_bool	empty_line_found_after_non_empty_one = e_false;
	static t_bool	non_empty_line_found = e_false;

	if (NULL == map_handle)
	{
		empty_line_found_after_non_empty_one = e_false;
		non_empty_line_found = e_false;
		return ;
	}
	if (ft_str_isempty(map[row_index]))
	{
		if (non_empty_line_found)
			empty_line_found_after_non_empty_one = e_true;
	}
	else
	{
		if (empty_line_found_after_non_empty_one)
			*err_flag = e_true;
		non_empty_line_found = e_true;
	}
	ft_fill_tile_row(map_handle, map, row_index, err_flag);
}

static void	ft_fill_tile_row(
					t_map_holder *map_handle,
					char **char_map,
					size_t row_index,
					t_bool *err_flag
				)
{
	size_t	col;

	col = 0;
	while (char_map[row_index][col] && e_false == *err_flag)
	{
		if (e_false == is_valid_map_char(char_map[row_index][col])
			|| e_false == is_map_char_pos_valid(
							map_handle, char_map,
							row_index, col
						)
		)
			*err_flag = e_true;
		else
		{
			if (is_player_map_char(char_map[row_index][col]))
			{
				map_handle->player_initial_dir = char_map[row_index][col];
			}
			map_handle->map[row_index][col] = char_map[row_index][col];
		}
		col += 1;
	}
}

static t_bool	is_map_char_pos_valid(
					t_map_holder *map_handle,
					char **map,
					size_t row_index, size_t col_index
)
{
	if (is_floor_map_char(map[row_index][col_index])
		|| is_player_map_char(map[row_index][col_index])
		|| (BONUS && is_entity_map_char(map[row_index][col_index]))
	)
	{
		if (
			(row_index == 0
				|| is_empty_map_char(map[row_index - 1][col_index])
		)
			|| (row_index == map_handle->rows - 1
				|| is_empty_map_char(map[row_index + 1][col_index])
			)
			|| (col_index == 0
				|| is_empty_map_char(map[row_index][col_index - 1])
			)
			|| (col_index == map_handle->columns - 1
				|| is_empty_map_char(map[row_index][col_index + 1])
			)
		)
			return (e_false);
	}
	return (e_true);
}
