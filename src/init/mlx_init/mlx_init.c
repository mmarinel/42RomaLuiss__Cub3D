/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:38:37 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 13:38:56 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_init.h"

void	game_set_mlx( t_game *game_ref, size_t width, size_t height )
{
	game_ref->screen_handle.mlx = mlx_init();
	game_ref->screen_handle.window
		= mlx_new_window(
			game_ref->screen_handle.mlx,
			width, height, "CyberCube-Escape"
		);
	game_ref->screen_handle.frame_data.img
		= mlx_new_image(
			game_ref->screen_handle.mlx,
			width, height
		);

	game_ref->screen_handle.frame_data.addr = mlx_get_data_addr(
		game_ref->screen_handle.frame_data.img,
		&game_ref->screen_handle.frame_data.bits_per_pixel,
		&game_ref->screen_handle.frame_data.line_length,
		&game_ref->screen_handle.frame_data.endian
	);
	game_ref->screen_handle.width = width;
	game_ref->screen_handle.height = height;
	game_ref->screen_handle.frame_data.width = width;
	game_ref->screen_handle.frame_data.height = height;
	mlx_holder_set(&game_ref->screen_handle);
}
