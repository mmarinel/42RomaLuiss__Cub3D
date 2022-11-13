/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 09:35:01 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/13 19:04:33 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static t_render_data			render_fetch_data(t_game *g,
									float cur_ray_angle);
static t_wall_camera_incidence	wall_camera_incidence(
									t_camera_plane cp, t_side side
								);
static size_t					render_region(t_game *g,
									float cur_ray_angle,
									size_t *cur_screen_px
								);
//*		end of static declarations

void	render(t_game *g)
{
	const float	fov_half = M_PI / 6;//* 60 / 2 = (π / 3) / 2
	const float	angle_step_size = fov_half / g->screen_handle.width;
	float		cur_ray_angle;
	float		hit_wall_px_width;
	size_t		cur_screen_px;

	cur_screen_px = 0;
	cur_ray_angle = M_PI / 2 - fov_half;
	while (cur_ray_angle < M_PI / 2 + fov_half)
	{
		hit_wall_px_width = render_region(g, cur_ray_angle, &cur_screen_px);
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
static size_t	render_region(t_game *g,
					float cur_ray_angle,
					size_t *cur_screen_px
				)
{
	const t_render_data	r_data = render_fetch_data(g, cur_ray_angle);
	size_t				i;

	i = 0;
	while (i < r_data.wll_px_width)
	{
		if (i >= r_data.wll_out_bounds_pxs)
		{
			
		}
		i += 1;
		*cur_screen_px += 1;
	}
	
	return (r_data.wll_px_width);
}

static t_wall_camera_incidence	wall_camera_incidence(
	t_camera_plane cp, t_side side
	)
{
	t_wall_camera_incidence	wall_camera_incidence;

	{
		if (e_VERTICAL == side)
			wall_camera_incidence.angle = cp.angle_from_y_axis;
		else
			wall_camera_incidence.angle = cp.angle_from_x_axis;
	}
	{
		wall_camera_incidence.side = side;
	}
	{
		if (cp.versor.x >= 0 && cp.versor.y < 0)
			wall_camera_incidence.raydir_quadrant = e_FIRST_QUADRANT;
		else if (cp.versor.x > 0 && cp.versor.y >= 0)
			wall_camera_incidence.raydir_quadrant = e_SECOND_QUADRANT;
		else if (cp.versor.x <= 0 && cp.versor.y > 0)
			wall_camera_incidence.raydir_quadrant = e_THIRD_QUADRANT;
		else if (cp.versor.x < 0 && cp.versor.y <= 0)
			wall_camera_incidence.raydir_quadrant = e_FOURTH_QUADRANT;
	}
	return (wall_camera_incidence);
}

static t_render_data	render_fetch_data(t_game *g, float cur_ray_angle)
{
	const t_raycast_return			rc_ret
		= raycast(g, cur_ray_angle);
	const t_wall_camera_incidence	wll_cam_incidence
		= wall_camera_incidence(g->camera_plane, rc_ret.side);
	const size_t					wll_px_width
		= wall_width(rc_ret.perp_dist, wll_cam_incidence);
	const size_t					wll_px_height
		= wall_height(rc_ret.perp_dist);
	const size_t					wll_out_of_bounds_pxs
		= wall_px_offset(rc_ret.hit_point.x, wll_px_width);

	return (
		(t_render_data){
			rc_ret,
			wll_px_width,
			wll_px_height,
			wll_out_of_bounds_pxs,
			wll_cam_incidence
		}
	);
}

// static void	render_wall(const size_t wll_px_width, const size_t wll_px_height,
// 				const size_t wll_px_offset, const float wll_cam_angle)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < wll_px_width)
// 	{
// 		if (i >= wll_px_offset)
// 		{
// 			ft_mlx_fill_col()
// 		}
// 		i += 1;
// 	}
	
// }
