/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:37:23 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/11 12:53:37 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_TYPES_H
# define RAYCAST_TYPES_H

# include "../types.h"

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

typedef struct s_raycast_return
{
	t_2d_point		hit_point;//*	exact coordinate where we hit the square corresponding a wall
	t_int_2d_point	square;
	t_side			side;
	t_2d_point		ray;
	t_ray_dir		view_forw_direction;
	t_ray_dir		view_side_direction;
	float			euclidean_dist;
	float			perp_dist;
}	t_raycast_return;

typedef struct s_raycast_data
{
	t_2d_point	ray;
	t_2d_point	ray_dir;
	float		delta_x;
	float		delta_y;
	int			step_x;
	int			step_y;
	int			cur_sq_x;
	int			cur_sq_y;
	float		dist_nhp_through_x;
	float		dist_nhp_through_y;
	t_side		side;
}	t_raycast_data;

#endif