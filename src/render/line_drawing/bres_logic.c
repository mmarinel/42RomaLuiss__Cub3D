/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bres_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 18:15:29 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/06 12:17:49 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_drawing.h"

static int	bres_get_increment_factor(t_bres_line_type bres_type);
//*		end of static declarations

t_bres_line_type	bres_get_type(t_int_2d_point vfirst, t_int_2d_point vlast,
						const size_t norm_delta_x, const size_t norm_delta_y)
{
	const int	delta_x = vlast.x - vfirst.x;
	const int	delta_y = vlast.y - vfirst.y;
	int			sign;

	sign = get_angular_coefficient_sign(delta_x, delta_y,
				norm_delta_x, norm_delta_y);
	if (norm_delta_y <= norm_delta_x)
	{
		if (1 == sign)
			return (e_BRES_LOW_POS);
		else
			return (e_BRES_LOW_NEG);
	}
	else
	{
		if (1 == sign)
			return (e_BRES_HIGH_POS);
		else
			return (e_BRES_HIGH_NEG);
	}
}

void	bres_put_next_px(
			t_data *canvas_data,
			t_next_pixel_f next_pixel_f, t_nxt_px_f_arg *arg
		)
{
	ft_put_mlxpx_to_image(
		canvas_data,
		ft_get_pixel_offset(*canvas_data, *arg->cur_px),
		(*next_pixel_f)(arg)
	);
	// t_color	color = (t_color){ *( (int *)row->texture + row->img_offset ), 0, 0, 0.0f};
	// t_color	fake = (t_color){0, 0, 255, 0.0f};

	// printf("%d %d %d\n",
	// 	color.red,
	// 	color.green,
	// 	color.blue
	// );
	// printf("mlx_color: %zu\n", ft_get_mlx_color(color));
	// exit(0);
	// (void) color;
	// (void) fake;
	// (void) img_data;
	// (void) cur_point;
	// (void) row;
	//**
	// ft_put_px_to_image(
	// 	img_data,
	// 	ft_get_pixel_offset(*img_data, cur_point),
	// 	color
	// );
	//*
	//!		FOR TESTING PURPOSES
	// row->img_offset = (row->img_offset + 1) % row->len;
	// return (*row);
}

t_bool	bres_eol(t_int_2d_point cur_point, t_int_2d_point vlast,
			t_bres_line_type bres_type)
{
	if (e_BRES_LOW_POS ==  bres_type || e_BRES_LOW_NEG == bres_type)
		return (cur_point.x == vlast.x);
	else
		return (cur_point.y == vlast.y);
}

t_int_2d_point		bres_next_point(int d_k,
					t_int_2d_point cur_point, t_bres_line_type bres_type)
{
	if (e_BRES_LOW_POS == bres_type || e_BRES_LOW_NEG == bres_type)
	{
		if (d_k >= 0)
		{
			cur_point.y += bres_get_increment_factor(bres_type);
			cur_point.x += 1;
		}
		else
			cur_point.x += 1;
	}
	else
	{
		if (d_k < 0)
		{
			cur_point.x += 1;
			cur_point.y += bres_get_increment_factor(bres_type);
		}
		else
			cur_point.y += bres_get_increment_factor(bres_type);
	}
	return (cur_point);
}

static int	bres_get_increment_factor(t_bres_line_type bres_type)
{
	if (e_BRES_LOW_NEG == bres_type
		|| e_BRES_HIGH_NEG == bres_type)
		return (-1);
	else
		return (+1);
}
