/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_doors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:30:03 by earendil          #+#    #+#             */
/*   Updated: 2022/12/22 00:00:23 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

t_bool	door_front_side(t_tile door_type, t_side side)
{
	return (
		(side == e_HORIZONTAL && door_type == e_DOOR_HORIZONTAL)
		|| (side == e_VERTICAL && door_type == e_DOOR_VERTICAL)
	);
}

t_bool	door_pos(const void *door, const void *pos)
{
	const t_door			*__door = (const t_door *)door;
	const t_int_2d_point	*__pos = (const t_int_2d_point *)pos;

	return (
		e_true == ft_int_2d_point_equals(
			&__door->pos,
			__pos
		)
	);
}
