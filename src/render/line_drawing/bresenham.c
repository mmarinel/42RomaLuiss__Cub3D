/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:35:54 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/04 19:30:48 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_drawing.h"

static void	bresenham_algo(t_int_2d_point vfirst, t_int_2d_point vlast,
			t_data *img_data, t_color color);
//*		end of static declarations

//**			VECCHIO
// void	bresenham_plot(t_int_2d_point v_1, t_int_2d_point v_2,
// 			t_data *img_data, t_color color)
//**			VECCHIO
void	bresenham_plot(const t_int_2d_point endpoint[2],
			t_data *canvas_data, next_pixel_f next_pixel, void *arg)
{
	t_int_2d_point		vfirst;
	t_int_2d_point		vlast;

	bres_order_pts(endpoint[0], endpoint[1], &vfirst, &vlast);
	bresenham_algo(vfirst, vlast, canvas_data, color);
}

/**
 * @brief this function implements the bresenham line drawing algorithm
 * for lines with equation y = m * x + q where 0 <= m <= infinity.
 * 
 * @param vfirst 
 * @param vlast 
 * @param img_data 
 */
static void	bresenham_algo(t_int_2d_point vfirst, t_int_2d_point vlast,
			t_data *img_data, t_color color)
{
	const size_t			norm_delta_x = abs(vlast.x - vfirst.x);
	const size_t			norm_delta_y = abs(vlast.y - vfirst.y);
	int						d_k;//*		the decision variable
	t_int_2d_point			cur_point;
	t_bres_line_type		bres_type;

	bres_type = bres_get_type(vfirst, vlast, norm_delta_x, norm_delta_y);
	d_k = bres_decision_var_initial(norm_delta_x, norm_delta_y, bres_type);
	cur_point = vfirst;
	bres_put_next_px(img_data, cur_point, color);
	while (e_false == bres_eol(cur_point, vlast, bres_type))
	{
		d_k = bres_update_decision_var(
			bres_type, d_k, norm_delta_x, norm_delta_y
		);
		cur_point = bres_next_point(d_k, cur_point, bres_type);
		bres_put_next_px(img_data, cur_point, color);
	}
}
