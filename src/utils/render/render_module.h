/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_module.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:12:20 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/05 12:34:01 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_MODULE_H
# define RENDER_MODULE_H

# include "render_types.h"

//*		mlx_utils
size_t	ft_get_pixel_offset(const t_data img_data, t_2Dpoint pt);

//*		color
t_bool	ft_iscolor(long long red, long long green, long long blue);
void	ft_put_px_to_image(t_data *img_data, size_t px_offset, t_color color);
size_t	ft_get_mlx_color(t_color color);
t_bool	ft_fill_color(int red, int green, int blue, t_color *color);
void	ft_apply_brightness(t_color *color, int factor);

#endif