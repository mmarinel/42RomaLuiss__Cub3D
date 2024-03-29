/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enemies_lst_callbacks_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:04:08 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 13:15:48 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

t_bool	enemy_aggro(const void *enemy, const void *game)
{
	const t_enemy		*__enemy = (const t_enemy *)enemy;
	const t_game		*__game = (const t_game *)game;

	return (
		enemy_colliding(__enemy, &__game->player.pos)
		&& is_traversable_pos(
			(t_game *)__game, &__enemy->pos, &__game->player.pos
		)
	);
}

t_bool	enemy_colliding(const void *enemy, const void *pos)
{
	const t_enemy		*__enemy = (const t_enemy *)enemy;
	const t_2d_point	*__pos = (const t_2d_point *)pos;
	const t_2d_point	dist_vec
		= ft_vec_sum(
			ft_vec_opposite(__enemy->pos),
			*__pos
			);

	return (
		__enemy->health > 0
		&& ft_vec_norm(dist_vec) <= __enemy->collision_radius
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
