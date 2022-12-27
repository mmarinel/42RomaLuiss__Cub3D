/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:36:03 by earendil          #+#    #+#             */
/*   Updated: 2022/12/27 21:11:01 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

static void	mmp_draw_border(
	const t_int_2d_point *mmp_start, t_game *g
	);
static void	mmp_draw_background(
	const t_int_2d_point *mmp_start, t_game *g
	);
static void	mmp_draw_map(
	const t_int_2d_point *mmp_start, t_game *g
	);
//*		end of static declarations

void	render_minimap(t_game *g)
{
	const t_int_2d_point	mmp_start = (t_int_2d_point){
		g->screen_handle.width / MMP_OFFSET,
		g->screen_handle.height - g->screen_handle.height / MMP_OFFSET
	};
	
	mmp_draw_border(&mmp_start, g);
	mmp_draw_background(&mmp_start, g);
	mmp_draw_map(&mmp_start, g);
}

static void	mmp_draw_border(
	const t_int_2d_point *mmp_start, t_game *g
	)
{
	mmp_border_draw_horizontal_frames(mmp_start, g);
	mmp_border_draw_vertical_frames(mmp_start, g);
}

static void	mmp_draw_background(
	const t_int_2d_point *mmp_start, t_game *g
	)
{
	const t_color	mmp_background_col = (t_color){100, 104, 227, 1};
	t_int_2d_point	px;

	px.x = 0;
	while (px.x < MMP_WIDTH)
	{
		px.y = 0;
		while (px.y < MMP_HEIGHT)
		{
			ft_put_px_to_image(
				&g->screen_handle.frame_data,
				ft_get_pixel_offset(
					&g->screen_handle.frame_data,
					(t_int_2d_point){
						px.x + mmp_start->x,
						px.y + mmp_start->y - MMP_HEIGHT + 1}
					),
				mmp_background_col
			);
			px.y += 1;
		}
		px.x += 1;
	}
}

static void	mmp_draw_map(
	const t_int_2d_point *mmp_start, t_game *g
	)
{
	const t_int_2d_point	top_left_corner = (t_int_2d_point){
		mmp_start->x,
		mmp_start->y - MMP_HEIGHT + 1
	};
	const t_int_2d_point	player_mmp_px = (t_int_2d_point){
		mmp_start->x + ((MMP_WIDTH / MMP_TILE_WIDTH) / 2) * MMP_TILE_WIDTH,
		mmp_start->y - ((MMP_HEIGHT / MMP_TILE_WIDTH) / 2) * MMP_TILE_WIDTH,
	};
	t_int_2d_point			mmp_px;

	mmp_px.x = top_left_corner.x;
	while (mmp_px.x < top_left_corner.x + MMP_WIDTH)
	{
		mmp_px.y = top_left_corner.y;
		while (mmp_px.y < top_left_corner.y + MMP_HEIGHT)
		{
			mmp_draw_tile(&mmp_px, &player_mmp_px, g);
			mmp_px.y += 1;
		}
		mmp_px.x += 1;
	}
}
