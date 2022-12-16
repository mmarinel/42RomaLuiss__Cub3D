/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing_module.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:32:55 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/16 23:17:43 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_DRAWING_MODULE_H
# define LINE_DRAWING_MODULE_H

# include "../../utils/utils_module.h"
# include "line_drawing_types.h"
# include "../render.h"

# include "../../sys_includes.h"

void	bresenham_plot(t_int_2d_point endpoints[2],
			t_data *canvas_data, t_next_pixel_f next_pixel, t_nxt_px_f_arg *arg);

#endif