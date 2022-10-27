/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:19:54 by earendil          #+#    #+#             */
/*   Updated: 2022/10/27 07:59:16 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

static t_bool	is_file_content_valid( const char* path, t_map_holder* map_handle );
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
		ft_write(STDOUT_FILENO, RED "Error\n" RESET "map: fields error\n");
	else if (e_false == is_map_content_ok(map_fd, map_handle))
		ft_write(STDOUT_FILENO, RED "Error\n" RESET "map: invalid map\n");
	else
		return (e_true);
	return (e_false);
}

t_bool	is_map_attributes_ok( int map_fd, t_map_holder* map_handle  )
{
	t_bool	error_found;
	char	*next_line;

	error_found = e_false;
	while (
		map_fields_incomplete(map_handle)
		&& e_false == error_found)
	{
		next_line = get_next_line(map_fd);
		if (NULL == next_line)
			error_found = e_true;
		
	}
}