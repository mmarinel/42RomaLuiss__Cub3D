/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:10:38 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/30 14:47:36 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_render.h"

t_bool	is_mlx_color(t_color color)
{
	return (
		color.alpha == 1
		&& color.red <= 255
		&& color.green <= 255
		&& color.blue <= 255
	);
}

t_bool	ft_iscolor( long long red, long long green, long long blue )
{
	return (
		COLOR_MIN <= red && red <= COLOR_MAX
		&& COLOR_MIN <= green && green <= COLOR_MAX
		&& COLOR_MIN <= blue && blue <= COLOR_MAX
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
