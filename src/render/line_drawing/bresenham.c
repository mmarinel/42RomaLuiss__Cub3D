/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:35:54 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/19 19:01:46 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_drawing.h"

/**
 * @brief this function implements the bresenham line drawing algorithm
 * for lines with equation y = m * x + q where 0 <= m <= infinity.
 * 
 * @param vfirst 
 * @param vlast 
 * @param img_data 
 */
void	bresenham_algo(t_2d_point vfirst, t_2d_point vlast,
			t_data *img_data, t_px_row row)
{
	const size_t		delta_x = vlast.x - vfirst.x;
	const size_t		delta_y = vlast.y - vfirst.y;
	int					d_k;//*		the decision variable
	t_2d_point			cur_point;
	t_bres_line_type	bres_type = (delta_y > delta_x);

	d_k = decision_var_initial(delta_x, delta_y, bres_type);
	cur_point = vfirst;
	printf(GREEN "ciaoooooooooooo" RESET);
	put_next_px(img_data, cur_point, &row);
	exit(0);
	printf(GREEN "ciaoooooooooooo" RESET);
	while (e_false == bres_eol(cur_point, vlast, bres_type))
	{
		d_k = update_decision_var(bres_type, d_k, delta_x, delta_y);
		cur_point = bres_next_point(d_k, cur_point, bres_type);
		put_next_px(img_data, cur_point, &row);
	}
}
