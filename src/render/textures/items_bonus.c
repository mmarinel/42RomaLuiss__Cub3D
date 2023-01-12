/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:06:16 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 16:46:43 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

static void		set_scaling_factor(
					float *scaling_factor, const size_t item_size
					);
static t_data	*get_item_texture(t_game *g);
//*		end of static declarations

t_column_info	get_item_column_info(
	size_t resized_texture_col,
	size_t item_size,
	t_item *item,
	t_game *g
	)
{
	const float	gap = (
			((float)g->screen_handle.height - item_size) / 2.0f
			);
	float		scaling_factor;

	set_scaling_factor(&scaling_factor, item_size);
	return ((t_column_info){
		item_size,
		gap + item->cur_shift,
		get_item_texture(g),
		&g->\
		screen_handle.frame_data,
		resized_texture_col * scaling_factor,
		scaling_factor,
		e_false
	}
		);
}

static void	set_scaling_factor(float *scaling_factor, const size_t item_size)
{
	if (0 == item_size)
		*scaling_factor = INFINITY;
	else
		*scaling_factor = (float)get_textures_size() / item_size;
}

static t_data	*get_item_texture(t_game *g)
{
	return (&g->textures.item);
}
