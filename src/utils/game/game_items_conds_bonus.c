/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_items_conds_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:43:46 by earendil          #+#    #+#             */
/*   Updated: 2022/12/24 20:43:57 by earendil         ###   ########.fr       */
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
t_bool	item_equals(const t_item *item1, const t_item *item2)
{
	return (
		e_true == ft_2d_point_equals(&item1->pos, &item2->pos)
	);
}
