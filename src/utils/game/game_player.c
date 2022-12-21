/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:12:14 by earendil          #+#    #+#             */
/*   Updated: 2022/12/21 16:12:23 by earendil         ###   ########.fr       */
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
