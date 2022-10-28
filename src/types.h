/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:20:44 by earendil          #+#    #+#             */
/*   Updated: 2022/10/28 08:42:10 by mmarinel         ###   ########.fr       */
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

typedef enum e_tile
{
	e_FLOOR,
	e_WALL,
	e_EMPTY
}	t_tile;

typedef struct s_map_holder
{
	t_tile	**map;
	size_t	size;
}	t_map_holder;

#endif