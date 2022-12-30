/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:07:53 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 14:14:25 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uti_render.h"

t_int_2d_point	mmp_px_clip(
	const t_int_2d_point *bottom_left,
	const t_int_2d_point *mmp_px
	)
{
	t_int_2d_point	clipped = *mmp_px;

	if (clipped.x < bottom_left->x)
		clipped.x = bottom_left->x;
	else if (clipped.x >= bottom_left->x + MMP_WIDTH)
		clipped.x = bottom_left->x + MMP_WIDTH - 1;

	if (clipped.y < bottom_left->y - MMP_HEIGHT + 1)
		clipped.y = bottom_left->y - MMP_HEIGHT + 1;
	else if (clipped.y > bottom_left->y)
		clipped.y = bottom_left->y;

	return (clipped);
}

t_int_2d_point	mmp_get_map_pos(
	const t_int_2d_point *mmp_px,
	const t_int_2d_point *player_mmp_px,
	t_game *g
	)
{
	const t_int_2d_point	player_map_pos = as_int_2dpt(&g->player.pos);
	const t_2d_point		pos = map_pos_clip(
		(t_2d_point){
			(
				(float)(mmp_px->x - player_mmp_px->x) / MMP_TILE_WIDTH
					+ player_map_pos.x
			),
			(
				(float)(mmp_px->y - player_mmp_px->y) / MMP_TILE_WIDTH
					+ player_map_pos.y
			)
		},
		g
	);

	return (as_int_2dpt(&pos));
}
