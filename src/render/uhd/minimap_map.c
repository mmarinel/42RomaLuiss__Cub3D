/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:09:13 by earendil          #+#    #+#             */
/*   Updated: 2022/12/27 21:17:19 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

static t_int_2d_point	mmp_get_map_pos(
	const t_int_2d_point *mmp_px, const t_int_2d_point *player_mmp_px,
	t_game *g
	);
static void	draw_mmp_wall(
	const t_int_2d_point *mmp_px,
	t_game *g
	);
static void	draw_mmp_player_box(
	const t_int_2d_point *mmp_px,
	t_game *g
	);
static void	draw_enemy_box(
	const t_int_2d_point *mmp_px,
	t_game *g
	);
//*		end of static declarations

void	mmp_draw_tile(
	const t_int_2d_point *mmp_px,
	const t_int_2d_point *player_mmp_px,
	t_game *g
	)
{
	const t_int_2d_point	player_map_pos = as_int_2dpt(&g->player.pos);
	t_int_2d_point			map_pos;
	t_list					*enemy;

	map_pos = mmp_get_map_pos(mmp_px, player_mmp_px, g);
	enemy = ft_lstfind(g->enemies, enemy_pos, &map_pos);
	if (enemy)
		draw_enemy_box(mmp_px, g);
	else if (ft_int_2d_point_equals(&player_map_pos, &map_pos))//*debug
		draw_mmp_player_box(mmp_px, g);
	else if (e_FLOOR != g->map_handle.map[map_pos.y][map_pos.x])
		draw_mmp_wall(mmp_px, g);
}

static t_int_2d_point	mmp_get_map_pos(
	const t_int_2d_point *mmp_px, const t_int_2d_point *player_mmp_px,
	t_game *g
	)
{
	const t_2d_point	pos = map_pos_clip(
		(t_2d_point){
			(
				(float)(mmp_px->x - player_mmp_px->x) / MMP_TILE_WIDTH
					+ g->player.pos.x
			),
			(
				(float)(mmp_px->y - player_mmp_px->y) / MMP_TILE_WIDTH
					+ g->player.pos.y
			)
		},
		g
	);

	return (as_int_2dpt(&pos));
}

static void	draw_mmp_wall(
	const t_int_2d_point *mmp_px,
	t_game *g
	)
{
	const t_color	wall_col = (t_color){5, 26, 59, 1};;


	ft_put_px_to_image(
		&g->screen_handle.frame_data,
		ft_get_pixel_offset(
			&g->screen_handle.frame_data,
			*mmp_px
		),
		wall_col
	);
}

static void	draw_enemy_box(
	const t_int_2d_point *mmp_px,
	t_game *g
	)
{
	const t_color	box_col = (t_color){255, 0, 0, 1};


	ft_put_px_to_image(
		&g->screen_handle.frame_data,
		ft_get_pixel_offset(
			&g->screen_handle.frame_data,
			*mmp_px
		),
		box_col
	);
}

//*		debug
static void	draw_mmp_player_box(
	const t_int_2d_point *mmp_px,
	t_game *g
	)
{
	const t_color	box_col = (t_color){214, 4, 158, 1};;


	ft_put_px_to_image(
		&g->screen_handle.frame_data,
		ft_get_pixel_offset(
			&g->screen_handle.frame_data,
			*mmp_px
		),
		box_col
	);
}
