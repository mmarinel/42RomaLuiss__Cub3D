/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:43:30 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 13:45:15 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_init.h"

void	t_game_set(t_game *game_ref)
{
	game_ref->in_focus = e_true;
	game_ref->in_menu = e_true;
	game_ref->in_end = e_false;
	game_ref->menu_screen = 0;
	game_ref->unit_rot_angle = INITIAL_ROT_ANGLE;
	game_ref->player.alive = e_true;
	game_ref->player.hp = 100;
	game_ref->player.mana = 100;
	game_ref->player.attack_damage = 10;
	game_ref->player.attack_range = (3.0f / 2) * ENEMIES_DEFAULT_COLLISION_RADIUS + 1;
	game_ref->player.action_range = 1.0f + 1;
	game_ref->player.attacking = e_false;
	game_ref->player.enemy_colliding = e_false;
	game_ref->player.west_angle = player_west_angle(game_ref);
	game_ref->player.picked_items = 0;
	game_ref->player.tot_items = ft_lstsize(game_ref->items);
}