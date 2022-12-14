/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_imgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:36:58 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/14 19:58:47 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_put_px_to_image(t_data *img_data, size_t px_offset, t_color color)//!		cambiare color in PX !!!!!!!!!!!
{
	char	*byte_ptr;

	if (px_offset < mlx_holder_max_offset())
	{
		byte_ptr = img_data->addr + px_offset;
		*(unsigned int *)byte_ptr = ft_get_mlx_color(color);
	}
}

void	ft_put_mlxpx_to_image(t_data *img_data, size_t px_offset, int color)
{
	char	*byte_ptr;

	if (px_offset < mlx_holder_max_offset() && color > 0)
	{
		byte_ptr = img_data->addr + px_offset;
		*(unsigned int *)byte_ptr = color;
	}
}

size_t	ft_get_pixel_offset(const t_data *img_data, t_int_2d_point pt)
{
	return (
		pt.y * img_data->line_length + pt.x * (img_data->bits_per_pixel / 8)
	);
}
