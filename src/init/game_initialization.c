/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:28:32 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/12 12:05:29 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_init.h"

static void	first_call_inits(t_game *game_ref, size_t width, size_t height);
//*		end of static declarations

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
			first_call_inits(game_ref, width, height);
		t_game_set(map_path, game_ref);
		load_textures(game_ref, &error);
	}
	calls++;
	return (error == e_false);
}

static void	first_call_inits(t_game *game_ref, size_t width, size_t height)
{
	if (BONUS)
		set_rand();
	game_set_mlx(game_ref, width, height);
}
