/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_types.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:12:31 by earendil          #+#    #+#             */
/*   Updated: 2022/12/24 15:00:29 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATION_TYPES_H
# define MAP_VALIDATION_TYPES_H

# include "../types.h"
# include "../utils/math/uti_math_types.h"

# include "../sys_includes.h"

typedef enum e_tile
{
	e_DOOR_HORIZONTAL = 'D',
	e_DOOR_VERTICAL = 'd',
	e_ENEMY = 'X',
	e_ITEM = 'C',
	e_PLAYER_N = 'N',
	e_PLAYER_S = 'S',
	e_PLAYER_E = 'E',
	e_PLAYER_W = 'W',
	e_FLOOR = '0',
	e_WALL = '1',
	e_EMPTY = '?',
}	t_tile;

typedef struct s_map_holder
{
	t_tile		**map;
	size_t		rows;
	size_t		columns;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	t_color		f_color;
	t_color		c_color;
	t_2d_point	player_initial_pos;
	t_tile		player_initial_dir;
}	t_map_holder;

#endif