/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_module.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:12:20 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/10 19:52:02 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_RENDER_MODULE_H
# define UTILS_RENDER_MODULE_H

# include "render_types.h"

//*		mlx_utils
void	ft_put_px_to_image(t_data *img_data, size_t px_offset, t_color color);
void	ft_put_mlxpx_to_image(t_data *img_data, size_t px_offset, int color);
size_t	ft_get_pixel_offset(const t_data *img_data, t_int_2d_point pt);

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

//*		mlx holder
void	mlx_holder_set(const t_screen_holder *screen_holder);
size_t	mlx_holder_max_offset( void );

//*		textures
size_t	texture_pt_clip(size_t coordinate);
int		texture_pt_clipper(t_clip_opcode opcode, size_t size);
size_t	get_textures_size();

#endif