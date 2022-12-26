/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend_ent_callbacks_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:19:21 by earendil          #+#    #+#             */
/*   Updated: 2022/12/26 02:08:24 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rend_bonus.h"

t_bool	rend_enemy_spotted(const void *cur, const void *enemy)
{
	const t_rendered_entity	*__cur = (const t_rendered_entity *)cur;
	const t_enemy			*__enemy = (const t_enemy *)enemy;

	return (
		__enemy
		&& e_ENT_ENEMY == __cur->which
		&& enemy_equals(__cur->entity, __enemy)
	);
}

t_bool	rend_item_spotted(const void *cur, const void *item)
{
	const t_rendered_entity	*__cur = (const t_rendered_entity *)cur;
	const t_item			*__item = (const t_item *)item;

	return (
		__item
		&& e_ENT_ITEM == __cur->which
		&& item_equals(__cur->entity, __item)
	);
}

/**
 * @brief the farthest objects need to be drawn first
 * 
 * @param ent_1 
 * @param ent_2 
 * @return t_bool 
 */
t_bool	rendent_greater_than(const void *ent_1, const void *ent_2)
{
	const t_rendered_entity	*__ent_1 = (const t_rendered_entity *)ent_1;
	const t_rendered_entity	*__ent_2 = (const t_rendered_entity *)ent_2;

	return (
		__ent_1->min_perp_dist < __ent_2->min_perp_dist
	);
}
