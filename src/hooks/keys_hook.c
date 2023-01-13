/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:19:50 by earendil          #+#    #+#             */
/*   Updated: 2023/01/13 10:43:58 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

static int	get_key_index(int key_code, t_game *game);
//*		end of static declarations

int	key_press_hook(int key_code, t_game *game)
{
	const int	key_index = get_key_index(key_code, game);

	if (e_false == game->in_focus || (-1) == key_index)
		return (0);
	else if (e_ESC_KEY == key_code)
		exit_game(game);
	else
		game->key_map.keys[key_index].state = KeyPress;
	return (0);
}

int	key_release_hook(int key_code, t_game *game)
{
	const int	key_index = get_key_index(key_code, game);

	if (e_false == game->in_focus || (-1) == key_index)
		return (0);
	game->key_map.keys[key_index].state = KeyRelease;
	return (0);
}

static int	get_key_index(int key_code, t_game *game)
{
	size_t	i;

	i = 0;
	while (i < BOUND_KEYS)
	{
		if (key_code == (int)game->key_map.keys[i].code)
			return (i);
		i++;
	}
	return (-1);
}
