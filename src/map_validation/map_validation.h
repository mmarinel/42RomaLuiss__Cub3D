/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:52:28 by earendil          #+#    #+#             */
/*   Updated: 2022/11/03 18:21:23 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATION_H
# define MAP_VALIDATION_H

# include "../colors.h"
# include "../types.h"
# include "../utils/utils_module.h"

# include <unistd.h>
# include <fcntl.h>
#include <stdio.h>//! REMOVE!!!

# define MAP_FILE_EXTENSION ".cub"
# define ERROR_SIG "Error\n"


t_bool	is_map_attributes_ok( int map_fd, t_map_holder* map_handle );
t_bool	is_map_content_ok( int map_fd, t_map_holder *map_holder);
char		**read_map( int map_fd, t_map_holder* map_handle );

#endif