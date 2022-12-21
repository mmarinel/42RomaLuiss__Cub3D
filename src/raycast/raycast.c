/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:03:29 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/21 13:27:37 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

static void	rc_scan_door(
	t_raycast_data *rc_data,
	const t_2d_point *ray,
	t_game *game
	);
static void	rc_scan_enemy(
	t_raycast_data *rc_data,
	t_game *game
	);
static t_bool	rc_door_wall_hit(
	const t_int_2d_point *prev_square,
	const t_raycast_data *rc_data,
	t_game *game
);
//*		end of static declarations

/**
 * @brief this function casts a ray until it hits a wall
 * 
 * @param game 
 * @param ray_angle the angle the ray forms with the camera plane
 * @return t_raycast_return 
 */
t_raycast_return	raycast(t_game *game, t_2d_point ray)
{
	t_raycast_return	rc_ret;
	t_raycast_data		rc_data;
	t_bool				hit;
	t_int_2d_point		prev_square;

	ft_ray_data_init(&rc_data, ray, game);
	// ft_print_raycast_data(rc_data);
	hit = e_false;
	while (e_false == hit)
	{
		prev_square = rc_data.cur_sq;
		ft_walk_through_nhp(&rc_data);
		if (e_WALL == game->\
				map_handle.map[rc_data.cur_sq.y][rc_data.cur_sq.x]
			)
			hit = e_true;
		else if (BONUS)
		{
			hit = rc_door_wall_hit(&prev_square, &rc_data, game);
			rc_scan_door(&rc_data, &ray, game);
			rc_scan_enemy(&rc_data, game);
		}
	}
	rc_ret_set_data(&rc_data, &rc_ret.wall, &ray, game);
	// if (BONUS)
	// 	set_bonus()
	rc_ret_set_doors(&rc_data, &rc_ret);
	rc_ret_set_enemy(&rc_data, &rc_ret);
	return (rc_ret);
}

static void	rc_scan_door(
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

static void	rc_scan_enemy(
	t_raycast_data *rc_data,
	t_game *game
	)
{
	t_spotted_door	*first_door;
	t_list			*door_node;

	door_node = ft_lstlast(rc_data->doors);
	if (door_node)
		first_door = (t_spotted_door *)door_node->content;
	else
		first_door = NULL;
	if (NULL == first_door || first_door->door_ref->status != e_DOOR_CLOSED)
		rc_data->spotted_enemy = spot_enemy(
			rc_data,
			&rc_data->cur_sq,
			game
		);
}

/**
 * @brief this function returns true iff we hit the side of a door
 * 
 * @param prev_square 
 * @param rc_data 
 * @param game 
 * @return t_bool 
 */
static t_bool	rc_door_wall_hit(
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
