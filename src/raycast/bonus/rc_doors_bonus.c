/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_doors_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 23:50:25 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 11:31:54 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc_bonus.h"

static void	scan_door_on_previous_tile(
				t_raycast_data *rc_data,
				const t_2d_point *pos, const t_2d_point *ray,
				t_game *game
				);
static void	add_door(
				t_raycast_data *rc_data,
				const t_2d_point *pos, const t_2d_point *ray,
				t_game *game
				);
//*		end of static declarations

void	rc_ret_set_doors(
			const t_raycast_data *rc_data,
			t_raycast_return *rc_ret
			)
{
	rc_ret->doors = rc_data->doors;
}

/**
 * @brief this function spots a new door along the path of the casted ray.
 * 
 * @param rc_data 
 * @param pos the initial position from where we cast the ray
 * @param ray the casted ray
 * @param game 
 */
void	rc_scan_door(
	t_raycast_data *rc_data,
	const t_2d_point *pos, const t_2d_point *ray,
	t_game *game
	)
{
	const t_int_2d_point	cur_square = rc_data->cur_sq;
	t_tile **const			map = game->map_handle.map;
	t_list					*door_node;

	scan_door_on_previous_tile(rc_data, pos, ray, game);
	if (e_false == rc_data->door_obstacle
		&& is_door_map_char(map[cur_square.y][cur_square.x]))
	{
		door_node = ft_lstfind(game->doors, door_pos, &cur_square);
		if (door_node && door_node->content
			&& e_false == door_front_side(
				((t_door *)door_node->content)->type, rc_data->side
			)
		)
			rc_data->door_obstacle = e_true;
		else
			add_door(rc_data, pos, ray, game);
	}
}

/**
 * @brief 
 * 
 * @param rc_data 
 * @param pos 
 * @param ray 
 * @param game 
 */
static void	scan_door_on_previous_tile(
	t_raycast_data *rc_data,
	const t_2d_point *pos, const t_2d_point *ray,
	t_game *game
	)
{
	t_tile **const			map = game->map_handle.map;
	t_list					*door_node;

	if (is_door_map_char(map[rc_data->prev_sq.y][rc_data->prev_sq.x]))
	{
		door_node = ft_lstfind(game->doors, door_pos, &rc_data->prev_sq);
		if (door_node && door_node->content
			&& e_false == door_front_side(
				((t_door *)door_node->content)->type,
				rc_data->side
			)
		)
			rc_data->door_obstacle = e_true;
		else if (is_floor_map_char(map[rc_data->cur_sq.y][rc_data->cur_sq.x]))
			add_door(rc_data, pos, ray, game);
	}
}

/**
 * @brief 
 * 
 * @param rc_data 
 * @param pos 
 * @param ray 
 * @param game 
 * @return void true iff the front side of the door hit is closed or ajar.
 */
static void	add_door(
	t_raycast_data *rc_data,
	const t_2d_point *pos, const t_2d_point *ray,
	t_game *game
	)
{
	t_spotted_door	*spotted_door_data;

	spotted_door_data = new_spotted_door_data(rc_data, pos, ray, game);
	if (spotted_door_data)
	{
		ft_lstadd_front(&rc_data->doors, ft_lstnew(NULL, spotted_door_data));
		if (spotted_door_data->door_ref->status == e_DOOR_CLOSED)
			rc_data->door_obstacle = e_true;
	}
}
