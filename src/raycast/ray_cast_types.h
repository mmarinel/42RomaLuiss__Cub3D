/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_types.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:37:23 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/06 15:46:05 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_TYPES_H
# define RAYCAST_TYPES_H

# include "../types.h"

typedef enum e_side
{
	e_HORIZONTAL,
	e_VERTICAL
}	t_side;

typedef struct s_raycast_return
{
	t_2d_point	hit_point;//*	exact coordinate where we hit the square corresponding a wall
	t_2d_point	square;
	t_side		side;
	double		angle_of_incidence;//*	maybe we won't need this
	double		euclidean_dist;
	double		perp_dist;
}	t_raycast_return;

#endif