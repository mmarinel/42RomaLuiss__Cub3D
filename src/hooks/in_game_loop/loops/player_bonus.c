/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:27:51 by earendil          #+#    #+#             */
/*   Updated: 2023/01/01 21:34:31 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "in_game_loops_bonus.h"

void	player_enemy_collision_check(t_game *game)
{
	t_list	*enemy_node;

	enemy_node = ft_lstfind(game->enemies, enemy_aggro, game);
	if (enemy_node)
	{
		game->player.hp -= 1;
		game->player.enemy_colliding = e_true;
		if (game->player.hp <= 0)
			game->in_end_menu = e_true;
	}
	else
		game->player.enemy_colliding = e_false;
}

void	player_item_collision_check(t_game *game)
{
	t_list	*item_node;
	t_item	*item;

	item_node = ft_lstfind(game->items, item_aggro, game);
	if (item_node)
	{
		item = item_node->content;
		if (game->player.hp < 100)
			game->player.hp += ceil(
				(100 - game->player.hp) * 10.0f / 100.0f
				);
		else
			game->player.attack_damage += 5.0f;
		game->player.picked_items += 1;
		item->picked = e_true;
		if (game->player.picked_items == game->player.tot_items)
			game->in_end_menu = e_true;
	}
}

void	player_recharge_mana(t_game *game)
{
	if (e_false == game->player.attacking && e_false == game->player.running)
	{
		if (game->player.mana < 100 && time(NULL) % 2)
			game->player.mana += 1;
	}
}
