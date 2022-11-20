/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_holder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:06:08 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/20 17:05:07 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static size_t	mlx_window_holder(t_mlx_win_holder opcode, const t_screen_holder *screen_holder)
{
	static size_t	win_width = 0;
	static size_t	win_height = 0;
	static size_t	win_max_offset = 0;

	if (e_MLX_HOLDER_SET == opcode && screen_holder)
	{
		win_width = screen_holder->width;
		win_height = screen_holder->height;
		win_max_offset
			= screen_holder->height * screen_holder->frame_data.line_length;
	}
	if (e_MLX_HOLDER_GET_MAX_OFFSET == opcode)
	{
		return (win_max_offset);
	}
	//* if (...other opcodes)
	//* ..default
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
