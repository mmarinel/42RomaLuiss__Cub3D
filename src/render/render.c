// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   render.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/11/13 09:35:01 by mmarinel          #+#    #+#             */
// /*   Updated: 2022/11/17 12:17:42 by mmarinel         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "render.h"

// static t_render_data			render_fetch_data(t_game *g,
// 									float cur_ray_angle);
// static t_wall_camera_incidence	wall_camera_incidence(
// 									t_camera_plane cp, t_side side
// 								);
// static size_t					render_region(t_game *g,
// 									float cur_ray_angle,
// 									size_t *cur_screen_px
// 								);
// static size_t	hit_wall_width(t_game *g, float perp_dist,
// 					t_wall_camera_incidence wc_incidence);
// static size_t	hit_wall_height(t_game *g, float perp_dist,
// 					t_wall_camera_incidence wc_incidence);
// //*		end of static declarations

// /*
// 	local vars:
// 		fov_half:			half of the FOV (field of view --
// 							[https://en.wikipedia.org/wiki/Field_of_view])

// 		angle_step_size:	the angle between a px column and the next one

// 		cur_ray_angle:		angle the current ray forms with
// 							the player direction versor

// 		hit_wall_px_width:	the width [in px] of the wall the ray hits
		
// 		cur_screen_col:		the px column we need to draw the next wall from
// */
// //
// /**
//  * @brief this function renders the next frame
//  * 
//  * 
//  * @param g a structure containing the all the data of the game
//  */
// void	render(t_game *g)
// {
// 	const float			fov_half = M_PI / 6;//* 60° / 2 = (π / 3) / 2 = π / 6
// 	const float			angle_step_size = fov_half / g->screen_handle.width;
// 	static size_t		cur_screen_col = 0;
// 	float				cur_ray_angle;
// 	float				hit_wall_px_width;//TODO	sfrutta la variazione della variabile [cur_screen_col] prima e dopo la chiamata a render_region !!!!!!!!!

// 	// cur_screen_col = 0;
// 	cur_ray_angle = M_PI / 2 - fov_half;
// 	while (cur_ray_angle < M_PI / 2 + fov_half)
// 	{
// 		hit_wall_px_width = render_region(g, cur_ray_angle, &cur_screen_col);
// 		cur_ray_angle += hit_wall_px_width * angle_step_size;
// 	}
// }

// /**
//  * @brief 
//  * 
//  * @param g 
//  * @param cur_ray_angle angle the ray forms with the camera plane
//  * @return size_t 
//  */
// static size_t	render_region(t_game *g,
// 					float cur_ray_angle,
// 					size_t *cur_screen_col
// 				)
// {
// 	const t_render_data	r_data = render_fetch_data(g, cur_ray_angle);
// 	size_t				i;

// 	draw_cube_left_side(g, r_data, cur_ray_angle, cur_screen_col);
// 	i = 0;
// 	while (i < r_data.wll_px_width)
// 	{
// 		if (i >= r_data.wll_out_bounds_pxs)
// 		{
// 			ft_mlx_put_stripe(col_floor_part(i, g, r_data),
// 				g->map_handle.f_color
// 			);
// 			ft_mlx_put_stripe(col_wall_part(i, g, r_data),
// 				wall_get_texture(r_data.rc_ret.side)
// 			);
// 			ft_mlx_put_stripe(col_ceil_part(i, g, r_data),
// 				g->map_handle.c_color
// 			);
// 			*cur_screen_col = (*cur_screen_col + 1) % g->screen_handle.width;
// 		}
// 		i += 1;
// 	}
// 	draw_cube_right_side(g, r_data,  cur_ray_angle, cur_screen_col);
// 	return (r_data.wll_px_width);
// }

// static void	draw_cube_left_side(t_game *g, t_render_data r_data,
// 				float cur_ray_angle, size_t *cur_screen_col)
// {
// }

// static void	draw_cube_right_side(t_game *g, t_render_data r_data,
// 				float cur_ray_angle, size_t *cur_screen_col)
// {
// }

// static size_t	coordinate_to_px(float coordinate)
// {
// 	const float origin;

// 	return ((size_t) roundf(coordinate - origin));
// }

// /**
//  * @brief this function serves for diagonal walls rendering.
//  * 
//  * @param cp the camera plane versor
//  * @param side the side the casted ray hit
//  * @return t_wall_camera_incidence a stucture containing all of the information
//  * about the angulation of the camera plane with respect to the side hit
//  */
// static t_wall_camera_incidence	wall_camera_incidence(
// 	t_camera_plane cp, t_side side
// 	)
// {
// 	t_wall_camera_incidence	wall_camera_incidence;

// 	{
// 		if (e_VERTICAL == side)
// 			wall_camera_incidence.angle = cp.angle_from_y_axis;
// 		else
// 			wall_camera_incidence.angle = cp.angle_from_x_axis;
// 	}
// 	{
// 		wall_camera_incidence.side = side;
// 	}
// 	{
// 		if (cp.versor.x >= 0 && cp.versor.y < 0)
// 			wall_camera_incidence.player_dir_quadrant = e_FIRST_QUADRANT;
// 		else if (cp.versor.x > 0 && cp.versor.y >= 0)
// 			wall_camera_incidence.player_dir_quadrant = e_SECOND_QUADRANT;
// 		else if (cp.versor.x <= 0 && cp.versor.y > 0)
// 			wall_camera_incidence.player_dir_quadrant = e_THIRD_QUADRANT;
// 		else if (cp.versor.x < 0 && cp.versor.y <= 0)
// 			wall_camera_incidence.player_dir_quadrant = e_FOURTH_QUADRANT;
// 	}
// 	wall_camera_incidence.reentrancy = reentrancy(wall_camera_incidence);
// 	return (wall_camera_incidence);
// }

