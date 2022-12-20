/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:40:51 by earendil          #+#    #+#             */
/*   Updated: 2022/12/20 19:50:34 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_TYPES_H
# define GAME_TYPES_H

# include "types.h"
# include "utils/math/uti_math_types.h"
# include "map_validation/map_validation_types.h"

typedef struct s_screen_holder
{
	void	*mlx;
	void	*window;
	t_data	frame_data;
	size_t	width;
	size_t	height;
}	t_screen_holder;

typedef struct s_wall_texture {
	t_data	north;
	t_data	south;
	t_data	west;
	t_data	east;
}	t_wall_texture;

typedef struct s_door_texture {
	t_data	open;
	t_data	ajar;
	t_data	closed;
}	t_door_texture;

typedef struct s_key_state
{
	t_key	key;
	int		state;
}	t_key_state;

# define BOUND_KEYS 14

# define W_INDEX 0
# define A_INDEX 1
# define S_INDEX 2
# define D_INDEX 3
# define UP_INDEX 4
# define DOWN_INDEX 5
# define RIGHT_INDEX 6
# define LEFT_INDEX 7
# define SPACE_INDEX 8
# define E_INDEX 9

typedef struct s_enemy
{
	t_bool		alive;
	int			health;
	t_2d_point	pos;
	size_t		die_anim_frames;
}	t_enemy;

typedef enum e_door_status
{
	e_DOOR_OPEN = 0,
	e_DOOR_CLOSED = 1,
	e_DOOR_AJAR = 2,
}	t_door_status;

typedef struct s_door
{
	t_door_status	status;
	t_door_status	prev_status;
	t_int_2d_point	pos;
	int				opening_delay_frames;
}	t_door;

typedef struct s_player
{
	t_bool		alive;
	size_t		hp;
	size_t		mana;
	t_bool		attacking;
	t_bool		colliding;
	float		west_angle;
	t_2d_point	pos;
	t_2d_point	dir;
	t_2d_point	camera_plane;
}	t_player;

typedef struct s_game_texture
{
	t_wall_texture	wall;
	t_door_texture	door;
	t_data			background;
	t_data			sun[SUN_FRAMES];
	t_data			enemy[2];
}	t_game_texture;

typedef struct s_game
{
	t_bool			in_game;
	t_bool			in_menu;
	t_player		player;
	t_list			*enemies;
	t_list			*doors;
	t_map_holder	map_handle;
	t_screen_holder	screen_handle;
	t_game_texture	textures;
	t_key_state		keys[BOUND_KEYS];
	float			unit_rot_angle;
}	t_game;

#endif