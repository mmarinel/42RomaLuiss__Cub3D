/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:28:32 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/01 14:35:12 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_init.h"

t_bool	ft_game_init(
			const char *map_path,
			t_game *game_ref,
			size_t width, size_t height
		)
{
	static int	calls = 0;
	t_bool		error;

	t_game_init(game_ref);
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
		if (0 == calls)
		{
			set_rand();
			game_set_mlx(game_ref, width, height);
		}
		t_game_set(map_path, game_ref);
		load_textures(game_ref, &error);
	}
	calls++;
	return (error == e_false);
}
