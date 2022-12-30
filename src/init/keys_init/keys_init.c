/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:39:32 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 13:39:43 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_init.h"

void	game_set_key_state(t_game *game_ref)
{
	size_t	cur_key;

	cur_key = 0;
	while (cur_key < BOUND_KEYS)
	{
		game_ref->keys[cur_key].state = -1;
		cur_key += 1;
	}
}
