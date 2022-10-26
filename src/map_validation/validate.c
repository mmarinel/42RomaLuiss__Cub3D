/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:19:54 by earendil          #+#    #+#             */
/*   Updated: 2022/10/26 18:51:00 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation.h"

static t_bool	is_file_content_valid( const char* path );
//* end of static declarations

t_bool	is_valid_map( const char* path ) {
	if (e_false == is_file_type(path, MAP_FILE_EXTENSION))
		return (e_false);
	if (e_false == is_file_content_valid(path))
		return (e_false);
	return (true);
}

static t_bool	is_file_content_valid( const char* path )
{
	int	map_fd;

	map_fd = open(path, O_RDONLY);
	if (-1 == map_fd)
		perror(RED ERROR_SIG RESET "map");
	else if (e_false == is_map_attributes_ok(map_fd))
		ft_write( RED "Error\n" RESET "map: fields error\n");
	else if (e_false == is_map_content_ok(map_fd))
		ft_write( RED "Error\n" RESET "map: invalid map\n");
	else
		return (e_true);
	return (e_false);
}
