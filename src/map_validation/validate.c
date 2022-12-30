/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:19:54 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 19:25:15 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

static t_bool	is_file_type_valid(const char *path);
static t_bool	is_file_content_valid( const char *path,
					t_map_holder *map_handle );
//* end of static declarations

t_bool	is_valid_map( const char *path, t_map_holder *map_handle )
{
	if (
		e_false == is_file_type_valid(path)
		|| e_false == is_file_content_valid(path, map_handle)
	)
	{
		ft_free_map(&map_handle->map, map_handle->rows);
		return (e_false);
	}
	else
	{
		forget_player();
		return (e_true);
	}
}

static t_bool	is_file_type_valid(const char *path)
{
	if (e_false == is_file_type(path, MAP_FILE_EXTENSION))
	{
		ft_write(STDERR_FILENO, RED "Error:\n" RESET "map: wrong file type\n");
		return (e_false);
	}
	return (e_true);
}

static t_bool	is_file_content_valid( const char *path,
					t_map_holder *map_handle )
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
