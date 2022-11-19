/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 15:35:54 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/19 16:20:16 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_drawing.h"

static	int	update_decision_var(int low_or_high, int d_k,
				const size_t delta_x, const size_t delta_y);
//*		end of static declarations

void	bresenham_algo(t_2d_point vfirst, t_2d_point vlast,
			t_data *img_data, int *px)
{
	const size_t		delta_x = vlast.x - vfirst.x;
	const size_t		delta_y = vlast.y - vfirst.y;
	int					d_k;//*		the decision variable
	t_2d_point			cur_point;
	t_bres_line_type	bres_line_type = (delta_y > delta_x);

	d_k = decision_var_initial(delta_x, delta_y, bres_line_type);
	cur_point = vfirst;
	// ft_put
}

/**
 * @brief this function implements the bresenham line drawing algorithm
 * for lines with equation y = m * x + q where m > 1.
 * 
 * @param vfirst 
 * @param vlast 
 * @param img_data 
 */
void	bresenham_high_line(t_2d_point vfirst, t_2d_point vlast,
			t_data *img_data)
{
	const size_t	delta_x = vlast.x - vfirst.x;
	const size_t	delta_y = vlast.y - vfirst.y;
	int				d_k;//*		the decision variable
	t_2d_point		cur_point;

	d_k = delta_y - 2 * delta_x;
	cur_point = vfirst;
	ft_put_px_to_image(img_data, ft_get_pixel_offset(*img_data, cur_point), 65280);
	while (cur_point.y != vlast.y)
	{
		d_k = update_decision_var(2, d_k, delta_x, delta_y);
		if (d_k < 0)
		{
			cur_point.x += 1;
			cur_point.y += 1;
		}
		else
		{
			cur_point.y += 1;
		}
		ft_put_px_to_image(img_data, ft_get_pixel_offset(*img_data, cur_point), 65280);
	}
}

/**
 * @brief this function implements the bresenham line drawing algorithm
 * for lines with equation y = m * x + q where m <= 1.
 * 
 * @param vfirst 
 * @param vlast 
 * @param img_data 
 */
void	bresenham_low_line(t_2d_point vfirst, t_2d_point vlast,
			t_data *img_data)
{
	const size_t	delta_y = vlast.y - vfirst.y;
	const size_t	delta_x = vlast.x - vfirst.x;
	int				d_k;//*		Decision variable
	t_2d_point		cur_point;

	d_k = 2 * delta_y - delta_x;
	cur_point = vfirst;
	ft_put_px_to_image(img_data, ft_get_pixel_offset(*img_data, cur_point), 16711680);
	while (cur_point.x != vlast.x)
	{
		d_k = update_decision_var(1, d_k, delta_x, delta_y);
		if (d_k >= 0)
		{
			cur_point.x += 1;
			cur_point.y += 1;
		}
		else
		{
			cur_point.x += 1;
		}
		ft_put_px_to_image(img_data, ft_get_pixel_offset(*img_data, cur_point), 16711680);
	}
}

static	int	update_decision_var(int low_or_high, int d_k,
					const size_t delta_x, const size_t delta_y)
{
	if (1 == low_or_high)//*		LOW
	{
		if (d_k >= 0)
			d_k += (2 * (delta_y  - delta_x));
		else
			d_k += (2 * delta_y);
		return (d_k);
	}
	else if (2 == low_or_high)//*		HIGH
	{
		if (d_k >= 0)
			d_k -= (2 * delta_x);
		else
			d_k -= (2 * (delta_x  - delta_y));
		return (d_k);
	}
	else
		return (-1);
}
