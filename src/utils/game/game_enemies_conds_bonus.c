/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enemies_conds_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:05:56 by earendil          #+#    #+#             */
/*   Updated: 2022/12/23 19:13:36 by earendil         ###   ########.fr       */
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
