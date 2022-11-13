/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:28:34 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/13 16:20:13 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_TYPES_H
# define RENDER_TYPES_H

# include "../types.h"
# include "../raycast/raycast_module.h"

typedef struct s_wall_camera_incidence
{
	float		angle;
	t_side		side;
	t_quadrant	raydir_quadrant;
}	t_wall_camera_incidence;


typedef struct s_render_data
{
	const t_raycast_return			rc_ret;
	const size_t					wll_px_width;
	const size_t					wll_px_height;
	const size_t					wll_out_bounds_pxs;
	const t_wall_camera_incidence	wall_camera_incidence;
}	t_render_data;

#endif