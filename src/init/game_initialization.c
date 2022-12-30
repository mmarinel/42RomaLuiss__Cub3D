/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:28:32 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/30 13:50:44 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_init.h"

t_bool	ft_game_init(
			const char *map_path,
			t_game *game_ref,
			size_t width, size_t height
		)
{
	t_bool	error;

	game_ref->enemies = NULL;
	game_ref->items = NULL;
	game_ref->doors = NULL;
	game_set_map(game_ref);
	error = e_false;
	if (e_false == is_valid_map(map_path, &game_ref->map_handle))
		error = e_true;
	else
	{
		game_set_inital_vectors(game_ref);
		if (BONUS)
		{
			scan_items(game_ref);
			scan_enemies(game_ref);
			scan_doors(game_ref);
		}
		map_reset(&game_ref->map_handle);
		game_set_mlx(game_ref, width, height);
		game_set_key_state(game_ref);
		t_game_set(game_ref);
		load_textures(game_ref, &error);
	}
	return (error == e_false);
}
