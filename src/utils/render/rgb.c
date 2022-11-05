/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:10:38 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/05 18:56:16 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

size_t	ft_get_mlx_color(t_color color)
{
	return (
		color.blue
		+ pow(2, 8) * color.green
		+ pow(2, 16) * color.red
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
