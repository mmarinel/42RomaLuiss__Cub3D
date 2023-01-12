/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:35:54 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/12 16:30:26 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_drawing.h"

static void	bresenham_algo(
				t_int_2d_point verts[2],
				t_data *canvas_data,
				t_next_pixel_f next_pixel_f, t_nxt_px_f_arg *nxt_px_f_arg
				);
//*		end of static declarations

//**			VECCHIO
// void	bresenham_plot(t_int_2d_point v_1, t_int_2d_point v_2,
// 			t_data *img_data, t_color color)
//**			VECCHIO
/**
 * @brief this function draws a segment delimited by two endpoints
 * using bresengam line drawing algorithm
 * 
 * @param endpoints the two endpointss
 * @param canvas_data the image on which to draw
 * @param next_pixel function that prints the next pixel on the segment
 * @param arg the argument to pass on each call to the next_pixel function
 */
void	bresenham_plot(t_int_2d_point endpoints[2],
			t_data *canvas_data, t_next_pixel_f next_pixel, t_nxt_px_f_arg *arg)
{
	bres_order_pts(endpoints);
	bresenham_algo(endpoints, canvas_data, next_pixel, arg);
}

/**
 * @brief this function implements the bresenham line drawing algorithm
 * for lines with equation y = m * x + q where 0 <= m <= infinity.
 * 
 * @param verts the ordered set of vertices that defines
 * the segment to be drawn
 * @param canvas_data the image on which to draw
 * @param next_pixel function that prints the next pixel on the segment
 * @param arg the argument to pass on each call to the next_pixel function
 */
static void	bresenham_algo(
				t_int_2d_point verts[2],
				t_data *canvas_data,
				t_next_pixel_f next_pixel_f, t_nxt_px_f_arg *nxt_px_f_arg
				)
{
	const size_t			norm_delta_x = abs(verts[1].x - verts[0].x);
	const size_t			norm_delta_y = abs(verts[1].y - verts[0].y);
	int						d_k;
	t_int_2d_point			cur_point;
	t_bres_line_type		bres_type;

	nxt_px_f_arg->cur_px = &cur_point;
	bres_type = bres_get_type(verts[0], verts[1], norm_delta_x, norm_delta_y);
	d_k = bres_decision_var_initial(norm_delta_x, norm_delta_y, bres_type);
	cur_point = verts[0];
	bres_put_next_px(canvas_data, next_pixel_f, nxt_px_f_arg);
	while (e_false == bres_eol(cur_point, verts[1], bres_type))
	{
		d_k = bres_update_decision_var(
				bres_type, d_k, norm_delta_x, norm_delta_y
				);
		cur_point = bres_next_point(d_k, cur_point, bres_type);
		bres_put_next_px(canvas_data, next_pixel_f, nxt_px_f_arg);
	}
}
//*		dk is the decision variable
