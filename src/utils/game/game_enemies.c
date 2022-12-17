/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enemies.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:17:41 by earendil          #+#    #+#             */
/*   Updated: 2022/12/17 21:51:07 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

t_bool	enemy_collision(const void *enemy, const void *player_pos)
{
	const t_enemy		*__enemy = (t_enemy *)enemy;
	const t_2d_point	*__player_pos = (t_2d_point *)player_pos;

	return (
		__enemy->health
		&& 1 >= ft_vec_norm(
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
