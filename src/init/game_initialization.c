/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:28:32 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/30 12:58:39 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_init.h"

static void	game_set_map( t_game *game_ref );
static void	game_set_mlx( t_game *game_ref, size_t width, size_t height );
static void	game_set_vectors( t_game *game_ref );
static void	initial_dir_vectors(
				t_tile inital_dir,
				t_2d_point *player_dir, t_2d_point *camera_plane
			);
//*		end of static declarations

static t_2d_point	get_initial_dir(t_tile dir)
{
	t_2d_point	pt;

	if (e_PLAYER_N == dir)
	{
		pt.x = 0;
		pt.y = 1;
	}
	if (e_PLAYER_S == dir)
	{
		pt.x = 0;
		pt.y = -1;
	}
	if (e_PLAYER_W == dir)
	{
		pt.x = 1;
		pt.y = 0;
	}
	if (e_PLAYER_E == dir)
	{
		pt.x = -1;
		pt.y = 0;
	}
	return (pt);
}

t_bool	ft_game_init(
			const char *path,
			t_game *game_ref,
			size_t width, size_t height
		)
{
	t_bool	ok;

	if (game_ref)
	{
		ok = e_true;
		game_set_map(game_ref);
		if (e_false == is_valid_map(path, &game_ref->map_handle))
			ok = e_false;
		else
		{
			game_ref->player_dir = get_initial_dir(game_ref->map_handle.player_initial_dir);
			game_ref->player_pos = game_ref->map_handle.player_initial_pos;
			game_ref->screen_handle.textures_size = TEXTURES_SIZE;// load_textures();
			game_set_vectors(game_ref);
		}
	}
	else
		ok = e_false;
	game_set_mlx(game_ref, width, height);
	return (ok);
}

static void	game_set_map( t_game *game_ref )
{
	game_ref->map_handle.player_initial_pos
		= ft_get_new_2dpt(-1, -1);
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

static void	game_set_vectors( t_game *game_ref )
{
	if (game_ref->map_handle.player_initial_pos.x >= 0
		&& game_ref->map_handle.player_initial_pos.y >= 0)
	{
		game_ref->player_pos = game_ref->map_handle.player_initial_pos;
		initial_dir_vectors(
			game_ref->map_handle.player_initial_dir,
			&game_ref->player_dir, &game_ref->camera_plane
		);
	}
}

static void	initial_dir_vectors(
				t_tile inital_dir,
				t_2d_point *player_dir, t_2d_point *camera_plane
			)
{
	const float	scale_factor = tan(FOV / 2);

	if (e_PLAYER_N == inital_dir)
	{
		*player_dir = ft_get_new_2dpt(0, -1);
		*camera_plane = ft_get_new_2dpt(-1 * scale_factor, 0 * scale_factor);
	}
	else if (e_PLAYER_S == inital_dir)
	{
		*player_dir = ft_get_new_2dpt(0, 1);
		*camera_plane = ft_get_new_2dpt(1 * scale_factor, 0 * scale_factor);
	}
	else if (e_PLAYER_E == inital_dir)
	{
		*player_dir = ft_get_new_2dpt(1, 0);
		*camera_plane = ft_get_new_2dpt(0 * scale_factor, -1 * scale_factor);
	}
	else if (e_PLAYER_W == inital_dir)
	{
		*player_dir = ft_get_new_2dpt(-1, 0);
		*camera_plane = ft_get_new_2dpt(0 * scale_factor, 1 * scale_factor);
	}
	else
		return;
}
