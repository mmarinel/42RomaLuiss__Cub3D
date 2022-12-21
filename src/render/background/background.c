/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:43:07 by earendil          #+#    #+#             */
/*   Updated: 2022/12/21 23:45:54 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

static int	background_next_pixel(t_nxt_px_f_arg *nxt_px_f_arg);
//*		end of static declarations

void	draw_background(t_game *g)
{
	const size_t	horizon = floor((float)g->screen_handle.height / 2);
	t_int_2d_point	vertices[2];
	t_nxt_px_f_arg	nxt_px_f_arg;
	const int		c_color = ft_get_mlx_color(g->map_handle.c_color);
	const int		f_color = ft_get_mlx_color(g->map_handle.f_color);

	vertices[0] = (t_int_2d_point){0, 0};
	vertices[1] = (t_int_2d_point){g->screen_handle.width - 1, 0};
	while (vertices[0].y < (int)g->screen_handle.height)
	{
		if (vertices[0].y >= (int)horizon)
			nxt_px_f_arg.arg = &f_color;
		else
			nxt_px_f_arg.arg = &c_color;
		bresenham_plot(vertices,
			&g->screen_handle.frame_data,
			background_next_pixel, &nxt_px_f_arg
			);
		vertices[0].y += 1;
		vertices[1].y += 1;
	}
}

static int	background_next_pixel(t_nxt_px_f_arg *nxt_px_f_arg)
{
	int	mlx_color;

	mlx_color = *((const int *)nxt_px_f_arg->arg);
	return (mlx_color);
}
