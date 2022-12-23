/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:27:51 by earendil          #+#    #+#             */
/*   Updated: 2022/12/23 18:02:56 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

void	player_enemy_collision_check(t_game *game)
{
	t_list	*enemy_node;

	enemy_node = ft_lstfind(game->enemies, enemy_aggro, game);
	if (enemy_node)
	{
		game->player.hp -= 1;
		game->player.enemy_colliding = e_true;
	}
	else
		game->player.enemy_colliding = e_false;
}
