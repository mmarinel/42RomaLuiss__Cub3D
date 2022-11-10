/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_imgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:36:58 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/10 12:01:08 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ft_put_px_to_image(t_data *img_data, size_t px_offset, t_color color)
{
	char	*byte_ptr;

	byte_ptr = img_data->addr + px_offset;
	*(unsigned int *)byte_ptr = ft_get_mlx_color(color);
}

size_t	ft_get_pixel_offset(const t_data img_data, t_2d_point pt)
{
	return (
		pt.y.val * img_data.line_length + pt.x.val * (img_data.bits_per_pixel / 8)
	);
}
