/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_doors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:30:03 by earendil          #+#    #+#             */
/*   Updated: 2022/12/24 13:05:01 by earendil         ###   ########.fr       */
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

//TODO		ELIMINARE FUNZIONE !!!!!
//TODO		rimuovere end_tile
t_bool	door_obstacle_through_dir(t_list *spotted_doors, const t_int_2d_point *end_tile)
{(void)end_tile;
	return (
		spotted_doors
		&& ft_lstfind(spotted_doors, is_spotted_door_invalicable, NULL)
		// && NULL == ft_lstfind(
		// 	// spotted_doors, is_spotted_door_valicable_in_tile, end_tile
		// 	spotted_doors, is_spotted_door_valicable, end_tile
		// 	)
	);
}
