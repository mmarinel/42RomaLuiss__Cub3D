/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:35:54 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/23 10:43:27 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_drawing.h"


static void	bresenham_algo(t_int_2d_point vfirst, t_int_2d_point vlast,
			t_data *img_data, t_px_row row);
//*		end of static declarations

void	bresenham_plot(t_int_2d_point v_1, t_int_2d_point v_2,
			t_data *img_data, t_px_row row)
{
	t_int_2d_point		vfirst;
	t_int_2d_point		vlast;

	bres_order_pts(v_1, v_2, &vfirst, &vlast);
	bresenham_algo(vfirst, vlast, img_data, row);
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
			t_data *img_data, t_px_row row)
{
	const size_t			norm_delta_x = abs(vlast.x - vfirst.x);
	const size_t			norm_delta_y = abs(vlast.y - vfirst.y);
	int						d_k;//*		the decision variable
	t_int_2d_point			cur_point;
	t_bres_line_type		bres_type;

	bres_type = bres_get_type(vfirst, vlast, norm_delta_x, norm_delta_y);
	d_k = bres_decision_var_initial(norm_delta_x, norm_delta_y, bres_type);
	cur_point = vfirst;
	bres_put_next_px(img_data, cur_point, &row);
	while (e_false == bres_eol(cur_point, vlast, bres_type))
	{
		d_k = bres_update_decision_var(
			bres_type, d_k, norm_delta_x, norm_delta_y
		);
		cur_point = bres_next_point(d_k, cur_point, bres_type);
		bres_put_next_px(img_data, cur_point, &row);
	}
}
