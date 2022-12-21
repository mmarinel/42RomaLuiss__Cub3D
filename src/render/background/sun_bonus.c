/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sun_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:51:32 by earendil          #+#    #+#             */
/*   Updated: 2022/12/21 23:57:06 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

static int		sun_set_offset(t_game *g);
static size_t	sun_get_frame(void);
static void		sun_draw_px(
	const t_int_2d_point *sun_frame_px,
	int col_offset,
	const t_data *sun_frame,
	t_game *g
	);
//*		end of static declarations

void	draw_sun(t_game *g)
{
	t_int_2d_point	sun_frame_px;
	size_t			frame;
	int				col_offset;

	if (
		(g->player.west_angle >= FOV && g->player.west_angle <= 2 * M_PI - FOV)
	)
		return ;
	frame = sun_get_frame();
	col_offset = sun_set_offset(g);
	sun_frame_px.x = 0;
	while (sun_frame_px.x < (int)g->textures.sun[frame].width)
	{
		sun_frame_px.y = 0;
		while (sun_frame_px.y < (float)g->textures.sun[frame].height)
		{
			sun_draw_px(&sun_frame_px, col_offset, &g->textures.sun[frame], g);
			sun_frame_px.y++;
		}
		sun_frame_px.x++;
	}
}

static int	sun_set_offset(t_game *g)
{
	return (roundf(
		west_axis_angle_to_px_shift(g) + west_middle_point_dist_to_px_shift(g)
		)
	);
}

static size_t	sun_get_frame(void)
{
	static size_t	clock = 0;
	static size_t	frame = 0;
	const size_t	refresh_rate = 3;

	clock = (clock + 1) % refresh_rate;
	if (0 == clock)
		frame = (frame + 1) % SUN_FRAMES;
	return (frame);
}

static void	sun_draw_px(
	const t_int_2d_point *sun_frame_px, int col_offset,
	const t_data *sun_frame,
	t_game *g
	)
{
	t_int_2d_point	screen_mapped_px;
	int				mlx_px;

	screen_mapped_px.x = sun_frame_px->x + col_offset;
	screen_mapped_px.y = sun_frame_px->y;
	mlx_px = get_texture_px(
		(t_int_2d_point){sun_frame_px->x, sun_frame_px->y},
		sun_frame
		);
	if (
		0 <= screen_mapped_px.x
		&& screen_mapped_px.x < (int)g->screen_handle.width
		)
		ft_put_mlxpx_to_image(
			&g->screen_handle.frame_data,
			ft_get_pixel_offset(&g->screen_handle.frame_data, screen_mapped_px),
			mlx_px
		);
}
