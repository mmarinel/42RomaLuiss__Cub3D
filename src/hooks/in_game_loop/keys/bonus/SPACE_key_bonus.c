/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SPACE_key_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:23:29 by earendil          #+#    #+#             */
/*   Updated: 2023/01/13 10:51:44 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "in_game_keys_bonus.h"

static void		attack(t_game *game);
static void		attack_enemies(t_game *game);
static t_bool	enemy_hit(t_enemy *enemy, float ray_angle, t_game *game);
static void		enemy_take_damage(t_enemy *enemy, t_game *game);
//*		end of static declarations

void	in_game_space_key(t_key_state *key, t_game *game)
{
	if (game->player.mana > 0
		&& (KeyPress == key->state || game->mouse_clicked))
		attack(game);
	else
		game->player.attacking = e_false;
}

static void	attack(t_game *game)
{
	const float	cost = game->player.mana / 4.0f;

	game->player.attacking = e_true;
	game->player.mana -= cost;
	attack_enemies(game);
}

static void	attack_enemies(t_game *game)
{
	const float			attack_view = M_PI / 4;
	t_list				*enemy_node;

	enemy_node = game->enemies;
	while (enemy_node)
	{
		if (
			enemy_hit(enemy_node->content, 2 * M_PI - attack_view / 2, game)
			|| enemy_hit(enemy_node->content, 0, game)
			|| enemy_hit(enemy_node->content, attack_view / 2, game)
		)
			enemy_take_damage(enemy_node->content, game);
		enemy_node = enemy_node->next;
	}
}

static t_bool	enemy_hit(t_enemy *enemy, float ray_angle, t_game *game)
{
	const t_int_2d_point	enemy_tile = as_int_2dpt(&enemy->pos);
	const t_2d_point		ray = ft_rotate(game->player.dir, ray_angle);
	t_bool					hit;
	t_raycast_return		rc_ret;

	rc_ret = raycast(game, game->player.pos, ray, enemy_tile);
	hit = (
			ft_int_2d_point_equals(&enemy_tile, &rc_ret.final_tile.square)
			&& rc_ret.final_tile.euclidean_dist <= game->player.attack_range
			);
	raycast_clean(&rc_ret);
	return (hit);
}

static void	enemy_take_damage(t_enemy *enemy, t_game *game)
{
	enemy->health -= game->player.attack_damage;
	if (enemy->health <= 0)
		enemy->health = 0;
}
