/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render_module.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:15:06 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 14:33:05 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_RENDER_MODULE_H
# define UTILS_RENDER_MODULE_H

# include "../../types.h"
# include "../../game_types.h"

//*		mlx holder
void	mlx_holder_set(const t_screen_holder *screen_holder);
size_t	mlx_holder_max_offset( void );

//*		textures clipper
size_t	textures_pt_clip(int coordinate);
void	textures_clipper_init(const size_t textures_size);
size_t	get_textures_size(void);

//*		rgb
t_bool	is_mlx_color(t_color color);
size_t	ft_get_mlx_color(t_color color);
t_bool	is_mlx_px(int px);

//*		imgs
void	ft_put_px_to_image(t_data *img_data, size_t px_offset, t_color color);
void	ft_put_mlxpx_to_image(t_data *img_data, size_t px_offset, int color);
size_t	ft_get_pixel_offset(const t_data *img_data, t_int_2d_point pt);
int		get_texture_px(t_int_2d_point coordinate, const t_data *texture_data);
size_t	texture_px_max_offset(const t_data *texture_data);

#endif