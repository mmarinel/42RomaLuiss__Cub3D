/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:20:44 by earendil          #+#    #+#             */
/*   Updated: 2023/01/07 11:49:03 by earendil         ###   ########.fr       */
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