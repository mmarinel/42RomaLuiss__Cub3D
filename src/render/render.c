/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 09:35:01 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/28 16:58:17 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static t_2d_point	ray_dir_for_col(
	size_t col,
	t_game *g
	);
static void			render_column(
	size_t column,
	t_game *g,
	const t_raycast_return *rc_ret
	);
//*		end of static declarations

void	render_next_frame(t_game *g)
{
	size_t				col;
	t_raycast_return	rc_return;
	t_list				*entities;
	t_list				*rays;
	
	mlx_clear_window(g->screen_handle.mlx, g->screen_handle.window);
	if (BONUS)
	{
		entities = NULL;
		rays = NULL;
		draw_background_bonus(g);
		draw_sun(g);
	}
	else
		draw_background(g);
	col = 0;
	while (col < g->screen_handle.width)
	{
		rc_return = raycast_wall(g, ray_dir_for_col(col, g));
		if (BONUS)
		{
			update_entity_list(&entities, &rc_return, col);
			ft_lstadd_back(&rays, ft_new_ray_node(&rc_return));
		}
		render_column(col, g, &rc_return);
		if (BONUS)
		{
			render_doors(col, &rc_return, g);
		}
		col++;
	}
	if (BONUS)
	{
		render_entities(entities, g);
		render_minimap(rays, g);
		render_collision(g);
		render_health_bar(g);
		render_mana_bar(g);
		render_items_bar(g);
		if (g->player.attacking)
			render_attack(g);
	}
	mlx_put_image_to_window(
		g->screen_handle.mlx, g->screen_handle.window,
		g->screen_handle.frame_data.img,
		0, 0);
	// rc_clean(rays);
}

static void	render_column(
	size_t column,
	t_game *g,
	const t_raycast_return *rc_ret
	)
{
	const size_t			wall_size = roundf(
		g->screen_handle.height / rc_ret->wall.perp_dist
	);
	const float				gap = ( 
		((float)g->screen_handle.height - wall_size) / 2.0f
	);
	const t_column_info		col_info = get_wall_column_info(
		wall_size, gap, rc_ret, g
		);
	t_int_2d_point			endpoint[2];
	
	endpoint[0] = (t_int_2d_point){column, gap};
	endpoint[1] = (t_int_2d_point){column, gap + (wall_size - 1)};
	if (0 == wall_size)
		return ;
	else
		bresenham_plot(
			endpoint,
			&g->screen_handle.frame_data,
			nearest_neighbour, &(t_nxt_px_f_arg){&col_info, NULL}
		);
}

static t_2d_point	ray_dir_for_col(size_t col, t_game *g)
{
	t_2d_point	ray;
	const float	dilatation_factor =
			((2.0f * col) / (g->screen_handle.width - 1.0f)) - 1.0f;

	ray.x = g->player.dir.x + dilatation_factor * g->player.camera_plane.x;
	ray.y = g->player.dir.y + dilatation_factor * g->player.camera_plane.y;
	return (ray);
}
