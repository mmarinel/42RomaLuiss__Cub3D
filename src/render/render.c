/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 09:35:01 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/13 10:51:00 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static size_t	render_region(t_game *g, float cur_ray_angle);
static float	wall_camera_angle(t_camera_plane cp, t_side side);
static void		render_wall(const size_t wll_px_width, const size_t wll_px_height,
					const size_t wll_px_offset, const float wll_cam_angle);
//*		end of static declarations

void	render(t_game *g)
{
	const float	fov_half = M_PI / 6;//* 60 / 2 = (π / 3) / 2
	const float	angle_step_size = fov_half / g->screen_handle.width;
	float		cur_ray_angle;
	float		hit_wall_px_width;

	cur_ray_angle = M_PI / 2 - fov_half;
	while (cur_ray_angle < M_PI / 2 + fov_half)
	{
		hit_wall_px_width = render_region(g, cur_ray_angle);
		cur_ray_angle += hit_wall_px_width * angle_step_size;
	}
}

/**
 * @brief 
 * 
 * @param g 
 * @param cur_ray_angle angle the ray forms with the camera plane
 * @return size_t 
 */
static size_t	render_region(t_game *g, float cur_ray_angle)
{
	const t_raycast_return	rc_ret
		= raycast(g, cur_ray_angle);
	const float				wll_cam_angle
		= wall_camera_angle(g->camera_plane, rc_ret.side);
	const size_t			wll_px_width
		= wall_width(rc_ret.perp_dist, wll_cam_angle);
	const size_t			wll_px_height
		= wall_height(rc_ret.perp_dist);
	const size_t			wll_out_of_bounds_pxs
		= wall_px_offset(rc_ret.hit_point.x, wll_px_width);

	render_wall(
		wll_px_width, wll_px_height, wll_out_of_bounds_pxs, wll_cam_angle
	);
	return (wll_px_width);
}

static float	wall_camera_angle(t_camera_plane cp, t_side side)
{
	if (e_VERTICAL == side)
		return (cp.angle_from_y_axis);
	else
		return (cp.angle_from_x_axis);
}

static void	render_wall(const size_t wll_px_width, const size_t wll_px_height,
				const size_t wll_px_offset, const float wll_cam_angle)
{
}
