/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enemies_lst_callbacks_bonus.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:04:08 by earendil          #+#    #+#             */
/*   Updated: 2022/12/22 12:24:06 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

t_bool	enemy_collision(const void *enemy, const void *player_pos)
{
	const t_enemy		*__enemy = (t_enemy *)enemy;
	const t_2d_point	*__player_pos = (t_2d_point *)player_pos;
	const float			collision_radius = __enemy->collision_radius;

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
