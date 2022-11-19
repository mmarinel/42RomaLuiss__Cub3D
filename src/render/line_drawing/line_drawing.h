/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:33:54 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/19 18:44:07 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_DRAWING_H
# define LINE_DRAWING_H

# include <unistd.h>

# include "../../colors.h"
# include "../../utils/utils_module.h"
# include "line_drawing_types.h"
# include "../render.h"

//*		bresenham helper functions

int			update_decision_var(t_bres_line_type bres_type, int d_k,
				const size_t delta_x, const size_t delta_y);
t_px_row	put_next_px(t_data *img_data, t_2d_point cur_point,
				t_px_row *row);
t_bool		bres_eol(t_2d_point cur_point, t_2d_point vlast,
				t_bres_line_type bres_type);
int			decision_var_initial(
				const size_t delta_x,
				const size_t delta_y,
				t_bres_line_type bres_type
			);
t_2d_point	bres_next_point(int d_k,
				t_2d_point cur_point, t_bres_line_type bres_type);

#endif