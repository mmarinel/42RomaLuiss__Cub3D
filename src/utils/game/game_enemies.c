/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:17:41 by earendil          #+#    #+#             */
/*   Updated: 2022/12/21 16:10:56 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

t_bool	is_free_pos_for_en(t_game *g, t_2d_point pt, t_enemy *enemy)
{
	const t_int_2d_point	normalized = as_int_2dpt(&pt);
	t_list					*enemy_node;
	t_list					*door_node;

	enemy_node = ft_lstfind(g->enemies, enemy_pos, &normalized);
	door_node = ft_lstfind(g->doors, door_pos, &normalized);
	if (enemy_node && ((t_enemy *)enemy_node->content) != enemy)
		return (e_false);
	else if (door_node)
		return (
			e_DOOR_OPEN == ((t_door *)door_node->content)->status
		);
	else
		return (is_free_pos(g, pt));
}

/**
 * @brief this function returns true iff
 * the given enemy is trapped behind a door
 * 
 * @param enemy 
 * @param game 
 * @return t_bool 
 */
t_bool	is_enemy_trapped(t_enemy *enemy, t_game *game)
{
	const float				collision_radius = 0.5f;
	const t_2d_point		new_dir = ft_change_magnitude(
		ft_vec_sum(
			game->player.pos,
			ft_vec_opposite(enemy->pos)
			),
		collision_radius
	);
	const t_2d_point		new_pos = map_pos_clip(
		ft_vec_sum(enemy->pos, new_dir),
		game
	);
	const t_int_2d_point	new_tile = as_int_2dpt(&new_pos);

	return (
		is_door_map_char(
			game->map_handle.map[new_tile.y][new_tile.x]
			)
	);
}

t_bool	enemy_collision(const void *enemy, const void *player_pos)
{
	const t_enemy		*__enemy = (t_enemy *)enemy;
	const t_2d_point	*__player_pos = (t_2d_point *)player_pos;
	const size_t		collision_radius = 2;

	return (
		__enemy->health
		&& collision_radius >= ft_vec_norm(
			ft_vec_sum(
				*__player_pos,
				ft_vec_opposite(__enemy->pos)
				)
			)
		);
}

/**
 * @brief [domain rule]: there cannot be two enemies in the same position.
 * 
 * @param en1 
 * @param en2 
 * @return t_bool 
 */
t_bool	enemy_equals(const t_enemy *en1, const t_enemy *en2)
{
	return (
		e_true == ft_2d_point_equals(&en1->pos, &en2->pos)
	);
}

/**
 * @brief [domain rule]: there cannot be two enemies in the same position.
 * 
 * @param en1 
 * @param en2 
 * @return t_bool 
 */
t_bool	enemy_pos(const void *en, const void *pos)
{
	const t_enemy			*__en = (const t_enemy *)en;
	const t_int_2d_point	*__pos = (const t_int_2d_point *)pos;

	return (
		e_true == ft_int_2d_point_equals(
			&(t_int_2d_point){floor(__en->pos.x), floor(__en->pos.y)},
			__pos
		)
	);
}

t_enemy	*get_enemy(const t_int_2d_point *pos, t_game *game)
{
	t_list	*enemy_node;

	enemy_node = ft_lstfind(game->enemies, enemy_pos, pos);
	if (NULL == enemy_node)
		return (NULL);
	else
		return (enemy_node->content);
}
