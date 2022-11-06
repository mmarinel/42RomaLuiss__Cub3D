/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_module.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:12:20 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/05 18:51:10 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_MODULE_H
# define RENDER_MODULE_H

# include "render_types.h"

//*		mlx_utils
void	ft_put_px_to_image(t_data *img_data, size_t px_offset, t_color color);
size_t	ft_get_pixel_offset(const t_data img_data, t_2d_point pt);

//*		color
size_t	ft_get_mlx_color(t_color color);
t_bool	ft_fill_color(int red, int green, int blue, t_color *color);

//*		brightness
t_color	ft_get_shade(const t_color color, double percentage);
void	ft_adjust_brightness(t_color *color, double percentage);
t_color	ft_color_gradient_get_shade(
			t_color brightiest_shade,
			t_color darkest_shade,
			double percentage
		);

//*		conditions
t_bool	ft_iscolor(long long red, long long green, long long blue);

#endif