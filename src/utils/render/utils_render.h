/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_render.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:16:20 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 14:38:15 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_RENDER_H
# define UTILS_RENDER_H

# include "../../types.h"
# include "../../game_types.h"

# include "utils_render_types.h"

size_t	texture_px_max_offset(const t_data *texture_data);
size_t	ft_get_mlx_color(t_color color);
t_bool	is_mlx_px(int px);
t_bool	is_mlx_color(t_color color);

#endif