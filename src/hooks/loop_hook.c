/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:22:02 by earendil          #+#    #+#             */
/*   Updated: 2022/12/25 17:40:25 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

static void	player_movement_handler(t_game *game);
static void	player_direction_handler(t_game *game);
static void	player_attack_handler(t_game *game);
static void	player_doors_handler(t_game *game);
//*		end of static declarations

int	loop_hook(t_game *game)
{
	if (e_false == game->in_game)
		return (0);
	if (BONUS)
	{
		player_doors_handler(game);
		player_attack_handler(game);
	}
	player_movement_handler(game);
	player_direction_handler(game);
	if (BONUS)
	{
		west_angle_update(game);
		player_enemy_collision_check(game);
		player_item_collision_check(game);
		enemies_anim_death(game);
		clean_enemies(game);
		clean_items(game);
		move_enemies(game);
		animate_doors(game);
	}
	render_next_frame(game);
	return (0);
}

static void	player_movement_handler(t_game *game)
{
	if (KeyPress == game->keys[W_INDEX].state)
		w_key_handler_pressed(game);
	else if (KeyPress == game->keys[A_INDEX].state)
		a_key_handler_pressed(game);
	else if (KeyPress == game->keys[S_INDEX].state)
		s_key_handler_pressed(game);
	else if (KeyPress == game->keys[D_INDEX].state)
		d_key_handler_pressed(game);
}

static void	player_direction_handler(t_game *game)
{
	if (KeyPress == game->keys[RIGHT_INDEX].state)
		right_key_handler_pressed(game);
	else if (KeyRelease == game->keys[RIGHT_INDEX].state)
		right_key_handler_released(game);
	if (KeyPress == game->keys[LEFT_INDEX].state)
		left_key_handler_pressed(game);
	else if (KeyRelease == game->keys[LEFT_INDEX].state)
		left_key_handler_released(game);
}

static void	player_attack_handler(t_game *game)
{
	if (KeyPress == game->keys[SPACE_INDEX].state)
		space_key_handler_pressed(game);
	else if (KeyRelease == game->keys[SPACE_INDEX].state)
		space_key_handler_released(game);
}

static void	player_doors_handler(t_game *game)
{
	if (KeyPress == game->keys[E_INDEX].state)
		e_key_handler(game);
}
