/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_game_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:54:05 by earendil          #+#    #+#             */
/*   Updated: 2023/01/05 13:40:40 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "in_game_keys.h"

static void	route_key(t_key_state *key, t_game *game);
//*		end of static declarations

void	in_game_keys_handler(t_game *game)
{
	size_t	i;

	i = 0;
	while (i < BOUND_KEYS)
	{
		route_key(&game->key_map.keys[i], game);
		i += 1;
	}
}

static void	route_key(t_key_state *key, t_game *game)
{
	if (BONUS && e_E_KEY == key->code)
		in_game_e_key(key, game);
	if (BONUS && e_SPACE_KEY == key->code)
		in_game_space_key(key, game);
	if (is_movement_key(key))
		in_game_movement_key(key, game);
	if (is_rotation_key(key))
		in_game_rotation_key(key, game);
}
