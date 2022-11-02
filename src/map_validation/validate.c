/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:19:54 by earendil          #+#    #+#             */
/*   Updated: 2022/11/02 08:33:23 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"
#include <stdio.h>
static t_bool	is_file_content_valid( const char* path, t_map_holder* map_handle );
t_bool			is_map_attributes_ok( int map_fd, t_map_holder* map_handle );
static t_bool	map_fields_complete( t_map_holder* map_handle );
static void		parse_fields_line( t_map_holder *map_handle, const char* line,
					t_bool* err_flag);
static void		parse_rgb_field( t_color *color_field, char* rgb_string,
					t_bool* err_flag );
static void		parse_rgb_item( short* item_ref, const char* channel,
					t_bool* err_flag );
static t_bool	is_map_content_ok( int map_fd, t_map_holder *map_holder);
static void		parse_map( t_map_holder *map_handle, char* map_string,
					t_bool* err_flag );
static void		parse_row( t_map_holder *map_handle, size_t row_index,
					const char* row, t_bool* err_flag );
static t_bool	is_map_char_pos_valid(
					char map_char,
					t_map_holder *map_handle,
					size_t row_index, size_t col_index
				);
static t_tile	ft_char_to_tile( char c );
static void		map_size( const char* map_string,
					size_t* rows, size_t* columns );
static char		*read_map( int map_fd );
//* end of static declarations

t_bool	is_valid_map( const char* path, t_map_holder* map_handle )
{
	if (e_false == is_file_type(path, MAP_FILE_EXTENSION)
		|| e_false == is_file_content_valid(path, map_handle))
	{
		ft_free_map(&map_handle->map, map_handle->rows);
		return (e_false);
	}
	return (e_true);
}

static t_bool	is_file_content_valid(
	const char* path,
	t_map_holder* map_handle
	)
{
	int	map_fd;

	map_fd = open(path, O_RDONLY);
	if (-1 == map_fd)
		perror(RED ERROR_SIG RESET "map");
	else if (e_false == is_map_attributes_ok(map_fd, map_handle))
		ft_write(STDERR_FILENO, RED "Error\n" RESET "map: fields error\n");
	else if (e_false == is_map_content_ok(map_fd, map_handle))
		ft_write(STDERR_FILENO, RED "Error\n" RESET "map: invalid map\n");
	else
		return (e_true);
	return (e_false);
}

t_bool	is_map_attributes_ok( int map_fd, t_map_holder* map_handle )
{
	t_bool	error_found;
	char	*next_line;

	error_found = e_false;
	while (
		e_false == map_fields_complete(map_handle)
		&& e_false == error_found
	)
	{
		next_line = get_next_line(map_fd);
		if (NULL == next_line)
			error_found = e_true;
		else
		{
			if (e_false == ft_str_isempty(next_line))
				parse_fields_line(map_handle, next_line, &error_found);
			free(next_line);
		}
	}
	return (error_found == e_false);
}

static t_bool	map_fields_complete( t_map_holder* map_handle )
{
	return (
		map_handle->no_texture && map_handle->so_texture
		&& map_handle->we_texture && map_handle->ea_texture
		&& -1 != map_handle->f_color.alpha && -1 != map_handle->c_color.alpha
	);
}

static void		parse_fields_line( t_map_holder *map_handle, const char* line,
					t_bool* err_flag)
{
	char	**splitted;
	char	*right_hand_side;

	splitted = ft_multisplit(line, " VV\t");
	printf("printing cur line split\n");
	ft_splitprint(splitted);
	printf("printing END..............\n");
	if (ft_splitlen(splitted) < 2)
		*err_flag = e_true;
	else
	{
		right_hand_side = ft_split_merge(splitted + 1, " ", e_false);
		if (0 == ft_strcmp(splitted[0], "NO"))
			map_handle->no_texture = ft_strdup(splitted[1]);
		else if (0 == ft_strcmp(splitted[0], "SO"))
			map_handle->so_texture = ft_strdup(splitted[1]);
		else if (0 == ft_strcmp(splitted[0], "WE"))
			map_handle->we_texture = ft_strdup(splitted[1]);
		else if (0 == ft_strcmp(splitted[0], "EA"))
			map_handle->ea_texture = ft_strdup(splitted[1]);
		else if (0 == ft_strcmp(splitted[0], "F"))
			parse_rgb_field(&map_handle->f_color, right_hand_side, err_flag);
		else if (0 == ft_strcmp(splitted[0], "C"))
			parse_rgb_field(&map_handle->c_color, right_hand_side, err_flag);
		else
			*err_flag = e_true;
		free(right_hand_side);
	}
	ft_splitclear(splitted);
}

static void		parse_rgb_field( t_color *color_field, char* rgb_string,
					t_bool* err_flag )
{
	char	**splitted;

	printf("parse_rgb_field: rgb_string = %s\n", rgb_string);
	splitted = ft_split(rgb_string, ',');
	printf("..printing rgb val split:\n");
	ft_splitprint(splitted);
	printf(".............................................\n");
	if (ft_splitlen(splitted) != 3)
		*err_flag = e_true;
	else
	{
		parse_rgb_item(&color_field->red, splitted[0], err_flag);
		parse_rgb_item(&color_field->green, splitted[1], err_flag);
		parse_rgb_item(&color_field->blue, splitted[2], err_flag);
		if (e_false == *err_flag
			&&
			ft_iscolor(color_field->red, color_field->green, color_field->blue)
		)
			color_field->alpha = 1;
		else
			*err_flag = e_true;
	}
	ft_splitclear(splitted);
}

static void	parse_rgb_item( short* item_ref, const char* channel,
				t_bool* err_flag )
{
	printf("parse_rgb_item: input is %s\n", channel);
	if (ft_isdigit_string(channel))
		*item_ref = ft_atoi(channel);
	else
	{
		printf("ft_isdigit_string failed for %s\n", channel);
		*item_ref = -1;
		*err_flag = e_true;
	}
}

static t_bool	is_map_content_ok( int map_fd, t_map_holder *map_holder)
{
	t_bool	error_found;
	char	*map_string;

	error_found = e_false;
	map_string = read_map(map_fd);
	map_size(map_string, &map_holder->rows, &map_holder->columns);
	if (0 == map_holder->columns + map_holder->rows)
		error_found = e_true;
	else
		parse_map(map_holder, map_string, &error_found);
	free(map_string);
	return (error_found == e_false);
}

//*			DOING THIS
//*							
//*							
static void	parse_map( t_map_holder *map_handle, char* map_string,
			t_bool* err_flag )
{
	char	**splitted;
	char	*row;
	size_t	cursor;

	map_handle->map = ft_map_init(map_handle->rows, map_handle->columns);
	if (NULL == map_handle->map)
		*err_flag = e_true;
	splitted = ft_split(map_string, '\n');
	cursor = 0;
	while (splitted[cursor] && e_false == *err_flag)
	{
		row = ft_strjoin(
			splitted[cursor],
			ft_string_new(
				' ',
				map_handle->columns - ft_strlen(splitted[cursor])
			),
			e_false, e_true
		);
		parse_row(map_handle, cursor, row, err_flag);
		free(row);
		cursor += 1;
	}
	ft_splitclear(splitted);
	// if (*err_flag)
	// 	ft_free_map(map_handle->map, map_handle->rows);
}

static void	parse_row( t_map_holder *map_handle, size_t row_index,
				const char* row, t_bool* err_flag )
{
	size_t	cursor;

	if (ft_str_isempty(row))
		*err_flag = e_true;
	else
	{
		cursor = 0;
		while (row[cursor] && e_false == *err_flag)
		{
			if (e_false == is_valid_map_char(row[cursor])
				|| e_false == is_map_char_pos_valid(row[cursor], map_handle,
								row_index, cursor
							)
			)
				*err_flag = e_true;
			else
				map_handle->map[row_index][cursor] = ft_char_to_tile(row[cursor]);
			cursor += 1;
		}
	}
}

static t_bool	is_map_char_pos_valid(
					char map_char,
					t_map_holder *map_handle,
					size_t row_index, size_t col_index
)
{
		if (is_floor_map_char(map_char) || is_player_map_char(map_char))
			if (
				(row_index == 0
					|| e_EMPTY == map_handle->map[row_index - 1][col_index]
				)
				|| (row_index == map_handle->rows - 1
					|| e_EMPTY == map_handle->map[row_index + 1][col_index]
				)
				|| (col_index == 0
					|| e_EMPTY == map_handle->map[row_index][col_index - 1]
				)
				|| (col_index == map_handle->columns - 1
					|| e_EMPTY == map_handle->map[row_index][col_index + 1]
				)
			)
				return (e_false);
	return (e_true);
}

static t_tile	ft_char_to_tile( char c )
{
	if (is_player_map_char(c))
	{
		return (c);
	}
	else if ('0' == c)
		return (e_FLOOR);
	else if ('1' == c)
		return (e_WALL);
	else
		return (e_EMPTY);
}

static void	map_size( const char* map_string,
					size_t* rows, size_t* columns )
{
	int		max_row_len;
	int		cur_row_len;
	char	**splitted;
	size_t	cursor;

	max_row_len = 0;
	cursor = 0;
	splitted = ft_split(map_string, '\n');
	if (NULL != splitted)
	{
		while (splitted[cursor])
		{
			cur_row_len = ft_strlen(splitted[cursor]);
			if (cur_row_len > max_row_len)
				max_row_len = cur_row_len;
			cursor += 1;
		}
	}
	ft_splitclear(splitted);
	*columns = max_row_len;
	*rows = cursor;
}

//* I Know this is (perhaps) bad !!!!
static char	*read_map( int map_fd )
{
	char	*map_string;
	char	*line;

	map_string = NULL;
	while (e_true)
	{
		line = get_next_line(map_fd);
		if (NULL == line)
			break ;
		map_string = ft_strjoin(map_string, line, e_true, e_false);
		free(line);
	}
	return (map_string);
}
