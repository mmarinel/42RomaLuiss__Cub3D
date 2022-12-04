// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   bcb_clip.c                                         :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/11/27 12:02:32 by mmarinel          #+#    #+#             */
// /*   Updated: 2022/11/27 13:23:47 by mmarinel         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "textures.h"

// int	bcb_clipper(t_clip_opcode opcode, size_t size)
// {
// 	static size_t	texture_size = 0;

// 	if (e_BCB_CLIPPER_INITIALIZE == opcode)
// 	{
// 		texture_size = size;
// 		// printf(BOLDGREEN "texture_size: %zu\n" RESET, texture_size);
// 	}
// 	else if (e_BCB_CLIPPER_GET == opcode)
// 	{
// 		return (texture_size);
// 	}
// 	return (texture_size);
// }

// size_t	bcb_clip(int coordinate)
// {
// 	const size_t	max_size = bcb_clipper(e_BCB_CLIPPER_GET, -1);

// 	if (coordinate < 0)
// 		return (0);
// 	else if (coordinate > (int)max_size - 1)
// 		return (max_size - 1);
// 	else
// 		return (coordinate);
// }