// t_reentrancy	reentrancy(t_wall_camera_incidence wc_incidence)
// {
// 	if (e_HORIZONTAL == wc_incidence.side)
// 	{
// 		if (e_FIRST_QUADRANT == wc_incidence.player_dir_quadrant
// 			|| e_THIRD_QUADRANT == wc_incidence.player_dir_quadrant)
// 			return (e_OUTGOING);
// 		else
// 			return (e_INGOING);
// 	}
// 	else if (e_VERTICAL  == wc_incidence.side)
// 	{
// 		if (e_FIRST_QUADRANT == wc_incidence.player_dir_quadrant
// 			|| e_THIRD_QUADRANT == wc_incidence.player_dir_quadrant)
// 			return (e_INGOING);
// 		else
// 			return (e_OUTGOING);
// 	}
// 	else
// 		return (e_REENTRANCY_NONE);
// }

// static size_t	col_floor_part(size_t cur_px, t_game *g, t_render_data r_data)
// {
// 	const float	scaling_factor = 1 / (pow(rc_ret.perp_dist, 2) + 1);
// 	float		hit_wall_height = scaling_factor * g->screen_handle.height;
// 	float		hit_wall_width = 

// 	return ((size_t) roundf((g->screen_handle.height - hit_wall_height) / 2) - )
// 	// size_t	floor_end_for_dist = g->screen_handle.height - ()
// }

// static size_t	col_wall_part(size_t cur_px, t_game *g, t_render_data r_data)
// {
	
// }

// static size_t	col_ceil_part(size_t cur_px, t_game *g, t_render_data r_data)
// {
	
// }

// /**
//  * @brief this function returns the width of a wall
//  * when viewed from a [perp_dist] distance
//  * with an angle [wc_incidence] from the camera plane.
//  * It assumes all the wall is included in the FOV
//  * (i.e. the wall is hit on the left edge)
//  * 
//  * @param g 
//  * @param perp_dist 
//  * @param wc_incidence 
//  * @return size_t 
//  */
// static size_t	hit_wall_width(t_game *g, float perp_dist,
// 					t_wall_camera_incidence wc_incidence)
// {
// 	const float	size_as_from_0_dist = g->screen_handle.width;
// 	const float	scaling_factor = 1 / (pow(perp_dist, 2) + 1);
// 	float		size_as_full = scaling_factor * size_as_from_0_dist;

// 	return (size_as_full * cos(wc_incidence.angle));
// }

// /**
//  * @brief this function returns the height of a wall
//  * when viewed from a [perp_dist] distance
//  * with an angle [wc_incidence] from the camera plane.
//  * (The angle does not affect the height though)
//  * 
//  * @param g 
//  * @param perp_dist 
//  * @param wc_incidence 
//  * @return size_t 
//  */
// static size_t	hit_wall_height(t_game *g, float perp_dist,
// 					t_wall_camera_incidence wc_incidence)
// {
// 	const float	size_as_from_0_dist = g->screen_handle.height;
// 	const float	scaling_factor = 1 / (pow(perp_dist, 2) + 1);
// 	float		size_as_full = scaling_factor * size_as_from_0_dist;

// 	return (size_as_full);
// }

// static size_t	hit_wall_px_offset(t_game *g, t_raycast_return rc_ret,
// 					t_wall_camera_incidence wc_incidence)
// {
// 	float	cell_offset;
// 	float	px_offset_as_as_full;

// 	if (e_VERTICAL == rc_ret.side)
// 	{
// 		cell_offset = rc_ret.hit_point.y - rc_ret.square.y;
// 		return (
// 			(1 - cell_offset)
// 			* hit_wall_height(g, rc_ret.perp_dist, wc_incidence)
// 		);
// 	}
// 	else
// 	{
// 		cell_offset = rc_ret.hit_point.x - rc_ret.square.x;
// 		return (
// 			(1 - cell_offset)
// 			* hit_wall_width(g, rc_ret.perp_dist, wc_incidence)
// 		);
// 	}
// }

// static t_render_data	render_fetch_data(t_game *g, float cur_ray_angle)
// {
// 	const t_raycast_return			rc_ret
// 		= raycast(g, cur_ray_angle);
// 	const t_wall_camera_incidence	wll_cam_incidence
// 		= wall_camera_incidence(g->camera_plane, rc_ret.side);
// 	const size_t					wll_px_width
// 		= hit_wall_width(g, rc_ret.perp_dist, wll_cam_incidence);
// 	const size_t					wll_px_height
// 		= hit_wall_height(g, rc_ret.perp_dist, wll_cam_incidence);
// 	const size_t					wll_out_of_bounds_pxs
// 		= hit_wall_px_offset(g, rc_ret, wll_cam_incidence);

// 	return (
// 		(t_render_data){
// 			rc_ret,
// 			wll_px_width,
// 			wll_px_height,
// 			wll_out_of_bounds_pxs,
// 			wll_cam_incidence
// 		}
// 	);
// }
