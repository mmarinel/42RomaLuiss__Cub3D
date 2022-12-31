/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:20:44 by earendil          #+#    #+#             */
/*   Updated: 2022/12/31 13:09:26 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "macros.h"
# include "X11_macros.h"

# include "utils/libft/libft_module.h"

# include "sys_includes.h"

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
	e_W_KEY = 119,
	e_A_KEY = 97,
	e_S_KEY = 115,
	e_D_KEY = 100,
	e_E_KEY = 101,
	e_Q_KEY = 113,
	e_SPACE_KEY = 32,
	e_ENTER_KEY = 65293,
	e_ESC_KEY = 65307,
	e_TAB_KEY = -1,
	e_CTRL_KEY = -1,
	e_CMD_KEY = -1,
}	t_key;

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

# define COLOR_MIN 0
# define COLOR_MAX 255

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

#endif