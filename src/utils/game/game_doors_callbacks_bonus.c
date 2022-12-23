/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_doors_callbacks_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:26:21 by earendil          #+#    #+#             */
/*   Updated: 2022/12/23 19:54:29 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

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

t_bool	is_spotted_door_valicable(const void *door, const void *end_tile)
{
	const t_spotted_door	*__door = (const t_spotted_door *)door;
	const t_int_2d_point	*__end_tile = (const t_int_2d_point *)end_tile;

	return (
		e_DOOR_OPEN == __door->door_ref->status
		&& ft_int_2d_point_equals(&__door->door_ref->pos, __end_tile)
		&& door_front_side(__door->door_ref->type, __door->rc_data.side)
	);
}
