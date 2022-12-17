/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_enemies.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:53:44 by earendil          #+#    #+#             */
/*   Updated: 2022/12/17 17:16:27 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc_bonus.h"

void	rc_ret_set_enemy(
	const t_raycast_data* rc_data,
	t_raycast_return *rc_ret
	)
{
	rc_ret->spotted_enemy = rc_data->spotted_enemy;
}

t_spotted_enemy	spot_enemy(
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
