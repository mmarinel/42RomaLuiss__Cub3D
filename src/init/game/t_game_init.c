/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_game_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:43:30 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 18:48:39 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_init.h"

static void	set_lvls(const char *map_path, t_game *game_ref);
//*		end of static declarations

void	t_game_init(t_game *game_ref)
{
	game_ref->doors = NULL;
	game_ref->enemies = NULL;
	game_ref->items = NULL;
	game_init_map(game_ref);
	game_init_textures(game_ref);
	game_init_keys(game_ref);
	game_init_menus(game_ref);
}

//*	acceleration:	0.25 IMPLIES==> when 16 frames (8 frames per sec on avg)
//*					have passed: step_size * (1 + step_ampl) = 2 tiles
void	t_game_set(const char *map_path, t_game *game_ref)
{
	set_lvls(map_path, game_ref);
	game_ref->in_focus = e_true;
	game_ref->mouse_clicked = e_false;
	game_ref->unit_rot_angle = INITIAL_ROT_ANGLE;
	game_ref->player.alive = e_true;
	game_ref->player.hp = 100;
	game_ref->player.mana = 100;
	game_ref->player.attack_damage = 10;
	game_ref->player.attack_range
		= (3.0f / 2) * ENEMIES_DEFAULT_COLLISION_RADIUS + 1;
	game_ref->player.action_range = 1.0f + 1;
	game_ref->player.step_size = 0.4f;
	game_ref->player.step_ampl = 0;
	game_ref->player.acceleration = 0.25f;
	game_ref->player.attacking = e_false;
	game_ref->player.running = e_false;
	game_ref->player.enemy_colliding = e_false;
	game_ref->player.west_angle = player_west_angle(game_ref);
	game_ref->player.picked_items = 0;
	game_ref->player.tot_items = ft_lstsize(game_ref->items);
}

static void	set_lvls(const char *map_path, t_game *game_ref)
{
	game_ref->cur_lvl = (char *)map_path;
	game_ref->lvls[0] = "map/bonus_level.cub";
	game_ref->lvls[1] = "map/bonus_level_2.cub";
	game_ref->lvls[2] = "map/bonus_level_3.cub";
	game_ref->lvls[3] = "map/bonus_level_4.cub";
}
