/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   E_key_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:23:29 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 21:36:20 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys_behavior.h"

static void		open_close_doors(t_game *game);
static t_bool	door_reached(t_door *door, float ray_angle, t_game *game);
static void		open_close_door(t_door *door);
//*		end of static declarations

void	e_key_handler(t_game *game)
{
	open_close_doors(game);
}

static void	open_close_doors(t_game *game)
{
	const float			range = M_PI / 4;
	t_list				*door_node;

	door_node = game->doors;
	while (door_node)
	{
		if (
			door_reached(door_node->content, 2 * M_PI - range / 2, game)
			|| door_reached(door_node->content, 0, game)
			|| door_reached(door_node->content, range / 2, game)
		)
			open_close_door(door_node->content);
		door_node = door_node->next;
	}
}

static t_bool	door_reached(t_door *door, float ray_angle, t_game *game)
{
	const t_2d_point		ray = ft_rotate(game->player.dir, ray_angle);
	t_bool					reached;
	t_list					*first_spotted_door_node;
	t_spotted_door			*first_spotted_door;
	t_raycast_return		rc_ret;

	rc_ret = raycast(game, game->player.pos, ray, (t_int_2d_point){-1, -1});
	first_spotted_door_node = ft_lstlast(rc_ret.doors);
	if (NULL == first_spotted_door_node)
		return (e_false);
	first_spotted_door = first_spotted_door_node->content;
	reached = (
		first_spotted_door && first_spotted_door->door_ref
		&& ft_int_2d_point_equals(
			&first_spotted_door->door_ref->pos, &door->pos
			)
		&& first_spotted_door->\
			rc_data.euclidean_dist <= game->player.action_range
	);
	raycast_clean(&rc_ret);
	return (reached);
}

static void		open_close_door(t_door *door)
{
	if (e_DOOR_CLOSED == door->status
		|| e_DOOR_OPEN == door->status)
	{
		door->prev_status = door->status;
		door->status = e_DOOR_AJAR;
	}
}
