/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_types.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:40:51 by earendil          #+#    #+#             */
/*   Updated: 2023/01/14 10:58:02 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_TYPES_H
# define GAME_TYPES_H

# include "basic_types.h"
# include "../utils/math/uti_math_types.h"
# include "../map_validation/map_validation_types.h"

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

typedef struct s_game_textures
{
	t_wall_texture	wall;
	t_door_texture	door;
	t_data			background;
	t_data			sun[SUN_FRAMES];
	t_data			enemy[2];
	t_data			item;
	t_data			menu[2];
	t_data			game_over[2];
	t_data			game_win[2];
}	t_game_textures;

typedef struct s_menu
{
	t_bool			in_initial_menu;
	t_bool			in_end_menu;
	int				menu_screen;
	t_int_2d_point	newg_btn_top_left;
	t_int_2d_point	newg_btn_bottom_right;
	t_int_2d_point	exit_btn_top_left;
	t_int_2d_point	exit_btn_bottom_right;
}	t_menu;

typedef struct s_screen_holder
{
	void	*mlx;
	void	*window;
	t_data	frame_data;
	size_t	width;
	size_t	height;
}	t_screen_holder;

typedef enum e_key
{
	e_UP_KEY = 126,
	e_DOWN_KEY = 125,
	e_RIGHT_KEY = 124,
	e_LEFT_KEY = 123,
	e_W_KEY = 13,
	e_A_KEY = 0,
	e_S_KEY = 1,
	e_D_KEY = 2,
	e_E_KEY = 14,
	e_SPACE_KEY = 49,
	e_ENTER_KEY = 36,
	e_ESC_KEY = 53,
	e_SHIFT_KEY = 257,
}	t_key;

typedef struct s_key_state
{
	t_key	code;
	int		state;
}	t_key_state;

typedef struct s_key_state_map
{
	t_key_state		keys[BOUND_KEYS];
}	t_key_state_map;

typedef struct s_enemy
{
	t_bool		alive;
	int			health;
	float		collision_radius;
	float		step_size;
	t_2d_point	pos;
	size_t		die_anim_frames;
}	t_enemy;

typedef struct s_item
{
	t_bool		picked;
	t_2d_point	pos;
	int			anim_dir;
	int			cur_increment;
	int			cur_shift;
	int			bouncing_clock;
}	t_item;

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
	size_t		attack_damage;
	float		attack_range;
	float		action_range;
	float		step_size;
	float		step_ampl;
	float		acceleration;
	t_bool		attacking;
	t_bool		running;
	t_bool		enemy_colliding;
	float		west_angle;
	size_t		tot_items;
	size_t		picked_items;
	t_2d_point	pos;
	t_2d_point	dir;
	t_2d_point	camera_plane;
}	t_player;

typedef struct s_game
{
	char			*lvls[LEVELS];
	char			*cur_lvl;
	t_bool			mouse_clicked;
	t_bool			in_focus;
	t_player		player;
	t_list			*enemies;
	t_list			*doors;
	t_list			*items;
	t_menu			menu;
	t_map_holder	map_handle;
	t_screen_holder	screen_handle;
	t_game_textures	textures;
	t_key_state_map	key_map;
	float			unit_rot_angle;
}	t_game;

#endif