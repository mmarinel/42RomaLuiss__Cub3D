/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_game_loops_handler_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:41:51 by earendil          #+#    #+#             */
/*   Updated: 2023/01/05 13:51:09 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "in_game_loops_bonus.h"

void	in_game_loops_handler(t_game *game)
{
	west_angle_adjust(game);
	player_recharge_mana(game);
	player_enemy_collision_check(game);
	player_item_collision_check(game);
	enemies_anim_death(game);
	clean_enemies(game);
	clean_items(game);
	move_enemies(game);
	animate_doors(game);
}
