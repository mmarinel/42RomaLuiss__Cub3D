/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:20:44 by earendil          #+#    #+#             */
/*   Updated: 2022/11/02 11:36:41 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <unistd.h>

# ifndef T_BOOL
#  define T_BOOL
typedef enum e_bool
{
	e_true = 1,
	e_false = 0
}	t_bool;
# endif

# ifndef T_COLOR
#  define T_COLOR
typedef struct s_color
{
	short	red;
	short	green;
	short	blue;
	double	alpha;
}	t_color;
# endif

typedef enum e_tile
{
	e_PLAYER_N = 'N',
	e_PLAYER_S = 'S',
	e_PLAYER_E = 'E',
	e_PLAYER_W = 'W',
	e_FLOOR = '0',
	e_WALL = '1',
	e_EMPTY
}	t_tile;

typedef struct s_map_holder
{
	t_tile	**map;
	size_t	rows;
	size_t	columns;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	t_color	f_color;
	t_color	c_color;
}	t_map_holder;

typedef struct s_game
{

	t_map_holder	map_handle;
	// t_vector		player_dir;
}	t_game;

#endif