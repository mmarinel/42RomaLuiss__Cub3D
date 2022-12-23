/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:12:14 by earendil          #+#    #+#             */
/*   Updated: 2022/12/23 23:39:08 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

static t_bool	wall_collision(
	const t_int_2d_point *next_tile,
	const t_raycast_return *rc_return,
	t_game *g
	);
static t_bool	door_collision(
	const t_int_2d_point *next_tile,
	const t_raycast_return *rc_return
	);
//*		end of static declarations

t_bool	is_free_pos(t_game *g, t_2d_point pt)
{
	const t_int_2d_point	normalized = as_int_2dpt(&pt);

	return (
		e_FLOOR == g->map_handle.map[normalized.y][normalized.x]
	);
}

t_bool	is_traversable_pos(
	t_game *g,
	const t_2d_point *old_pos,
	const t_2d_point *next_pos
	)
{
	const t_int_2d_point	next_tile = as_int_2dpt(next_pos);
	const t_int_2d_point	cur_tile = as_int_2dpt(old_pos);
	t_raycast_return		rc_ret;

	if (ft_int_2d_point_equals(&next_tile, &cur_tile))
		return (e_true);
	else
	{
		rc_ret = raycast_movement(old_pos, next_pos, g);
		if (
			wall_collision(&next_tile, &rc_ret, g)
			|| door_collision(&next_tile, &rc_ret)
		)
			return (e_false);
		else
			return (e_true);
	}
}

static t_bool	wall_collision(
	const t_int_2d_point *next_tile,
	const t_raycast_return *rc_return,
	t_game *g
	)
{
	return (
		e_WALL == g->map_handle.map[next_tile->y][next_tile->x]//TODO spostare is_wall_map_char in src/utils
		|| e_false  == ft_int_2d_point_equals(next_tile, &rc_return->wall.square)
	);
}

static t_bool	door_collision(
	const t_int_2d_point *next_tile,
	const t_raycast_return *rc_return
	)
{
	return (
		(BONUS && e_true == door_obstacle_through_dir(rc_return->doors, next_tile))
	);
}

//TODO
//			check same pos
//			check wall collision (line 39, 40)
//			check door collision (la sola porta che può esserci, deve essere nella posizione di arrivo
//									e deve essere aperta!)


		// 
		// || e_false == ft_int_2d_point_equals(&next_tile, &rc_return->wall.square)
		// || (BONUS && e_true == door_obstacle_through_dir(rc_return->doors))//*NON VA BENE