/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:12:49 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/05 12:19:12 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../libft/libft_module.h"
# include "render_types.h"

# include <math.h>

//*		mlx_utils
size_t	ft_get_pixel_offset(const t_data img_data, t_2Dpoint pt);

//*		color
t_bool	ft_iscolor(long long red, long long green, long long blue);
void	ft_put_px_to_image(t_data *img_data, size_t px_offset, t_color color);
size_t	ft_get_mlx_color(t_color color);
t_bool	ft_fill_color(int red, int green, int blue, t_color *color);
void	ft_apply_brightness(t_color *color, int factor);

#endif