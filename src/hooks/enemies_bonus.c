/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:19:15 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 22:04:56 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

static void	change_enemy_pos(t_enemy *enemy, t_game *game);
// static void	enemy_move_across_door(
// 	t_enemy *enemy, 
// 	const t_2d_point *door_position, const t_2d_point *enemy_dir,
// 	t_game *game
// 	);
//*		end of static declarations

void	move_enemies(t_game *game)
{
	t_list	*cur;

	cur = game->enemies;
	while (cur)
	{
		if (((t_enemy *)cur->content)->health
			&& e_false == enemy_colliding(cur->content, &game->player.pos)
		)
			change_enemy_pos(cur->content, game);
		cur = cur->next;
	}
}

void	enemies_anim_death(t_game *game)
{
	t_list	*cur;

	cur = game->enemies;
	while (cur)
	{
		if (0 == ((t_enemy *)cur->content)->health)
		{
			((t_enemy *)cur->content)->die_anim_frames -= 1;
			if (0 == ((t_enemy *)cur->content)->die_anim_frames)
				((t_enemy *)cur->content)->alive = e_false;
		}
		cur = cur->next;
	}
}

static void	enemy_take_damage(t_enemy *enemy, t_game *game)
{
	enemy->health -= game->player.attack_damage;
	if (enemy->health <= 0)
		enemy->health = 0;
}

static t_bool	enemy_hit(t_enemy *enemy, float ray_angle, t_game *game)
{
	const t_int_2d_point	enemy_tile = as_int_2dpt(&enemy->pos);
	const t_2d_point		ray = ft_rotate(game->player.dir, ray_angle);
	t_bool					hit;
	t_raycast_return		rc_ret;

	rc_ret = raycast(game, game->player.pos, ray, enemy_tile);
	hit = (
		ft_int_2d_point_equals(&enemy_tile, &rc_ret.wall.square)
		&& e_false == door_obstacle_through_dir(rc_ret.doors, NULL)
		&& rc_ret.wall.euclidean_dist <= game->player.attack_range
		);
	raycast_clean(&rc_ret);
	return (hit);
}

void	attack_enemies(t_game *game)
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

void	clean_enemies(t_game *game)
{
	t_list	*next;
	t_list	**prev_next;

	prev_next = &game->enemies;
	while (*prev_next)
	{
		next = (*prev_next)->next;
		if (e_false == ((t_enemy *)(*prev_next)->content)->alive)
		{
			ft_lstdelone(*prev_next, free);
			*prev_next = next;
		}
		else
			prev_next = &(*prev_next)->next;
	}
}

static void	change_enemy_pos(t_enemy *enemy, t_game *game)
{
	const t_2d_point		dir
		= ft_vec_sum(
			game->player.pos,
			ft_vec_opposite(enemy->pos)
			);
	const t_2d_point		new_pos
		= map_pos_clip(
			ft_vec_sum(
				enemy->pos,
				ft_change_magnitude(dir, enemy->step_size)
			),
			game
		);
	// const t_int_2d_point	next_tile = as_int_2dpt(&new_pos);

	if (is_traversable_pos(game, &enemy->pos, &new_pos))
	{
		// if (BONUS && is_door_map_char(
		// 	game->map_handle.map[next_tile.y][next_tile.x]
		// ))
		// 	enemy_move_across_door(enemy, &new_pos, &dir, game);
		// else
			enemy->pos = new_pos;
	}
}

// static void	enemy_move_across_door(
// 	t_enemy *enemy, 
// 	const t_2d_point *door_position, const t_2d_point *enemy_dir,
// 	t_game *game
// 	)
// {
// 	const t_2d_point	new_pos
// 		= ft_vec_sum(*door_position, ft_vec_normalize(*enemy_dir));

// 	if (is_free_pos_for_en(game, new_pos, enemy))
// 		enemy->pos = new_pos;
// }
