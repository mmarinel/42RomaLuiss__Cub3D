/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:19:50 by earendil          #+#    #+#             */
/*   Updated: 2022/12/21 20:43:21 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

static int	get_key_index(int key_code);
//*		end of static declarations

int	key_press_hook(int key_code, t_game *game)
{
	const int	key_index = get_key_index(key_code);

	// printf("key pressed: %d\n", key_code);
	// exit(0);
	if (e_false == game->in_game || (-1) == key_index)
		return (0);
	game->keys[key_index].state = KeyPress;
	return (0);
}

int	key_release_hook(int key_code, t_game *game)
{
	const int	key_index = get_key_index(key_code);

	if (e_false == game->in_game || (-1) == key_index)
		return (0);
	game->keys[key_index].state = KeyRelease;
	return (0);
}

static int	get_key_index(int key_code)
{
	if (e_W_KEY == key_code)
		return (W_INDEX);
	if (e_A_KEY == key_code)
		return (A_INDEX);
	if (e_S_KEY == key_code)
		return (S_INDEX);
	if (e_D_KEY == key_code)
		return (D_INDEX);
	if (e_UP_KEY == key_code)
		return (UP_INDEX);
	if (e_DOWN_KEY == key_code)
		return (DOWN_INDEX);
	if (e_RIGHT_KEY == key_code)
		return (RIGHT_INDEX);
	if (e_LEFT_KEY == key_code)
		return (LEFT_INDEX);
	if (e_SPACE_KEY == key_code)
		return (SPACE_INDEX);
	if (e_E_KEY == key_code)
		return (E_INDEX);
	// if (e_UP_KEY == key_code)
	// 	return (UP_INDEX);
	// if (e_UP_KEY == key_code)
	// 	return (UP_INDEX);
	// if (e_UP_KEY == key_code)
	// 	return (UP_INDEX);
	return (-1);
}
