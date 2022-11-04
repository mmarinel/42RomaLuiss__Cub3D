/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 18:14:58 by earendil          #+#    #+#             */
/*   Updated: 2022/11/04 11:00:33 by mmarinel         ###   ########.fr       */
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
		parse_map(map_holder, map, &error_found);
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
	while (ft_str_isempty(map[cursor]))
		cursor += 1;
	while (map[cursor] && e_false == *err_flag)
	{
		parse_row(map_handle, map, cursor, err_flag);
		cursor += 1;
	}
	if (e_false == is_player_found())
		*err_flag = e_true;
}

static void	parse_row( t_map_holder *map_handle,
				char **map, size_t row_index,
				t_bool *err_flag )
{
	size_t			cursor;
	static t_bool	empty_line_found = e_false;

	if (ft_str_isempty(map[row_index]))
		empty_line_found = e_true;
	else
	{
		if (empty_line_found)
			*err_flag = e_true;
		cursor = 0;
		while (map[row_index][cursor] && e_false == *err_flag)
		{
			if (e_false == is_valid_map_char(map[row_index][cursor])
				|| e_false == is_map_char_pos_valid(
								map_handle, map,
								row_index, cursor
							)
			)
				*err_flag = e_true;
			else
				map_handle->map[row_index][cursor] = map[row_index][cursor];
			cursor += 1;
		}
	}
}

static t_bool	is_map_char_pos_valid(
					t_map_holder *map_handle,
					char **map,
					size_t row_index, size_t col_index
)
{
	if (is_floor_map_char(map[row_index][col_index])
		|| is_player_map_char(map[row_index][col_index]))
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
	return (e_true);
}
