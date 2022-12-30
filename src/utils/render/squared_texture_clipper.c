/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squared_texture_clipper.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:18:07 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 14:39:18 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_render.h"

static int	textures_pt_clipper(t_clip_opcode opcode, size_t size);
//*		end of static declarations

size_t	textures_pt_clip(int coordinate)
{
	const size_t	max_size = textures_pt_clipper(e_TEXTURE_CLIPPER_GET, -1);

	if (coordinate < 0)
		return (0);
	else if (coordinate > (int)max_size - 1)
		return (max_size - 1);
	else
		return (coordinate);
}

size_t	get_textures_size()
{
	return (textures_pt_clipper(e_TEXTURE_CLIPPER_GET, -1));
}

void	textures_clipper_init(const size_t textures_size)
{
	textures_pt_clipper(e_TEXTURE_CLIPPER_INITIALIZE, textures_size);
}

static int	textures_pt_clipper(t_clip_opcode opcode, size_t size)
{
	static size_t	texture_size = 0;

	if (e_TEXTURE_CLIPPER_INITIALIZE == opcode)
	{
		texture_size = size;
	}
	else if (e_TEXTURE_CLIPPER_GET == opcode)
	{
		return (texture_size);
	}
	return (texture_size);
}
