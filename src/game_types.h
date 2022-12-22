/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:40:51 by earendil          #+#    #+#             */
/*   Updated: 2022/12/22 18:43:48 by earendil         ###   ########.fr       */
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

typedef enum e_side
{
	e_HORIZONTAL,
	e_VERTICAL,
	e_SIDE_NONE
}	t_side;

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

# define ENEMIES_DEFAULT_COLLISION_RADIUS 2.0f

typedef struct s_enemy
{
	t_bool		alive;
	int			health;
	float		collision_radius;
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
	t_tile			type;
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


//****************************		RAYCAST		************************************************//

typedef enum e_ray_dir
{
	e_RAY_NORTH = 1,
	e_RAY_SOUTH = 0,
	e_RAY_EAST = 0,
	e_RAY_WEST = 1,
}	t_ray_dir;

typedef struct s_rc_ret_data
{
	t_2d_point		hit_point;//*	exact coordinate where we hit the square corresponding a wall
	t_int_2d_point	square;
	t_side			side;
	t_2d_point		ray;
	t_ray_dir		view_forw_direction;
	t_ray_dir		view_side_direction;
	float			euclidean_dist;
	float			perp_dist;
}	t_rc_ret_data;

typedef struct s_spotted_enemy
{
	t_enemy	*enemy;
	float	perp_dist;
}	t_spotted_enemy;

typedef struct s_spotted_door
{
	t_door			*door_ref;
	t_rc_ret_data	rc_data;
}	t_spotted_door;

typedef struct s_raycast_return
{
	t_rc_ret_data	wall;
	t_list			*doors;
	t_spotted_enemy	spotted_enemy;
}	t_raycast_return;

typedef struct s_raycast_data
{
	t_2d_point		ray;
	t_2d_point		ray_dir;
	float			delta_x;
	float			delta_y;
	int				step_x;
	int				step_y;
	t_int_2d_point	cur_sq;
	t_int_2d_point	prev_sq;
	float			dist_nhp_through_x;
	float			dist_nhp_through_y;
	t_spotted_enemy	spotted_enemy;
	t_list			*doors;
	t_side			side;
}	t_raycast_data;

#endif