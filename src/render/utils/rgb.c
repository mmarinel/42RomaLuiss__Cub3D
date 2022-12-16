/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:10:38 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/16 23:34:51 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uti_render.h"

t_bool	is_mlx_color(t_color color)
{
	return (
		color.alpha == 1
		&& color.red <= 255
		&& color.green <= 255
		&& color.blue <= 255
	);
}
t_bool	is_mlx_px(int px)
{
	return (
		px >= 0 && px <= (255 | (255 << 8) | (255 << 16))
	);
}

size_t	ft_get_mlx_color(t_color color)
{
	return (
		color.blue
		| color.green << 8
		| color.red << 16
		// | 1 << 24
	);
}

/**
 * @brief this function fills the color structure with the given colors
 * iff they form a valid rgb color,
 * otheriwse it fills it with fixed invalid color values.
 * 
 * @param red 
 * @param green 
 * @param blue 
 * @param color
 * @return t_bool : true iff the input colors form a valid rgb color
 */
t_bool	ft_fill_color(int red, int green, int blue, t_color *color)
{
	if (e_false == ft_iscolor(red, green, blue))
	{
		color->red = -1;
		color->green = -1;
		color->blue = -1;
		color->alpha = -1;
		return (e_false);
	}
	else
	{
		color->red = red;
		color->green = green;
		color->blue = blue;
		color->alpha = 1;
		return (e_true);
	}
}

/**
 * @brief This function returns a new color such that each of the rgb
 * components are below a fixed threshold.
 * 
 * @param color 
 * @return t_color 
 */
t_color	ft_get_normalized_color(const t_color color)
{
	t_color		normalized;
	const short	threshold = 190;
	double		factor;

	if (color.red > threshold
		|| color.green > threshold
		|| color.blue > threshold)
		factor = 0.5;
	else
		factor = 1.0;
	normalized.red = color.red * factor;
	normalized.green = color.green * factor;
	normalized.blue = color.blue * factor;
	return (normalized);
}

int	ft_rgb_normalize(int channel)
{
	if (channel < COLOR_MAX)
		return (channel);
	else
		return (COLOR_MAX);
}
