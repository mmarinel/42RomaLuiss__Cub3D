/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:34:37 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 15:48:09 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rend_bonus.h"

static t_bool	renderable(
					t_rendered_entity *item_data, const size_t item_size
					);
static void		item_shift(t_rendered_entity *item_data);
static void		item_render_col(
					const size_t screen_col,
					const size_t resized_texture_col,
					const t_rendered_entity *item_data,
					t_game *g
					);
//*		end of static declarations

void	render_item(
	t_rendered_entity *item_data,
	t_game *g
	)
{
	const size_t	item_size = roundf(
			(g->screen_handle.height / item_data->min_perp_dist) / 2.0f
			);
	size_t			i;
	int				screen_col;

	if (e_false == renderable(item_data, item_size))
		return ;
	item_data->entity_size = item_size;
	item_shift(item_data);
	screen_col = item_data->mid_screen_col - (float)item_size / 2;
	i = 0;
	while (i < item_size)
	{
		if (screen_col >= 0 && screen_col < (int)g->screen_handle.width)
			item_render_col(screen_col, i, item_data, g);
		screen_col += 1;
		i += 1;
	}
}

static t_bool	renderable(
	t_rendered_entity *item_data, const size_t item_size
	)
{
	t_item	*item;

	if (e_ENT_ITEM != item_data->which)
		return (e_false);
	else
	{
		item = (t_item *)item_data->entity;
		return (
			e_false == item->picked
			&& item_size > 0
			&& item_size <= (
				item_data->last_screen_col - item_data->first_screen_col
			)
		);
	}
}

static void	item_shift(t_rendered_entity *item_data)
{
	const size_t	max_shift = item_data->entity_size / 4.0f;
	const size_t	unit_shift = max_shift / ITEM_ANIM_FRAME_STEP;
	t_item *const	item = (t_item *)item_data->entity;

	item->bouncing_clock = (
			(item->bouncing_clock + 1) % (ITEM_ANIM_FRAME_STEP + 1)
			);
	if (0 == item->bouncing_clock)
		item->anim_dir *= -1;
	item->cur_increment += (item->anim_dir);
	item->cur_shift = (item->cur_increment) * (int)unit_shift;
}

static void	item_render_col(
	const size_t screen_col,
	const size_t resized_texture_col,
	const t_rendered_entity *item_data,
	t_game *g
	)
{
	const t_column_info		col_info = get_item_column_info(
			resized_texture_col,
			item_data->entity_size,
			item_data->entity,
			g
			);
	t_int_2d_point			endpoint[2];

	endpoint[0] = (t_int_2d_point){
		screen_col,
		col_info.gap
	};
	endpoint[1] = (t_int_2d_point){
		screen_col,
		col_info.gap + (col_info.rendered_height - 1)
	};
	bresenham_plot(
		endpoint,
		&g->screen_handle.frame_data,
		nearest_neighbour, &(t_nxt_px_f_arg){&col_info, NULL}
		);
}
