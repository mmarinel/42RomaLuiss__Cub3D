/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   attack_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:43:27 by earendil          #+#    #+#             */
/*   Updated: 2022/12/23 17:13:58 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

static void	draw_laser(
	const t_int_2d_point *endpoint,
	const size_t offset,
	const t_color *laser_color,
	t_game *g
	);
static int	attack_next_px(t_nxt_px_f_arg *arg);
//*end of static declarations

void	render_attack(t_game *g)
{
	const t_int_2d_point	endpoint[2] = {
		(t_int_2d_point){
			g->screen_handle.width / 2.0f,
			g->screen_handle.height / 2.0f
		},
		(t_int_2d_point){
			g->screen_handle.width / 2.0f,
			g->screen_handle.height
		}
	};
	const t_color	laser_color = (t_color){222, 33, 65, 1};
	const size_t	base_width = (g->screen_handle.width * .5f) / 100;
	size_t			i;

	i = 0;
	while (i < 100)
	{
		draw_laser(
			endpoint, ((base_width / 50.0f) * i) - base_width, &laser_color, g
		);
		i += 1;
	}
}

void	render_collision(t_game *g)
{
	t_int_2d_point	px;

	if (g->player.enemy_colliding)
	{
		px.y = 0;
		while (px.y < (int)g->screen_handle.height)
		{
			px.x = 0;
			while (px.x < (int)g->screen_handle.width)
			{
				if ((px.x + px.y) % 2)
					ft_put_px_to_image(
						&g->screen_handle.frame_data,
						ft_get_pixel_offset(&g->screen_handle.frame_data, px),
						(t_color){255, 0, 0, 1}
					);
				px.x += 1;
			}
			px.y += 1;
		}
	}
}

static void	draw_laser(
	const t_int_2d_point *endpoint,
	const size_t offset,
	const t_color *laser_color,
	t_game *g
	)
{
	bresenham_plot(
		(t_int_2d_point[2]){
			(t_int_2d_point){
				endpoint[0].x + offset,
				endpoint[0].y
			},
			(t_int_2d_point){
				endpoint[1].x,
				endpoint[1].y
			}
		},
		&g->screen_handle.frame_data,
		attack_next_px, &(t_nxt_px_f_arg){laser_color, NULL}
	);
}

static int	attack_next_px(t_nxt_px_f_arg *arg)
{
	const t_color	color = *(const t_color *)arg->arg;

	return (ft_get_mlx_color(color));
}
