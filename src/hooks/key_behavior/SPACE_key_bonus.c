/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_key_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:23:29 by earendil          #+#    #+#             */
/*   Updated: 2022/12/21 17:31:25 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys_behavior.h"

void	space_key_handler_pressed(t_game *game)
{
	const float	cost = game->player.mana / 4.0f;

	if (game->player.mana > 0)
	{
		game->player.attacking = e_true;
		game->player.mana -= cost;
		attack_enemies(game);
	}
	else
		game->player.attacking = e_false;
}

void	space_key_handler_released(t_game *game)
{
	game->player.attacking = e_false;
	if (game->player.mana < 100 && time(NULL) % 2)
		game->player.mana += 1;
}
