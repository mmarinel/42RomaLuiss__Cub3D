/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:37:23 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/19 23:54:18 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_TYPES_H
# define RAYCAST_TYPES_H

# include "../utils/utils_module.h"
# include "../game_types.h"

typedef enum e_ray_dir
{
	e_RAY_NORTH = 1,
	e_RAY_SOUTH = 0,
	e_RAY_EAST = 0,
	e_RAY_WEST = 1,
}	t_ray_dir;

typedef enum e_side
{
	e_HORIZONTAL,
	e_VERTICAL,
	e_SIDE_NONE
}	t_side;

typedef struct s_spotted_enemy
{
	t_enemy	*enemy;
	float	perp_dist;
}	t_spotted_enemy;

typedef struct s_rc_ret_data
{
	t_2d_point		hit_point;//*	exact coordinate where we hit the square corresponding a wall
	t_int_2d_point	square;
	t_side			side;
	t_2d_point		ray;
	t_ray_dir		view_forw_direction;
	t_ray_dir		view_side_direction;
	float			euclidean_dist;
	float			perp_dist;
}	t_rc_ret_data;

typedef struct s_raycast_return
{
	t_rc_ret_data	wall;
	t_list			*doors;
	t_spotted_enemy	spotted_enemy;
}	t_raycast_return;

typedef struct s_raycast_data
{
	t_2d_point		ray;
	t_2d_point		ray_dir;
	float			delta_x;
	float			delta_y;
	int				step_x;
	int				step_y;
	t_int_2d_point	cur_sq;
	float			dist_nhp_through_x;
	float			dist_nhp_through_y;
	t_spotted_enemy	spotted_enemy;
	t_list			*doors;
	t_side			side;
}	t_raycast_data;

#endif