/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_doors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:30:03 by earendil          #+#    #+#             */
/*   Updated: 2022/12/23 13:32:46 by earendil         ###   ########.fr       */
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

t_bool	door_obstacle_through_dir(t_list *spotted_doors, const t_int_2d_point *end_tile)
{
	return (
		spotted_doors
		&& NULL == ft_lstfind(
			spotted_doors, is_spotted_door_valicable, end_tile
			)
	);
}
