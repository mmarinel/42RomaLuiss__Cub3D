/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:28:34 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/08 17:15:45 by mmarinel         ###   ########.fr       */
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
	const size_t			wall_size;
	const size_t			gap;
	const t_raycast_return	*rc_ret;
	const t_data			*texture;
	t_data					*frame;
	const size_t			texture_column;
	const float				scaling_factor;
}	t_column_info;

typedef struct s_nxt_px_f_arg
{
	const void		*arg;
	t_int_2d_point	*cur_px;
}	t_nxt_px_f_arg;

typedef int(*t_next_pixel_f)(t_nxt_px_f_arg *);

#endif