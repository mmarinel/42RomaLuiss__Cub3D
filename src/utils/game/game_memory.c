/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:15:44 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/20 18:05:36 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

static void	game_set_map( t_game *game_ref );
static void	game_set_mlx( t_game *game_ref, size_t width, size_t height );
//*		end of static declarations


void	ft_game_init( t_game *game_ref, size_t width, size_t height )
{
	if (NULL == game_ref)
		return ;
	game_set_map(game_ref);
	game_set_mlx(game_ref, width, height);
}

static void	game_set_map( t_game *game_ref )
{
	game_ref->map_handle.map = NULL;
	game_ref->map_handle.rows = 0;
	game_ref->map_handle.columns = 0;
	game_ref->map_handle.no_texture = NULL;
	game_ref->map_handle.so_texture = NULL;
	game_ref->map_handle.we_texture = NULL;
	game_ref->map_handle.ea_texture = NULL;
	game_ref->map_handle.f_color.alpha = -1;
	game_ref->map_handle.f_color.red = 0;
	game_ref->map_handle.f_color.green = 0;
	game_ref->map_handle.f_color.blue = 0;
	game_ref->map_handle.c_color.alpha = -1;
	game_ref->map_handle.c_color.red = 0;
	game_ref->map_handle.c_color.green = 0;
	game_ref->map_handle.c_color.blue = 0;
}

static void	game_set_mlx( t_game *game_ref, size_t width, size_t height )
{
	game_ref->screen_handle.mlx = mlx_init();
	game_ref->screen_handle.window
		= mlx_new_window(
			game_ref->screen_handle.mlx,
			width, height, "Grezzo 2-Parte 2"
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
	mlx_holder_set(&game_ref->screen_handle);
}
