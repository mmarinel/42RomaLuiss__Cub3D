/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_memory_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 17:38:09 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 11:39:41 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc_bonus.h"

static void	set_door_ref(
				t_spotted_door *door_data,
				const t_raycast_data *rc_data, t_game *game
				);
//*		end of static declarations

t_spotted_door	*new_spotted_door_data(
					const t_raycast_data *rc_data,
					const t_2d_point *pos, const t_2d_point *ray,
					t_game *game
					)
{
	t_spotted_door	*door_data;

	door_data = (t_spotted_door *) malloc(sizeof(t_spotted_door));
	if (NULL == door_data)
		return (NULL);
	rc_ret_set_data(&door_data->rc_data, rc_data, pos, ray);
	set_door_ref(door_data, rc_data, game);
	return (door_data);
}

static void	set_door_ref(
	t_spotted_door *door_data,
	const t_raycast_data *rc_data, t_game *game
	)
{
	t_list	*door_node;

	door_node = ft_lstfind(game->doors, door_pos, &rc_data->cur_sq);
	if (door_node)
		door_data->door_ref = (t_door *)door_node->content;
	else
	{
		door_node = ft_lstfind(game->doors, door_pos, &rc_data->prev_sq);
		if (door_node)
			door_data->door_ref = (t_door *)door_node->content;
		else
			door_data->door_ref = NULL;
	}
}
