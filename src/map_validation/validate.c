/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:19:54 by earendil          #+#    #+#             */
/*   Updated: 2022/10/31 16:16:52 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"
#include <stdio.h>
static t_bool	is_file_content_valid( const char* path, t_map_holder* map_handle );
static void		parse_fields_line( t_map_holder *map_handle, const char* line,
					t_bool* err_flag);
static void		parse_rgb_field( t_color *color_field, char* rgb_string,
					t_bool* err_flag );
static void		parse_rgb_item( short* item_ref, const char* channel,
					t_bool* err_flag );
static t_bool	map_fields_complete( t_map_holder* map_handle );
static t_bool	is_map_content_ok( int map_fd, t_map_holder *map_holder);
static size_t	map_row_len( const char* map_string );
static char		*read_map( int map_fd );
t_bool			is_map_attributes_ok( int map_fd, t_map_holder* map_handle );
//* end of static declarations

t_bool	is_valid_map( const char* path, t_map_holder* map_handle )
{
	if (e_false == is_file_type(path, MAP_FILE_EXTENSION))
		return (e_false);
	if (e_false == is_file_content_valid(path, map_handle))
		return (e_false);
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
	int		max_row_len;

	error_found = e_false;
	map_string = read_map(map_fd);
	max_row_len = map_row_len(map_string);
	if (max_row_len < 0)
		error_found = e_true;
	else
	{
		map_holder->size = max_row_len;
		parse_map(map_holder, map_string, &error_found);
	}
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

	map_handle->map = (t_tile **) malloc(sizeof(t_tile *) * map_handle->size);
	splitted = ft_split(map_string, '\n');
	cursor = 0;
	while (splitted[cursor] && e_false == *err_flag)
	{
		row = ft_strjoin(
			splitted[cursor],
			ft_string_new(' ', map_handle->size - ft_strlen(splitted[cursor])),
			e_false, e_true
		);
		parse_row(map_handle, cursor, row, err_flag);
		cursor += 1;
	}
	ft_splitclear(splitted);
	if (*err_flag)
		ft_free_map(map_handle->map);
}

static size_t	map_row_len( const char* map_string )
{
	int		max_row_len;
	int		cur_row_len;
	char	**splitted;
	size_t	cursor;

	max_row_len = 0;
	splitted = ft_split(map_string, '\n');
	cursor = 0;
	while (splitted[cursor])
	{
		cur_row_len = ft_strlen(splitted[cursor]);
		if (cur_row_len > max_row_len)
			max_row_len = cur_row_len;
		cursor += 1;
	}
	ft_splitclear(splitted);
}

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
