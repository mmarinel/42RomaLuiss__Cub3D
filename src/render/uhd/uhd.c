/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uhd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:47:59 by earendil          #+#    #+#             */
/*   Updated: 2022/12/21 23:48:32 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	render_health_bar(t_game *g)
{
	const size_t		full = (g->screen_handle.width * 80.0f) / 100;
	const size_t		health = (full * g->player.hp) / 100.0f;
	const size_t		bar_height = 5;
	const size_t		horizontal_offset = (g->screen_handle.width * 10.0f) / 100;
	t_int_2d_point		px;

	px.y = 0;
	while (px.y < (int)bar_height)
	{
		px.x = 0;
		while (px.x < (int)health)
		{
			ft_put_px_to_image(
				&g->screen_handle.frame_data,
				ft_get_pixel_offset(
					&g->screen_handle.frame_data,
					(t_int_2d_point){px.x + horizontal_offset, px.y}
					),
				(t_color){255, 0, 0, 1}
			);
			px.x += 1;
		}
		px.y += 1;
	}
}

void	render_mana_bar(t_game *g)
{
	const size_t		full = (g->screen_handle.width * 50.0f) / 100.0f;
	const size_t		mana = (full * g->player.mana) / 100.0f;
	const size_t		bar_height = 5;
	const size_t		horizontal_offset = (g->screen_handle.width * 25.0f) / 100;
	const size_t		vertical_offset = 5 + 5;
	t_int_2d_point		px;

	px.y = 0;
	while (px.y < (int)bar_height)
	{
		px.x = 0;
		while (px.x < (int)mana)
		{
			ft_put_px_to_image(
				&g->screen_handle.frame_data,
				ft_get_pixel_offset(
					&g->screen_handle.frame_data,
					(t_int_2d_point){px.x + horizontal_offset, px.y + vertical_offset}
					),
				(t_color){0, 0, 255, 1}
			);
			px.x += 1;
		}
		px.y += 1;
	}
}
