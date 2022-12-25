/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 00:34:37 by earendil          #+#    #+#             */
/*   Updated: 2022/12/25 01:42:49 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rend_bonus.h"

static void	render_item(
	t_rendered_item *item_data,
	t_game *g
	);
static void	item_shift(t_item *item);
static void	item_render_col(
	const size_t screen_col,
	const size_t resized_texture_col,
	const t_rendered_item *item_data,
	t_game *g
	);
//*		end of static declarations

void	render_items(
	t_list *items,
	t_game *g
	)
{
	t_list			*cur;
	t_rendered_item	*spotted_item;

	cur = items;
	while (cur)
	{
		spotted_item = (t_rendered_item *)cur->content;
		if (spotted_item->item
			&& is_traversable_pos(g, &spotted_item->item->pos, &g->player.pos))
			render_item(spotted_item, g);
		cur = cur->next;
	}
}

static void	render_item(
	t_rendered_item *item_data,
	t_game *g
	)
{
	const size_t	item_size = roundf(
		(g->screen_handle.height / item_data->min_perp_dist) / 2.0f
	);
	size_t			i;
	int				screen_col;

	if (0 == item_size || item_data->item->picked)
		return ;
	item_data->item_size = item_size;
	screen_col = item_data->mid_screen_col;
	item_shift(item_data->item);
	i = 0;
	while (i < item_size)
	{
		if (screen_col >= 0 && screen_col < (int)g->screen_handle.width)//TODO	"<" anche in render enemy !!!!!
			item_render_col(screen_col, i, item_data, g);
		screen_col += 1;
		i += 1;
	}
}

static void	item_shift(t_item *item)
{
	if (ft_flt_abs(item->cur_shift) >= ITEM_BOUNCING_MAX_SHIFT)
		item->anim_dir *= (-1);
	item->cur_shift += (
		(item->anim_dir) * item->bouncing_px_shift
		);
}

static void	item_render_col(
	const size_t screen_col,
	const size_t resized_texture_col,
	const t_rendered_item *item_data,
	t_game *g
	)
{
	const t_column_info		col_info = get_item_column_info(
		resized_texture_col,
		item_data->item_size,
		item_data->item,
		g
	);
	t_int_2d_point	endpoint[2];
	
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
