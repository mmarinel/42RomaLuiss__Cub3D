/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 11:28:34 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/13 11:37:51 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_TYPES_H
# define RENDER_TYPES_H

# include "../types.h"
# include "../raycast/raycast_module.h"

typedef struct s_render_data
{
	const t_raycast_return	rc_ret;
	const size_t			wll_px_width;
	const size_t			wll_px_height;
	const size_t			wll_out_bounds_pxs;
	const float				wll_cam_angle;
}	t_render_data;

#endif