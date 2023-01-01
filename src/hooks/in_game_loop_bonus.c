/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_game_loop_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:59:49 by earendil          #+#    #+#             */
/*   Updated: 2023/01/01 15:55:57 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

static void	player_movement_handler(t_game *game);
static void	player_direction_handler(t_game *game);
static void	player_attack_handler(t_game *game);
static void	player_doors_handler(t_game *game);
//*		end of static declarations

void	in_game_loop(t_game *game)
{
	if (BONUS)
	{
		player_doors_handler(game);
		player_attack_handler(game);
		player_movement_handler(game);
		player_direction_handler(game);
		west_angle_update(game);
		player_enemy_collision_check(game);
		player_item_collision_check(game);
		enemies_anim_death(game);
		clean_enemies(game);
		clean_items(game);
		move_enemies(game);
		animate_doors(game);
	}
	else
	{
		player_movement_handler(game);
		player_direction_handler(game);
	}
	// render_next_frame(game);
}

static void	player_movement_handler(t_game *game)
{
	if (KeyPress == game->key_map.keys[W_INDEX].state)
		w_key_handler_pressed(game);
	else if (KeyPress == game->key_map.keys[A_INDEX].state)
		a_key_handler_pressed(game);
	else if (KeyPress == game->key_map.keys[S_INDEX].state)
		s_key_handler_pressed(game);
	else if (KeyPress == game->key_map.keys[D_INDEX].state)
		d_key_handler_pressed(game);
}

static void	player_direction_handler(t_game *game)
{
	if (BONUS)
		mouse_hook(game);
	if (KeyPress == game->key_map.keys[RIGHT_INDEX].state)
		right_key_handler_pressed(game);
	else if (KeyRelease == game->key_map.keys[RIGHT_INDEX].state)
		right_key_handler_released(game);
	if (KeyPress == game->key_map.keys[LEFT_INDEX].state)
		left_key_handler_pressed(game);
	else if (KeyRelease == game->key_map.keys[LEFT_INDEX].state)
		left_key_handler_released(game);
}

static void	player_attack_handler(t_game *game)
{
	if (KeyPress == game->key_map.keys[SPACE_INDEX].state)
		space_key_handler_pressed(game);
	else if (KeyRelease == game->key_map.keys[SPACE_INDEX].state)
		space_key_handler_released(game);
}

static void	player_doors_handler(t_game *game)
{
	if (KeyPress == game->key_map.keys[E_INDEX].state)
		e_key_handler(game);
}
