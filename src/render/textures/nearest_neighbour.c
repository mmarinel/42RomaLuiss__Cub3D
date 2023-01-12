/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest_neighbour.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:33:15 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 15:55:55 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

static t_int_2d_point	nn_map_px(
							const t_column_info *col_info,
							const t_int_2d_point *cur_px
							);
static int				nn_map_px_row(float y_mapping);
//*		end of static declarations

int	nearest_neighbour(t_nxt_px_f_arg *nxt_px_f_arg)
{
	t_column_info	*col_info;
	t_int_2d_point	original_texture_px;

	col_info = (t_column_info *)nxt_px_f_arg->arg;
	original_texture_px = nn_map_px(col_info, nxt_px_f_arg->cur_px);
	if (
		original_texture_px.y == (int)get_textures_size() - 1
		&& col_info->draw_shadow
	)
		return (0);
	else
		return (
			get_texture_px(
				original_texture_px,
				col_info->texture
			)
		);
}

size_t	get_texture_column(const t_rc_ret_data *rc_ret_data)
{
	double			dist;
	const size_t	texture_size = get_textures_size();

	if (e_VERTICAL == rc_ret_data->side)
		dist = rc_ret_data->hit_point.y - rc_ret_data->square.y;
	else if (e_HORIZONTAL == rc_ret_data->side)
		dist = rc_ret_data->hit_point.x - rc_ret_data->square.x;
	else
		return (-1);
	return (textures_pt_clip(roundl(dist * (double)texture_size)));
}

static int	nn_map_px_row(float y_mapping)
{
	if (y_mapping - floor(y_mapping) < 0.5f)
		return (textures_pt_clip(floor(y_mapping)));
	else
		return (textures_pt_clip(ceil(y_mapping)));
}

static t_int_2d_point	nn_map_px(
	const t_column_info *col_info,
	const t_int_2d_point *cur_px
	)
{
	t_int_2d_point	original_texture_px;
	size_t			resized_texture_row;

	resized_texture_row = cur_px->y - col_info->gap;
	original_texture_px.x = col_info->texture_column;
	original_texture_px.y = nn_map_px_row(
			col_info->vertical_scaling_factor * resized_texture_row
			);
	return (original_texture_px);
}
