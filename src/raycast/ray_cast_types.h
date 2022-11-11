/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_types.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:37:23 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/11 12:25:41 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_TYPES_H
# define RAYCAST_TYPES_H

# include "../types.h"

typedef enum e_side
{
	e_HORIZONTAL,
	e_VERTICAL,
	e_SIDE_NONE
}	t_side;

typedef struct s_raycast_return
{
	t_2d_point	hit_point;//*	exact coordinate where we hit the square corresponding a wall
	t_2d_point	square;
	t_side		side;
	t_fixed		angle_of_incidence;//*	maybe we won't need this
	t_fixed		euclidean_dist;
	t_fixed		perp_dist;
}	t_raycast_return;

typedef struct s_raycast_data
{
	t_2d_point	ray_dir;
	t_fixed		delta_x;
	t_fixed		delta_y;
	int			step_x;
	int			step_y;
	int			cur_sq_x;
	int			cur_sq_y;
	t_fixed		dist_nhp_through_x;
	t_fixed		dist_nhp_through_y;
	t_side		side;
}	t_raycast_data;

#endif