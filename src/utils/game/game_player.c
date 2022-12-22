/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:12:14 by earendil          #+#    #+#             */
/*   Updated: 2022/12/22 20:03:25 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

t_bool	is_free_pos(t_game *g, t_2d_point pt)
{
	const t_int_2d_point	normalized = as_int_2dpt(&pt);

	return (
		e_FLOOR == g->map_handle.map[normalized.y][normalized.x]
	);
}

t_bool	is_traversable_pos(
	t_game *g,
	t_2d_point *pt,
	const t_raycast_return *rc_return
	)
{
	const t_int_2d_point	tile = as_int_2dpt(pt);
(void)g;
	if (
		e_false == ft_int_2d_point_equals(&tile, &rc_return->wall.square)
		|| (BONUS && e_true == door_obstacle_through_dir(rc_return->doors))
	)
		return (e_false);
	else
		return (e_true);
		// return (is_free_pos(g, *pt));
}
