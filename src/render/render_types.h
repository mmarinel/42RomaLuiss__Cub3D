/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:28:34 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/12 16:36:24 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_TYPES_H
# define RENDER_TYPES_H

# include "../includes/basic_types.h"
# include "../includes/game_types.h"
# include "../raycast/raycast_types.h"
# include "../utils/math/uti_math_types.h"

typedef enum e_entity
{
	e_ENT_DOOR,
	e_ENT_ENEMY,
	e_ENT_ITEM,
}	t_entity;

/**
 * @brief an entity (enemy or item) is spotted multiple times
 * as we send many rays for each tile.
 * To render an entity, we take the column of the screen that gives the
 * ray which in turn gives the shortest perp distance, and for this column
 * we draw [rendered width / 2] on the left
 * and [rendered width / 2] on the right.
 * 
 */
typedef struct s_rendered_entity
{
	void		*entity;
	t_entity	which;
	size_t		entity_size;
	float		min_perp_dist;
	size_t		mid_screen_col;
	size_t		first_screen_col;
	size_t		last_screen_col;
}	t_rendered_entity;

typedef struct s_column_info
{
	const size_t			rendered_height;
	const size_t			gap;
	const t_data			*texture;
	t_data					*frame;
	const size_t			texture_column;
	const float				vertical_scaling_factor;
	const t_bool			draw_shadow;
}	t_column_info;

typedef struct s_nxt_px_f_arg
{
	const void		*arg;
	t_int_2d_point	*cur_px;
}	t_nxt_px_f_arg;

typedef int(*t_next_pixel_f)(t_nxt_px_f_arg *);

#endif