/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:10:38 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/05 12:23:16 by mmarinel         ###   ########.fr       */
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

/**
 * @brief this function applies brightness to the given color.
 * 
 * @param color 
 * @param factor X with X > 1 if you want to make it brighter,
 * or 1/X if you want to make it darker.
 * @return t_bool 
 */
void	ft_apply_brightness(t_color *color, int factor)
{
	const short	new_red = color->red * factor;
	const short	new_green = color->green * factor;
	const short	new_blue = color->blue * factor;

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
