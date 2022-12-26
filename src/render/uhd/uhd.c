/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uhd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:47:59 by earendil          #+#    #+#             */
/*   Updated: 2022/12/26 16:40:50 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

static void	render_bar(
	const t_int_2d_point *dimensions, const t_2d_point *offset,
	const t_color *bar_color,
	t_game *g
	);
//*		end of static declarations

void	render_health_bar(t_game *g)
{
	const size_t		full = (
		(g->screen_handle.width * 80.0f) / 100
		);
	const size_t		health = (full * g->player.hp) / 100.0f;
	const size_t		horizontal_offset = (
		g->screen_handle.width / 2 - health / 2
	);
	const t_color		health_bar_color = (t_color){255, 0, 0, 1};

	render_bar(
		&(t_int_2d_point){health, UHD_BAR_HEIGHT},
		&(t_2d_point){horizontal_offset, UHD_HP_VERT_OFFS},
		&health_bar_color,
		g
	);
}

void	render_mana_bar(t_game *g)
{
	const size_t		full = (
		(g->screen_handle.width * 50.0f) / 100.0f
		);
	const size_t		mana = (full * g->player.mana) / 100.0f;
	const size_t		horizontal_offset = (
		g->screen_handle.width / 2 - mana / 2
	);
	const t_color		mana_bar_color = (t_color){0, 0, 255, 1};

	render_bar(
		&(t_int_2d_point){mana, UHD_BAR_HEIGHT},
		&(t_2d_point){horizontal_offset, UHD_MANA_VERT_OFFS},
		&mana_bar_color,
		g
	);
}

void	render_items_bar(t_game *g)
{
	const size_t		full = (g->screen_handle.width * 32.0f) / 100.0f;
	const size_t		picked_bar_width = (
		(float)(full * g->player.picked_items) / g->player.tot_items
		);
	const size_t		horizontal_offset = (
		(g->screen_handle.width * 32.5f) / 100
		);
	const size_t		empty_bar_width = full - picked_bar_width;
	const t_color		picked_color = (t_color){252, 3, 219, 1};
	const t_color		empty_color = (t_color){126, 1, 109, 1};

	if (0 == g->player.tot_items)
		return ;
	render_bar(
		&(t_int_2d_point){picked_bar_width, UHD_BAR_HEIGHT},
		&(t_2d_point){horizontal_offset, UHD_ITEM_VERT_OFFS},
		&picked_color,
		g
	);
	render_bar(
		&(t_int_2d_point){empty_bar_width, UHD_BAR_HEIGHT},
		&(t_2d_point){horizontal_offset + picked_bar_width, UHD_ITEM_VERT_OFFS},
		&empty_color,
		g
	);
}

static void	render_bar(
	const t_int_2d_point *dimensions, const t_2d_point *offset,
	const t_color *bar_color,
	t_game *g
	)
{
	const size_t	width = dimensions->x;
	const size_t	height = dimensions->y;
	t_2d_point		px;

	if (0 == width || 0 == height)
		return ;
	px.y = 0;
	while (px.y < (int)height)
	{
		px.x = offset->x;
		while (px.x < offset->x + (int)width)
		{
			ft_put_px_to_image(
				&g->screen_handle.frame_data,
				ft_get_pixel_offset(
					&g->screen_handle.frame_data,
					(t_int_2d_point){px.x, px.y + offset->y}
					),
				*bar_color
			);
			px.x += 1;
		}
		px.y += 1;
	}
}
