/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uti_render_module.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:12:20 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/12 16:05:34 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTI_RENDER_MODULE_H
# define UTI_RENDER_MODULE_H

# include "../render_types.h"

//*		render_clipping
t_int_2d_point	endpoint_clip(t_int_2d_point endpoint);

//*		render conditions
t_bool			ft_iscolor( long long red, long long green, long long blue );

//*		minimap
t_int_2d_point	mmp_px_clip(
					const t_int_2d_point *bottom_left,
					const t_int_2d_point *mmp_px
					);
t_int_2d_point	mmp_get_map_pos(
					const t_int_2d_point *mmp_px,
					const t_int_2d_point *player_mmp_px,
					t_game *g
					);

#endif