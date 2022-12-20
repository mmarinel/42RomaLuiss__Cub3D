/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_doors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:30:03 by earendil          #+#    #+#             */
/*   Updated: 2022/12/20 14:31:42 by earendil         ###   ########.fr       */
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
