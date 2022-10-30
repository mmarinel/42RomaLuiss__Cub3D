/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:19:54 by earendil          #+#    #+#             */
/*   Updated: 2022/10/30 14:46:16 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"
#include <stdio.h>
static t_bool	is_file_content_valid( const char* path, t_map_holder* map_handle );
static void		parse_fields_line( t_map_holder *map_handle, const char* line,
					t_bool* err_flag);
static t_bool	map_fields_complete( t_map_holder* map_handle );
static t_bool	is_map_content_ok( int map_fd, t_map_holder *map_holder);
t_bool	is_map_attributes_ok( int map_fd, t_map_holder* map_handle );
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
		&& map_handle->f_texture && map_handle->c_texture
	);
}

static void		parse_fields_line( t_map_holder *map_handle, const char* line,
					t_bool* err_flag)
{
	char	**splitted;

	splitted = ft_multisplit(line, " VV\t");
	printf("printing cur line split\n");
	ft_splitprint(splitted);
	printf("printing END..............\n");
	if (ft_splitlen(splitted) > 2)
		*err_flag = e_true;
	else
	{
		if (0 == ft_strcmp(splitted[0], "NO"))
			map_handle->no_texture = ft_strdup(splitted[0]);
		else if (0 == ft_strcmp(splitted[0], "SO"))
			map_handle->so_texture = ft_strdup(splitted[0]);
		else if (0 == ft_strcmp(splitted[0], "WE"))
			map_handle->we_texture = ft_strdup(splitted[0]);
		else if (0 == ft_strcmp(splitted[0], "EA"))
			map_handle->ea_texture = ft_strdup(splitted[0]);
		else if (0 == ft_strcmp(splitted[0], "F"))
			map_handle->f_texture = ft_strdup(splitted[0]);
		else if (0 == ft_strcmp(splitted[0], "C"))
			map_handle->c_texture = ft_strdup(splitted[0]);
		else
			*err_flag = e_true;
	}
	ft_splitclear(splitted);
}

static t_bool	is_map_content_ok( int map_fd, t_map_holder *map_holder)
{
	(void) map_fd;
	(void) map_holder;
	return (e_true);
}
