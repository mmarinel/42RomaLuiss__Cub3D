/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_doors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:50:25 by earendil          #+#    #+#             */
/*   Updated: 2022/12/20 14:41:55 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc_bonus.h"

static t_spotted_door *new_spotted_door_data(
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
	t_spotted_door	*spotted_door_data;

	spotted_door_data = new_spotted_door_data(rc_data, ray, game);
	if (spotted_door_data)
		ft_lstadd_front(
			&rc_data->doors,
			ft_lstnew(NULL, spotted_door_data)
			);
}

static t_spotted_door *new_spotted_door_data(
	const t_raycast_data *rc_data,
	const t_2d_point *ray,
	t_game *game
	)
{
	t_spotted_door	*door_data;
	t_list			*door_node;

	door_data = (t_spotted_door *) malloc(sizeof(t_spotted_door));
	if (NULL == door_data)
		return (NULL);
	rc_ret_set_data(rc_data, &door_data->rc_data, ray, game);//TODO		CAMBIARE ORDINE PARAMETRI
	door_node = ft_lstfind(game->doors, door_pos, &rc_data->cur_sq);
	if (door_node)
		door_data->door_ref = (t_door *)door_node->content;
	else
		door_data->door_ref = NULL;
	return (door_data);
}
