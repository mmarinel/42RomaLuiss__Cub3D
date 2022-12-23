/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:27:51 by earendil          #+#    #+#             */
/*   Updated: 2022/12/23 17:13:23 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

void	collision_check(t_game *game)
{
	t_list	*enemy_node;
	t_enemy	*enemy;

	enemy_node = ft_lstfind(game->enemies, enemy_collision, &game->player.pos);
	{
		if (enemy_node)
			enemy = (t_enemy *)enemy_node->content;
		else
			enemy = NULL;
	}
	if (enemy && e_false == is_enemy_trapped(enemy, game))
	{
		game->player.hp -= 1;
		game->player.enemy_colliding = e_true;
	}
	else
		game->player.enemy_colliding = e_false;
}
