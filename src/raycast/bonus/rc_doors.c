/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_doors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:50:25 by earendil          #+#    #+#             */
/*   Updated: 2022/12/20 00:46:01 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc_bonus.h"

static t_rc_ret_data *new_door_data(
	const t_raycast_data *rc_data,
	const t_2d_point *ray,
	t_game *game
	);
//*		end of static declarations

void	add_door(
	t_raycast_data *rc_data,
	const t_2d_point *ray,
	t_game *game
	)
{
	t_rc_ret_data	*door_data;

	door_data = new_door_data(rc_data, ray, game);
	if (door_data)
		ft_lstadd_front(
			&rc_data->doors,
			ft_lstnew(NULL, door_data)
			);
}

static t_rc_ret_data *new_door_data(
	const t_raycast_data *rc_data,
	const t_2d_point *ray,
	t_game *game
	)
{
	t_rc_ret_data	*door_data;

	door_data = (t_rc_ret_data *) malloc(sizeof(t_rc_ret_data));
	if (NULL == door_data)
		return (NULL);
	rc_ret_set_data(rc_data, door_data, ray, game);//TODO		CAMBIARE ORDINE PARAMETRI
	return (door_data);
}
