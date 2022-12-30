/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:10:38 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/30 14:31:36 by earendil         ###   ########.fr       */
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
