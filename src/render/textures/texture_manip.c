// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   texture_manip.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/11/27 12:05:06 by mmarinel          #+#    #+#             */
// /*   Updated: 2022/11/27 16:12:28 by mmarinel         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "textures.h"

// t_px	get_texture_px(t_int_2d_point coordinate, const t_data *texture_data)
// {
// 	const size_t	offset = ft_get_pixel_offset(*texture_data, coordinate);
// 	const char		*byte_ptr = texture_data->addr + offset;
// 	t_px	px;

// 	// if (offset >= (size_t) 64 * texture_data->line_length || offset < 0)
// 	// {
// 	// 	px.rgb = 255 + (255 << 8) + (255 << 16);
// 	// 	printf(RED "out\n" RESET);
// 	// }
// 	// else
// 	// {
// 	// 	printf("\n");
// 		px.rgb = *(unsigned int *)byte_ptr;
// 	// }
// 	return (px);
// }
