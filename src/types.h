/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:20:44 by earendil          #+#    #+#             */
/*   Updated: 2022/11/10 17:24:42 by mmarinel         ###   ########.fr       */
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

typedef struct s_dbl
{
	double	val;
	t_bool	inf;
	t_bool	neg_inf;
}	t_dbl;

typedef struct s_fixed		t_fixed;
typedef struct s_fixed_val	t_fixed_val;

typedef enum e_fixed_frac_bits
{
	e_FRAC_BITS = 8,
}	t_fixed_frac_bits;

//*		conversions
typedef struct s_fixed_to_dbl_closure
{
	t_fixed_val	val;
	double(*call)(struct s_fixed this);
}	t_fixed_to_dbl;

typedef struct s_fixed_to_int_closure
{
	t_fixed_val	val;
	int(*call)(struct s_fixed this);
}	t_fixed_to_int;

//*		arithmetic
typedef struct s_fixed_sum_closure
{
	t_fixed_val	val;
	t_fixed(*call)(struct s_fixed this, struct s_fixed val);
}	t_fixed_sum;

typedef struct s_fixed_diff_closure
{
	t_fixed_val	val;
	t_fixed(*call)(struct s_fixed this, struct s_fixed val);
}	t_fixed_diff;

typedef struct s_fixed_mult_closure
{
	t_fixed_val	val;
	t_fixed(*call)(struct s_fixed this, struct s_fixed val);
}	t_fixed_mult;

typedef struct s_fixed_div_closure
{
	t_fixed_val	val;
	t_fixed(*call)(struct s_fixed this, struct s_fixed val);
}	t_fixed_div;

typedef struct s_fixed_cmp_closure
{
	t_fixed_val	val;
	double(*call)(struct s_fixed this, struct s_fixed val);
}	t_fixed_cmp;

typedef struct s_fixed_print_closure
{
	t_fixed_val	val;
	void(*call)(struct s_fixed this);
}	t_fixed_print;

struct s_fixed
{
	t_fixed_val		fixed_val;
	t_fixed_to_dbl	to_double;
	t_fixed_to_int	to_int;
	t_fixed_sum		sum;
	t_fixed_diff	diff;
	t_fixed_mult	mult;
	t_fixed_div		div;
	t_fixed_cmp		cmp;
	t_fixed_print	print;
};

struct s_fixed_val
{
	int32_t				row_bits;
	t_fixed_frac_bits	frac_bits;
	t_bool				inf;
	t_bool				neg_inf;
};

typedef struct s_2Dpoint
{
	t_dbl	x;
	t_dbl	y;
}	t_2d_point;

typedef struct s_2Dmatrix
{
	t_2d_point	col_1;
	t_2d_point	col_2;
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

typedef struct s_game
{
	t_map_holder	map_handle;
	t_2d_point		player_dir;
	t_2d_point		player_pos;
	t_2d_point		camera_plane;
}	t_game;
/**
 * fields:
 * 			1) t_vector		player_dir;
 * 
 */

#endif