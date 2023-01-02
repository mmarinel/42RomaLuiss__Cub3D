/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:51:18 by earendil          #+#    #+#             */
/*   Updated: 2023/01/02 09:59:50 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

t_2d_point	map_pos_clip(t_2d_point pt, t_game *game)
{
	if (pt.x >= game->map_handle.columns)
		pt.x = game->map_handle.columns - 1;
	if (pt.x < 0)
		pt.x = 0;
	if (pt.y >= game->map_handle.rows)
		pt.y = game->map_handle.rows - 1;
	if (pt.y < 0)
		pt.y = 0;
	return (pt);
}

t_bool	is_map_pos(
	const t_map_holder *map_handle,
	const t_int_2d_point *pos
	)
{
	if (NULL == map_handle)
		return (e_false);
	else
		return (
			(0 <= pos->x && pos->x < (int)map_handle->columns)
			&& (0 <= pos->y && pos->y < (int)map_handle->rows)
		);
}

t_bool	is_map_posf(
	const t_map_holder *map_handle,
	const t_2d_point *pos
	)
{
	if (NULL == map_handle)
		return (e_false);
	else
		return (
			(0 <= pos->x && pos->x < (int)map_handle->columns)
			&& (0 <= pos->y && pos->y < (int)map_handle->rows)
		);
}
