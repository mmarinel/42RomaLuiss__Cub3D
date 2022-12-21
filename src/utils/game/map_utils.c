/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 15:51:18 by earendil          #+#    #+#             */
/*   Updated: 2022/12/21 15:51:42 by earendil         ###   ########.fr       */
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
