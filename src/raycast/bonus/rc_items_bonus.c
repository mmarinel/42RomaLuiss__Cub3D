/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_items_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 20:07:18 by earendil          #+#    #+#             */
/*   Updated: 2022/12/24 20:21:33 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc_bonus.h"

static t_spotted_item	spot_item(
			const t_raycast_data *rc_data,
			const t_int_2d_point *pos,
			t_game *game
			);
//*		end of static declarations

void	rc_ret_set_item(
	const t_raycast_data* rc_data,
	t_raycast_return *rc_ret
	)
{
	rc_ret->spotted_item = rc_data->spotted_item;
}

void	rc_scan_item(
	t_raycast_data *rc_data,
	t_game *game
	)
{
	t_spotted_door	*last_door;
	t_list			*door_node;

	door_node = rc_data->doors;
	if (door_node)
		last_door = (t_spotted_door *)door_node->content;
	else
		last_door = NULL;
	if (NULL == last_door || last_door->door_ref->status != e_DOOR_CLOSED)
		rc_data->spotted_item = spot_item(
			rc_data,
			&rc_data->cur_sq,
			game
		);
}

static t_spotted_item	spot_item(
			const t_raycast_data *rc_data,
			const t_int_2d_point *pos,
			t_game *game
			)
{
	if (rc_data->spotted_item.item)
		return (rc_data->spotted_item);
	else
		return (
			(t_spotted_item){
				get_item(pos, game),
				perp_calc(euclid_calc(rc_data), rc_data)
				}
		);
}
