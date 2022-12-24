/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_items_lst_callbacks_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:14:48 by earendil          #+#    #+#             */
/*   Updated: 2022/12/24 20:16:58 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

/**
 * @brief [domain rule]: there cannot be two items in the same position.
 * 
 * @param item1 
 * @param item2 
 * @return t_bool 
 */
t_bool	item_pos(const void *item, const void *pos)
{
	const t_item			*__item = (const t_item *)item;
	const t_int_2d_point	*__pos = (const t_int_2d_point *)pos;

	return (
		e_true == ft_int_2d_point_equals(
			&(t_int_2d_point){floor(__item->pos.x), floor(__item->pos.y)},
			__pos
		)
	);
}
