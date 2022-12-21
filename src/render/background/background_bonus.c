/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:50:24 by earendil          #+#    #+#             */
/*   Updated: 2022/12/21 23:50:38 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	draw_background_bonus(t_game *g)
{
	t_int_2d_point	screen_px;

	screen_px.x = 0;
	while (screen_px.x < (int)g->screen_handle.frame_data.width)
	{
		screen_px.y = 0;
		while (screen_px.y < (int)g->screen_handle.frame_data.height)
		{
			ft_put_mlxpx_to_image(
				&g->screen_handle.frame_data,
				ft_get_pixel_offset(&g->screen_handle.frame_data, screen_px),
				get_texture_px(screen_px, &g->textures.background)
			);
			screen_px.y++;
		}
		screen_px.x++;
	}
}
