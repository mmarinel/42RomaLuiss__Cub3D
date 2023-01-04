/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 21:09:13 by earendil          #+#    #+#             */
/*   Updated: 2023/01/04 13:43:14 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

static void	mmp_draw_tile(
	const t_int_2d_point *mmp_px,
	const t_int_2d_point *player_mmp_px,
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

void	mmp_draw_map(
	const t_int_2d_point *mmp_bottom_left, t_game *g
	)
{
	const t_int_2d_point	top_left_corner = (t_int_2d_point){
		mmp_bottom_left->x,
		mmp_bottom_left->y - MMP_HEIGHT + 1
	};
	const t_int_2d_point	player_mmp_px = (t_int_2d_point){
		mmp_bottom_left->x + MMP_WIDTH / 2,
		mmp_bottom_left->y - MMP_HEIGHT / 2,
	};
	t_int_2d_point			mmp_px;

	mmp_px.x = top_left_corner.x;
	while (mmp_px.x < top_left_corner.x + MMP_WIDTH)
	{
		mmp_px.y = top_left_corner.y;
		while (mmp_px.y < top_left_corner.y + MMP_HEIGHT)
		{
			mmp_draw_tile(&mmp_px, &player_mmp_px, g);
			mmp_px.y += 1;
		}
		mmp_px.x += 1;
	}
}

static void	mmp_draw_tile(
	const t_int_2d_point *mmp_px,
	const t_int_2d_point *player_mmp_px,
	t_game *g
	)
{
	const t_int_2d_point	player_map_pos = as_int_2dpt(&g->player.pos);
	t_int_2d_point			map_pos;
	t_list					*enemy;
	t_list					*door;

	map_pos = mmp_get_map_pos(mmp_px, player_mmp_px, g);
	enemy = ft_lstfind(g->enemies, enemy_pos, &map_pos);
	door = ft_lstfind(g->doors, door_pos, &map_pos);
	if (enemy)
		draw_enemy_box(mmp_px, g);
	else if (ft_int_2d_point_equals(&player_map_pos, &map_pos))
		draw_mmp_player_box(mmp_px, g);
	else if (e_WALL == g->map_handle.map[map_pos.y][map_pos.x]
			|| (door && e_DOOR_CLOSED == ((t_door *)door->content)->status))
		draw_mmp_wall(mmp_px, g);
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

static void	draw_mmp_player_box(
	const t_int_2d_point *mmp_px,
	t_game *g
	)
{
	const t_color	box_col = (t_color){214, 4, 158, 1};
	static int		calls = 0;


	calls += 1;
	// printf("player printed %d times\n", calls);
	ft_put_px_to_image(
		&g->screen_handle.frame_data,
		ft_get_pixel_offset(
			&g->screen_handle.frame_data,
			*mmp_px
		),
		box_col
	);
}
