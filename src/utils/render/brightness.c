/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brightness.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 18:38:49 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/05 18:55:31 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static double	ft_get_max_brightness_factor(const t_color color);
//*		end of static declarations

/**
 * @brief This function returns a new shade of the given color.
 * 
 * @param color 
 * @param percentage a floating point in interval [0, 1].
 * 1 for the brightest shade and 0 for the darkest one.
 * @return t_color 
 */
t_color	ft_get_shade(const t_color color, double percentage)
{
	t_color	shade;

	shade = color;
	ft_adjust_brightness(&shade, percentage);
	return (shade);
}

/**
 * @brief this function adjust the brightness of a given color.
 * 
 * @param color 
 * @param percentage a floating point in interval [0, 1].
 * 1 for the brightest shade and 0 for the darkest one.
 */
void	ft_adjust_brightness(t_color *color, double percentage)
{
	t_color			darkest_shade;
	t_color			brightest_shade;
	const t_color	normalized = ft_get_normalized_color(*color);
	const double	max_factor = ft_get_max_brightness_factor(normalized);

	darkest_shade = normalized;
	brightest_shade = normalized;
	ft_apply_brightness(&brightest_shade, max_factor);
	ft_apply_brightness(&darkest_shade, (double) 1 / max_factor);
	*color = ft_color_gradient_get_shade(
			brightest_shade,
			darkest_shade,
			percentage
			);
}

/**
 * @brief This function returns a new color along
 * the gradient formed by the two input colors.
 * 
 * @param brightiest_shade 
 * @param darkest_shade 
 * @param percentage a floating point in interval [0, 1].
 * 1 and 0 for the respective extremants.
 * @return t_color 
 */
t_color	ft_color_gradient_get_shade(
			t_color brightiest_shade,
			t_color darkest_shade,
			double percentage
		)
{
	t_color	shade;

	shade.red = darkest_shade.red
		+ percentage * (brightiest_shade.red - darkest_shade.red);
	shade.green = darkest_shade.green
		+ percentage * (brightiest_shade.green - darkest_shade.green);
	shade.blue = darkest_shade.blue
		+ percentage * (brightiest_shade.blue - darkest_shade.blue);
	return (shade);
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

/**
 * @brief This function returns the maximum brightness factor 
 * for the given color.
 * A brightness factor is a number X with X > 1 such that it makes
 * the color brighter when multiplied on each of its rgb components.
 * A brightest factor is said to be maximum when there is no greater one
 * (with respect to the step size) such that each component
 * remains under CHAR_MAX when multiplied by it.
 * @param color 
 * @return double 
 */
static double	ft_get_max_brightness_factor(const t_color color)
{
	double			max_factor;
	const double	step = 0.01;

	max_factor = 1 + step;
	while (e_true)
	{
		if (
			color.red * max_factor > (double) COLOR_MAX
			|| color.green * max_factor > (double) COLOR_MAX
			|| color.blue * max_factor > (double) COLOR_MAX
		)
			break ;
		max_factor += step;
	}
	return (max_factor);
}
