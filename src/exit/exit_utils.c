/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:46:42 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 17:50:21 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	t_game_set_nulls(t_game *game)
{
	game->doors = NULL;
	game->items = NULL;
	game->enemies = NULL;
	game->map_handle.map = NULL;
	game->map_handle.no_texture = NULL;
	game->map_handle.so_texture = NULL;
	game->map_handle.ea_texture = NULL;
	game->map_handle.we_texture = NULL;
	game->screen_handle.mlx = NULL;
	game->screen_handle.window = NULL;
}
