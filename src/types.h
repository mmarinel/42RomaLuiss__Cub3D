/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:20:44 by earendil          #+#    #+#             */
/*   Updated: 2022/11/13 14:49:49 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <unistd.h>
# include <limits.h>

# ifndef T_BOOL
#  define T_BOOL

typedef enum e_bool
{
	e_true = 1,
	e_false = 0
}	t_bool;
# endif

typedef enum e_quadrant
{
	e_FIRST_QUADRANT,
	e_SECOND_QUADRANT,
	e_THIRD_QUADRANT,
	e_FOURTH_QUADRANT
}	t_quadrant;

typedef struct s_2Dpoint
{
	float	x;
	float	y;
}	t_2d_point;

typedef struct s_2Dmatrix
{
	t_2d_point	row_1;
	t_2d_point	row_2;
}	t_2d_matrix;

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

typedef struct s_screen_holder
{
	size_t	width;
	size_t	wheight;
}	t_screen_holder;

typedef struct s_camera_plane
{
	t_2d_point	versor;
	float		angle_from_x_axis;
	float		angle_from_y_axis;
}	t_camera_plane;

typedef struct s_game
{
	t_map_holder			map_handle;
	t_screen_holder			screen_handle;
	t_2d_point				player_dir;
	t_2d_point				player_pos;
	t_camera_plane			camera_plane;
}	t_game;
/**
 * fields:
 * 			1) t_vector		player_dir;
 * 
 */

#endif