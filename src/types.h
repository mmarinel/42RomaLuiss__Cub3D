/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:20:44 by earendil          #+#    #+#             */
/*   Updated: 2022/12/15 17:32:24 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <unistd.h>
# include <limits.h>
# include "utils/libft/libft_module.h"

# define FLT_PRECISION 6

//*		X11		Events & events Masks

//		events
//* 	Event names.  Used in "type" field in XEvent structures.  Not to be
//* 	confused with event masks below.  They start from 2 because 0 and 1
//* 	are reserved in the protocol for errors and replies.
//
#define KeyPress			2
#define KeyRelease			3
#define ButtonPress			4
#define ButtonRelease		5
#define MotionNotify		6
#define EnterNotify			7
#define LeaveNotify			8
#define FocusIn				9
#define FocusOut			10
#define KeymapNotify		11
#define Expose				12
#define GraphicsExpose		13
#define NoExpose			14
#define VisibilityNotify	15
#define CreateNotify		16
#define DestroyNotify		17
#define UnmapNotify			18
#define MapNotify			19
#define MapRequest			20
#define ReparentNotify		21
#define ConfigureNotify		22
#define ConfigureRequest	23
#define GravityNotify		24
#define ResizeRequest		25
#define CirculateNotify		26
#define CirculateRequest	27
#define PropertyNotify		28
#define SelectionClear		29
#define SelectionRequest	30
#define SelectionNotify		31
#define ColormapNotify		32
#define ClientMessage		33
#define MappingNotify		34
#define GenericEvent		35
#define LASTEvent			36	/* must be bigger than any event # */

//		masks
//*		Input Event Masks. Used as event-mask window attribute and as arguments
//*		to Grab requests.  Not to be confused with event names.
//
#define NoEventMask					0L
#define KeyPressMask				(1L<<0)
#define KeyReleaseMask				(1L<<1)
#define ButtonPressMask				(1L<<2)
#define ButtonReleaseMask			(1L<<3)
#define EnterWindowMask				(1L<<4)
#define LeaveWindowMask				(1L<<5)
#define PointerMotionMask			(1L<<6)
#define PointerMotionHintMask		(1L<<7)
#define Button1MotionMask			(1L<<8)
#define Button2MotionMask			(1L<<9)
#define Button3MotionMask			(1L<<10)
#define Button4MotionMask			(1L<<11)
#define Button5MotionMask			(1L<<12)
#define ButtonMotionMask			(1L<<13)
#define KeymapStateMask				(1L<<14)
#define ExposureMask				(1L<<15)
#define VisibilityChangeMask		(1L<<16)
#define StructureNotifyMask			(1L<<17)
#define ResizeRedirectMask			(1L<<18)
#define SubstructureNotifyMask		(1L<<19)
#define SubstructureRedirectMask	(1L<<20)
#define FocusChangeMask				(1L<<21)
#define PropertyChangeMask			(1L<<22)
#define ColormapChangeMask			(1L<<23)
#define OwnerGrabButtonMask			(1L<<24)


# ifndef T_BOOL
#  define T_BOOL

typedef enum e_bool
{
	e_true = 1,
	e_false = 0
}	t_bool;
# endif

typedef enum e_key
{
	e_UP_KEY = 65362,
	e_DOWN_KEY = 65364,
	e_RIGHT_KEY = 65363,
	e_LEFT_KEY = 65361,
	e_W_KEY = -1,
	e_A_KEY = -1,
	e_S_KEY = -1,
	e_D_KEY = -1,
	e_E_KEY = -1,
	e_Q_KEY = -1,
	e_SPACE_KEY = 32,
	e_TAB_KEY = -1,
	e_CTRL_KEY = -1,
	e_CMD_KEY = -1,
}	t_key;

typedef enum e_quadrant
{
	e_FIRST_QUADRANT,
	e_SECOND_QUADRANT,
	e_THIRD_QUADRANT,
	e_FOURTH_QUADRANT
}	t_quadrant;

# define COLOR_MIN 0
# define COLOR_MAX 255

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_data;

typedef struct s_int_2Dpoint
{
	int	x;
	int	y;
}	t_int_2d_point;

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
	int	red;
	int	green;
	int	blue;
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
	e_EMPTY = '?',
}	t_tile;

typedef struct s_map_holder
{
	t_2d_point	player_initial_pos;
	t_tile		player_initial_dir;
	t_tile		**map;
	size_t		rows;
	size_t		columns;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	t_color		f_color;
	t_color		c_color;
}	t_map_holder;

typedef struct s_screen_holder
{
	void	*mlx;
	void	*window;
	t_data	frame_data;
	t_data	*textures_data;
	// int		textures_size;
	size_t	width;
	size_t	height;
}	t_screen_holder;

typedef struct s_wall_texture {
	t_data	north;
	t_data	south;
	t_data	west;
	t_data	east;
}	t_wall_texture;

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

# define SUN_FRAMES 19
# define ENEMY_DIE_ANIM_FRAMES 48

typedef struct s_enemy
{
	t_bool			alive;
	int				health;
	t_2d_point		pos;
	size_t			die_anim_frames;//TODO fare una funzione che crea i nemici che setta valore default
}	t_enemy;

typedef struct s_game
{
	t_bool					in_game;
	t_bool					alive;
	t_bool					attacking;
	t_bool					colliding;
	size_t					player_hp;
	size_t					player_mana;
	t_map_holder			map_handle;
	t_key_state				keys[BOUND_KEYS];
	t_screen_holder			screen_handle;
	t_wall_texture			wall_texture;
	t_data					background;
	t_data					sun[SUN_FRAMES];
	t_data					enemy_texture[2];
	t_list					*enemies;
	// t_enemy			enemy
	t_2d_point				player_dir;
	t_2d_point				player_pos;
	t_2d_point				camera_plane;
}	t_game;
/**
 * fields:
 * 			1) t_vector		player_dir;
 * 
 */

#endif