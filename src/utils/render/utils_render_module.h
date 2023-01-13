/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render_module.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:15:06 by earendil          #+#    #+#             */
/*   Updated: 2023/01/13 15:17:01 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_RENDER_MODULE_H
# define UTILS_RENDER_MODULE_H

# include "../../includes/basic_types.h"
# include "../../includes/game_types.h"

//*		mlx memory
int	ft_mlx_destroy_image(void *mlx_ptr, t_data *img_data);

//*		textures clipper
size_t	textures_pt_clip(int coordinate);
void	textures_clipper_init(const size_t textures_size);
size_t	get_textures_size(void);

//*		rgb
t_bool	is_mlx_color(t_color color);
t_bool	ft_iscolor( long long red, long long green, long long blue );
size_t	ft_get_mlx_color(t_color color);
t_bool	is_mlx_px(int px);

//*		imgs
void	ft_put_px_to_image(t_data *img_data, size_t px_offset, t_color color);
void	ft_put_mlxpx_to_image(t_data *img_data, size_t px_offset, int color);
size_t	ft_get_pixel_offset(const t_data *img_data, t_int_2d_point pt);
int		get_texture_px(t_int_2d_point coordinate, const t_data *texture_data);
size_t	texture_px_max_offset(const t_data *texture_data);

#endif