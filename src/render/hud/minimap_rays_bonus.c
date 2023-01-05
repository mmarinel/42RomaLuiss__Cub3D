/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_rays.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:20:19 by earendil          #+#    #+#             */
/*   Updated: 2023/01/05 19:48:44 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

static void	render_minimap_ray(
	const t_raycast_return *rc_ret,
	const t_int_2d_point *mmp_bottom_left,
	t_game *g
	);
static void	mmp_draw_ray(
	const t_int_2d_point *player_mmp_px,
	const t_int_2d_point *wall_mmp_px,
	t_game *g
	);
static int	mmp_ray_next_pixel(t_nxt_px_f_arg *f_arg);
//*		end of static declarations

void	mmp_draw_rays(
	t_list *rays,
	const t_int_2d_point *mmp_bottom_left,
	t_game *g
	)
{
	t_list	*cur;

	cur = rays;
	while (cur)
	{
		render_minimap_ray(cur->content, mmp_bottom_left, g);
		cur = cur->next;
	}
}

static void	render_minimap_ray(
	const t_raycast_return *rc_ret,
	const t_int_2d_point *mmp_bottom_left,
	t_game *g
	)
{
	const t_int_2d_point	player_map_pos = as_int_2dpt(&g->player.pos);
	const t_int_2d_point	player_mmp_px = mmp_px_clip(
		mmp_bottom_left,
		&(t_int_2d_point){
				mmp_bottom_left->x + MMP_WIDTH / 2,
				mmp_bottom_left->y - MMP_HEIGHT / 2,
			}
	);
	const t_int_2d_point	wall_mmp_px = mmp_px_clip(
		mmp_bottom_left,
		&(t_int_2d_point){
			player_mmp_px.x
				+ MMP_TILE_WIDTH * (
					(rc_ret->final_tile.hit_point.x - player_map_pos.x)
				),
			player_mmp_px.y
				+ MMP_TILE_WIDTH * (
					(rc_ret->final_tile.hit_point.y - player_map_pos.y)
				),
			}
	);

	mmp_draw_ray(&player_mmp_px, &wall_mmp_px, g);
}

static void	mmp_draw_ray(
	const t_int_2d_point *player_mmp_px,
	const t_int_2d_point *wall_mmp_px,
	t_game *g
	)
{
	const t_color	ray_color = (t_color){214, 4, 158, 1};

	bresenham_plot(
		(t_int_2d_point[2]){
			*player_mmp_px,
			*wall_mmp_px
		},
		&g->screen_handle.frame_data,
		mmp_ray_next_pixel,
		&(t_nxt_px_f_arg){
			&ray_color,
			NULL
		}
	);
}

static int	mmp_ray_next_pixel(t_nxt_px_f_arg *f_arg)
{
	const t_color	*ray_col = (const t_color *)f_arg->arg;

	return (
		(ray_col->red) + (ray_col->green << 8) + (ray_col->blue << 16)
	);
}
