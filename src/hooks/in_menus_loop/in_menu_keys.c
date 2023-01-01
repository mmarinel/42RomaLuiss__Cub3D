/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_menu_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:53:35 by earendil          #+#    #+#             */
/*   Updated: 2023/01/01 17:27:30 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "in_menu_loop_bonus.h"

static void	route_key(t_key_state *key, t_game *game);
//*		end of static declarations

void	in_menu_keys_handler(t_game *game)
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
	if (e_ENTER_KEY == key->code)
		in_menu_enter_key(key, game);
	if (e_UP_KEY == key->code || e_DOWN_KEY == key->code)
		in_menu_move(key, game);
}
