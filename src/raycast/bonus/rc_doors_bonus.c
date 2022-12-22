/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_doors_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:50:25 by earendil          #+#    #+#             */
/*   Updated: 2022/12/22 17:38:27 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc_bonus.h"

static void				add_door(
	t_raycast_data *rc_data,
	const t_2d_point *ray,
	t_game *game
	);
//*		end of static declarations

void	rc_ret_set_doors(
	const t_raycast_data* rc_data,
	t_raycast_return *rc_ret
	)
{
	rc_ret->doors = rc_data->doors;
}

void	rc_scan_door(
	t_raycast_data *rc_data,
	const t_2d_point *ray,
	t_game *game
	)
{
	if (
		is_door_map_char(game->map_handle\
			.map[rc_data->cur_sq.y][rc_data->cur_sq.x]
			)
	)
		add_door(rc_data, ray, game);
}

/**
 * @brief this function returns true iff we hit the side of a door
 * 
 * @param prev_square 
 * @param rc_data 
 * @param game 
 * @return t_bool 
 */
t_bool	rc_door_wall_hit(
	const t_int_2d_point *prev_square,
	const t_raycast_data *rc_data,
	t_game *game
	)
{
	t_list	*door_node;
	t_door	*door;

	if (is_door_map_char(game->map_handle\
		.map[prev_square->y][prev_square->x])
		)
	{
		door_node = ft_lstfind(game->doors, door_pos, prev_square);
		if (NULL == door_node)
			return (e_false);
		door = (t_door *)door_node->content;
		if (NULL == door)
			return (e_false);
		if (e_false == door_front_side(door->type, rc_data->side))
			return (e_true);
	}
	return (e_false);
}

static void	add_door(
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
