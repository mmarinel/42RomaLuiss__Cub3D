/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_doors_callbacks_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 18:26:21 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 13:10:56 by alazzari         ###   ########.fr       */
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

t_bool	is_spotted_door_valicable(const void *door, const void *_)
{
	const t_spotted_door	*__door = (const t_spotted_door *)door;

	if (_)
	{
	}
	return (
		e_DOOR_OPEN == __door->door_ref->status
		&& door_front_side(__door->door_ref->type, __door->rc_data.side)
	);
}

t_bool	is_spotted_door_invalicable(const void *door, const void *_)
{
	const t_spotted_door	*__door = (const t_spotted_door *)door;

	if (_)
	{
	}
	return (
		e_DOOR_CLOSED == __door->door_ref->status
		|| e_DOOR_AJAR == __door->door_ref->status
		|| (e_DOOR_OPEN == __door->door_ref->status
			&& e_false == door_front_side(
				__door->door_ref->type, __door->rc_data.side
			)
		)
	);
}
