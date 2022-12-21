/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_imgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:36:58 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/21 23:23:58 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uti_render.h"

void	ft_put_px_to_image(t_data *img_data, size_t px_offset, t_color color)//!		cambiare color in PX !!!!!!!!!!!
{
	char	*byte_ptr;

	if (px_offset < texture_px_max_offset(img_data) && is_mlx_color(color))
	{
		byte_ptr = img_data->addr + px_offset;
		*(unsigned int *)byte_ptr = ft_get_mlx_color(color);
	}
}

void	ft_put_mlxpx_to_image(t_data *img_data, size_t px_offset, int color)
{
	char	*byte_ptr;

	if (px_offset < texture_px_max_offset(img_data) && is_mlx_px(color))
	{
		byte_ptr = img_data->addr + px_offset;
		*(unsigned int *)byte_ptr = color;
	}
}

size_t	ft_get_pixel_offset(const t_data *img_data, t_int_2d_point pt)
{
	if ((pt.x < 0 || pt.x >= img_data->width)
		|| (pt.y < 0 || pt.y >= img_data->height)
	)
		return ((size_t)(-1));
	else
		return (
			pt.y * img_data->line_length + pt.x * (img_data->bits_per_pixel / 8)
		);
}

int	get_texture_px(t_int_2d_point coordinate, const t_data *texture_data)
{
	const size_t	offset = ft_get_pixel_offset(texture_data, coordinate);
	const char		*byte_ptr = texture_data->addr + offset;

	if (offset != (size_t)(-1)
		&& offset < (size_t)texture_data->height * texture_data->line_length
		)
		return (*(unsigned int *)byte_ptr);
	else
		return (-1);
}

size_t	texture_px_max_offset(const t_data *texture_data)
{
	return (
		texture_data->height * texture_data->line_length
	);
}
