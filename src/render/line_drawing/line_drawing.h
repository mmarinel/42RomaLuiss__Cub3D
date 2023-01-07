/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:33:54 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/07 12:39:06 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_DRAWING_H
# define LINE_DRAWING_H

# include "../../includes/colors.h"

# include "../../utils/utils_module.h"
# include "line_drawing_types.h"
# include "../render.h"

# include "../../includes/sys_includes.h"

//*		bresenham helper functions

t_bres_line_type	bres_get_type(t_int_2d_point vfirst, t_int_2d_point vlast,
						const size_t norm_delta_x, const size_t norm_delta_y);
int					bres_update_decision_var(t_bres_line_type bres_type, int d_k,
						const size_t delta_x, const size_t delta_y);
void				bres_put_next_px(t_data *canvas_data,
						t_next_pixel_f next_pixel_f, t_nxt_px_f_arg *arg);
t_bool				bres_eol(t_int_2d_point cur_point, t_int_2d_point vlast,
						t_bres_line_type bres_type);
int					bres_decision_var_initial(
						const size_t delta_x,
						const size_t delta_y,
						t_bres_line_type bres_type
					);
t_int_2d_point		bres_next_point(int d_k,
						t_int_2d_point cur_point, t_bres_line_type bres_type);
int					get_angular_coefficient_sign(int delta_x, int delta_y,
						const size_t norm_delta_x, const size_t norm_delta_y);
void				bres_order_pts(t_int_2d_point endpoints[2]);

#endif