/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_enemies_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:53:44 by earendil          #+#    #+#             */
/*   Updated: 2022/12/23 14:57:29 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc_bonus.h"

static t_spotted_enemy	spot_enemy(
			const t_raycast_data *rc_data,
			const t_int_2d_point *pos,
			t_game *game
			);
//*		end of static declarations

void	rc_ret_set_enemy(
	const t_raycast_data* rc_data,
	t_raycast_return *rc_ret
	)
{
	rc_ret->spotted_enemy = rc_data->spotted_enemy;
}

/**
 * @brief this function spots a new enemy along the path of the casted ray.
 * 
 * @param rc_data 
 * @param game 
 */
void	rc_scan_enemy(
	t_raycast_data *rc_data,
	t_game *game
	)
{
	t_spotted_door	*last_door;
	t_list			*door_node;

	door_node = rc_data->doors;//ft_lstlast(rc_data->doors);
	if (door_node)
		last_door = (t_spotted_door *)door_node->content;
	else
		last_door = NULL;
	if (NULL == last_door || last_door->door_ref->status != e_DOOR_CLOSED)
		rc_data->spotted_enemy = spot_enemy(
			rc_data,
			&rc_data->cur_sq,
			game
		);
}

static t_spotted_enemy	spot_enemy(
			const t_raycast_data *rc_data,
			const t_int_2d_point *pos,
			t_game *game
			)
{
	if (rc_data->spotted_enemy.enemy)
		return (rc_data->spotted_enemy);
	else
		return (
			(t_spotted_enemy){
				get_enemy(pos, game),
				perp_calc(euclid_calc(rc_data), rc_data)
				}
		);
}
