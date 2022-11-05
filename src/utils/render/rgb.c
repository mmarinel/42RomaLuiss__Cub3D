/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:10:38 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/05 13:02:14 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	ft_rgb_normalize(int channel);
//*		end of static declarations

size_t	ft_get_mlx_color(t_color color)
{
	return (
		color.blue +
		pow(2, 8) * color.green +
		pow(2, 16) * color.red
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


void	ft_adjust_brightness(t_color *color, double percentage)
{
	t_color	adjusted;
	t_color	darkest_shade;
	t_color	brightest_shade;
	const double	max_factor = ft_get_max_brightness_factor(color);

	darkest_shade = *color;
	brightest_shade = *color;
	ft_apply_brightness(&darkest_shade, max_factor);
	ft_apply_brightness(&brightest_shade, max_factor);
	adjusted = ft_color_gradient_get_shade(brightest_shade, darkest_shade, percentage);
	*color = adjusted;
}

double	ft_get_max_brightness_factor(t_color *color)
{
	double	max_factor;
	double	step = 0.01;

	max_factor = 1 + step;
	while (
		color->red * max_factor > (double) COLOR_MAX
		|| color->green * max_factor > (double) COLOR_MAX
		|| color->blue * max_factor > (double) COLOR_MAX
	)
	{
		max_factor += step;
	}
	return (max_factor);
}

/**
 * @brief this function applies brightness to the given color.
 * 
 * @param color 
 * @param factor X with X > 1 if you want to make it brighter,
 * or 1/X if you want to make it darker.
 * @return t_bool 
 */
void	ft_apply_brightness(t_color *color, double factor)
{
	const short	new_red = (int) color->red * factor;
	const short	new_green = (int) color->green * factor;
	const short	new_blue = (int) color->blue * factor;

	color->red = ft_rgb_normalize(new_red);
	color->green = ft_rgb_normalize(new_green);
	color->blue = ft_rgb_normalize(new_blue);
}

static int	ft_rgb_normalize(int channel)
{
	if (channel < COLOR_MAX)
		return (channel);
	else
		return (COLOR_MAX);
}
