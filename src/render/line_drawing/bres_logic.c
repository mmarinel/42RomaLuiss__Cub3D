/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:15:29 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/19 19:18:28 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_drawing.h"

int	decision_var_initial(
		const size_t delta_x,
		const size_t delta_y,
		t_bres_line_type bres_type
	)
{
	if (e_BRES_LOW == bres_type)
		return (2 * delta_y - delta_x);
	else
		return (delta_y - 2 * delta_x);
}

t_px_row	put_next_px(t_data *img_data, t_2d_point cur_point,
		t_px_row *row)
{
	t_color	color = (t_color){ *( (char *)row->texture + row->img_offset * sizeof(char) ), 0, 0, 0.0f};
	t_color	fake = (t_color){0, 0, 255, 0.0f};

	(void) color;
	(void) fake;
	(void) img_data;
	(void) cur_point;
	(void) row;
	ft_put_px_to_image(
		img_data,
		ft_get_pixel_offset(*img_data, cur_point),
		color
	);
	//!		FOR TESTING PURPOSES
	row->img_offset = (row->img_offset + 1) % row->len;
	return (*row);
}

t_bool	bres_eol(t_2d_point cur_point, t_2d_point vlast,
			t_bres_line_type bres_type)
{
	if (e_BRES_LOW ==  bres_type)
		return (cur_point.x == vlast.x);
	else
		return (cur_point.y == vlast.y);
}

int	update_decision_var(t_bres_line_type bres_type, int d_k,
				const size_t delta_x, const size_t delta_y)
{
	if (e_BRES_LOW == bres_type)
	{
		if (d_k >= 0)
			d_k += (2 * (delta_y  - delta_x));
		else
			d_k += (2 * delta_y);
		return (d_k);
	}
	else
	{
		if (d_k >= 0)
			d_k -= (2 * delta_x);
		else
			d_k -= (2 * (delta_x  - delta_y));
		return (d_k);
	}
}

t_2d_point		bres_next_point(int d_k,
					t_2d_point cur_point, t_bres_line_type bres_type)
{
	if (e_BRES_LOW == bres_type)
	{
		if (d_k >= 0)
		{
			cur_point.y += 1;
			cur_point.x += 1;
		}
		else
		{
			cur_point.x += 1;
		}
	}
	else
	{
		if (d_k < 0)
		{
			cur_point.x += 1;
			cur_point.y += 1;
		}
		else
		{
			cur_point.y += 1;
		}
	}
	return (cur_point);
}
