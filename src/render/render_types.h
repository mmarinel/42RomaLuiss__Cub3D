/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:28:34 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/14 23:58:21 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_TYPES_H
# define RENDER_TYPES_H

# include "../types.h"
# include "../raycast/raycast_types.h"

typedef enum e_reentrancy
{
	e_INGOING,
	e_OUTGOING,
	e_REENTRANCY_NONE
}	t_reentrancy;

typedef struct s_wall_camera_incidence
{
	float			angle;
	t_side			side;
	t_quadrant		player_dir_quadrant;
	t_reentrancy	reentrancy;
}	t_wall_camera_incidence;

/**
 * @brief an enemy is spotted multiple times as we send many rays for each tile.
 * To render an enemy, we take the column of the screen that gives the
 * ray which in turn gives the shortest perp distance, and for this column
 * we draw [rendered width / 2] on the left
 * and [rendered width / 2] on the right.
 * 
 */
typedef struct s_rendered_enemy
{
	const t_enemy	*enemy;
	size_t			mid_screen_col;
	size_t			first_screen_col;//*column of the first ray to hit the enemy
	size_t			last_screen_col;//*column of the last ray to hit the enemy
	float			min_perp_dist;
	size_t			enemy_size;
}	t_rendered_enemy;

typedef struct s_render_data
{
	const t_raycast_return			rc_ret;
	const size_t					wll_px_width;
	const size_t					wll_px_height;
	const size_t					wll_out_bounds_pxs;
	const t_wall_camera_incidence	wall_camera_incidence;
}	t_render_data;

typedef struct s_column_info
{
	// const t_2d_point		*frame_px;
	const size_t			rendered_size;
	const size_t			gap;
	const t_raycast_return	*rc_ret;
	const t_data			*texture;
	t_data					*frame;
	const size_t			texture_column;
	const float				scaling_factor;
	const t_bool			draw_shadow;
}	t_column_info;

typedef struct s_nxt_px_f_arg
{
	const void		*arg;
	t_int_2d_point	*cur_px;
}	t_nxt_px_f_arg;

typedef int(*t_next_pixel_f)(t_nxt_px_f_arg *);

#endif