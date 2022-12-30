/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:34:41 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 14:29:03 by earendil         ###   ########.fr       */
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
	size_t	north_texture_size;
	size_t	south_texture_size;
	size_t	west_texture_size;
	size_t	east_texture_size;

	north_texture_size = open_squared_texture(game_ref->map_handle.no_texture,
		&game_ref->textures.wall.north, game_ref, err_flag
	);
	south_texture_size = open_squared_texture(game_ref->map_handle.so_texture,
		&game_ref->textures.wall.south, game_ref, err_flag
	);
	west_texture_size = open_squared_texture(game_ref->map_handle.we_texture,
		&game_ref->textures.wall.west, game_ref, err_flag
	);
	east_texture_size = open_squared_texture(game_ref->map_handle.ea_texture,
		&game_ref->textures.wall.east, game_ref, err_flag
	);
	if (north_texture_size != south_texture_size
		|| north_texture_size != west_texture_size
		|| north_texture_size != east_texture_size
	)
		*err_flag = e_true;
	else
		textures_clipper_init(north_texture_size);
	if (BONUS)
		load_bonus_textures(game_ref, err_flag);
}
