/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_background_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 16:22:49 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 13:17:54 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	mmp_draw_background(
	const t_int_2d_point *mmp_bottom_left, t_game *g
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
					px.x + mmp_bottom_left->x,
					px.y + mmp_bottom_left->y - MMP_HEIGHT + 1
				}
					),
				mmp_background_col
				);
			px.y += 1;
		}
		px.x += 1;
	}
}
