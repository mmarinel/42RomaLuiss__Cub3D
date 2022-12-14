/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:12:49 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/14 22:10:48 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../libft/libft_module.h"
# include "render_types.h"
# include "../../colors.h"

# include <math.h>

//*		mlx_utils
void	ft_put_px_to_image(t_data *img_data, size_t px_offset, t_color color);
size_t	ft_get_pixel_offset(const t_data *img_data, t_int_2d_point pt);

//*		color
t_bool	is_mlx_px(int px);
t_bool	is_mlx_color(t_color color);
size_t	ft_get_mlx_color(t_color color);
t_bool	ft_fill_color(int red, int green, int blue, t_color *color);
t_color	ft_get_normalized_color(const t_color color);
int		ft_rgb_normalize(int channel);

//*		brightness
t_color	ft_get_shade(const t_color color, double percentage);
void	ft_adjust_brightness(t_color *color, double percentage);
t_color	ft_color_gradient_get_shade(
			t_color brightiest_shade,
			t_color darkest_shade,
			double percentage
		);
void	ft_apply_brightness(t_color *color, double factor);

//*		conditions
t_bool	ft_iscolor(long long red, long long green, long long blue);

//*		mlx_holder
void	mlx_holder_set(const t_screen_holder *screen_holder);
size_t	mlx_holder_max_offset( void );

#endif