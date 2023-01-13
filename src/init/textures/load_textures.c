/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:34:41 by earendil          #+#    #+#             */
/*   Updated: 2023/01/13 15:28:01 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_init.h"

/**
 * @brief this function opens the textures of the game.
 * All textures are 200 px wide squares.
 * Everything but walls can have a padding with transparent px (e.g. enemies)
 *
 * @param game_ref
 */
void	load_textures(t_game *game_ref, t_bool *err_flag)
{
	size_t	no_tx_sz;
	size_t	so_tx_sz;
	size_t	we_tx_sz;
	size_t	ea_tx_sz;

	no_tx_sz = open_squared_texture(game_ref->map_handle.no_texture,
			&game_ref->textures.wall.north, game_ref, err_flag
			);
	so_tx_sz = open_squared_texture(game_ref->map_handle.so_texture,
			&game_ref->textures.wall.south, game_ref, err_flag
			);
	we_tx_sz = open_squared_texture(game_ref->map_handle.we_texture,
			&game_ref->textures.wall.west, game_ref, err_flag
			);
	ea_tx_sz = open_squared_texture(game_ref->map_handle.ea_texture,
			&game_ref->textures.wall.east, game_ref, err_flag
			);
	if (no_tx_sz != so_tx_sz || no_tx_sz != we_tx_sz || no_tx_sz != ea_tx_sz)
		*err_flag = e_true;
	else
		textures_clipper_init(no_tx_sz);
	if (BONUS)
		load_bonus_textures(game_ref, err_flag);
}
