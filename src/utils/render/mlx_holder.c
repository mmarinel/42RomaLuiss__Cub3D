/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_holder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:06:08 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/13 10:52:48 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_render.h"

static size_t	mlx_window_holder(
	t_mlx_win_holder opcode,
	const t_screen_holder *screen_holder
	)
{
	static size_t	win_max_offset = 0;

	if (e_MLX_HOLDER_SET == opcode && screen_holder)
	{
		win_max_offset
			= screen_holder->height * screen_holder->frame_data.line_length;
	}
	if (e_MLX_HOLDER_GET_MAX_OFFSET == opcode)
	{
		return (win_max_offset);
	}
	return (win_max_offset);
}

void	mlx_holder_set(const t_screen_holder *screen_holder)
{
	mlx_window_holder(e_MLX_HOLDER_SET, screen_holder);
}

size_t	mlx_holder_max_offset( void )
{
	return (mlx_window_holder(e_MLX_HOLDER_GET_MAX_OFFSET, NULL));
}
