/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:42:01 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/04 19:24:34 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define SCREEN_WIDTH 1240
# define SCREEN_HEIGHT 760

# include "colors.h"
# include "types.h"
# include "utils/utils_module.h"
# include "init/game_init_module.h"
# include "map_validation/map_validation_module.h"
# include "raycast/raycast_module.h"
# include "render/render_module.h"

// # include <Xplugin.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>

t_bool	is_floor(t_game *g, t_2d_point pt)
{
	t_int_2d_point	normalized;

	normalized.x = floor(pt.x);
	normalized.y = floor(pt.y);
	return (e_FLOOR == g->map_handle.map[normalized.y][normalized.x]
			|| e_PLAYER_N == g->map_handle.map[normalized.y][normalized.x]
			|| e_PLAYER_S == g->map_handle.map[normalized.y][normalized.x]
			|| e_PLAYER_W == g->map_handle.map[normalized.y][normalized.x]
			|| e_PLAYER_E == g->map_handle.map[normalized.y][normalized.x]
		);
}

int	key_hook(int key_code, t_game *game)
{
	printf(YELLOW"key pressed: %d\n"RESET, key_code);

	if (e_UP_KEY == key_code)
	{
		t_2d_point	new_pos;

		new_pos = ft_vec_sum(game->player_pos,
		ft_vec_prod(game->player_dir, 1));
		if (is_floor(game, new_pos))
		{
			// printf(YELLOW "moving upwards...\n" RESET);
			game->player_pos = new_pos;
			render_next_frame(game);
		}
	}
	if (e_DOWN_KEY == key_code)
	{
		t_2d_point	new_pos;
		
		new_pos = ft_vec_sum(game->player_pos,
			ft_vec_prod(ft_vec_opposite(game->player_dir), 1));
		if (is_floor(game, new_pos))
		{
			// printf(YELLOW "moving downwards...\n" RESET);
			game->player_pos = new_pos;
			render_next_frame(game);
		}
	}
	if (e_RIGHT_KEY == key_code)
	{
		game->player_dir =  ft_rotate(game->player_dir, M_PI / 10.0f);
		game->camera_plane = ft_rotate(game->camera_plane, M_PI / 10.0f);
		render_next_frame(game);
	}
	if (e_LEFT_KEY == key_code)
	{
		game->player_dir =  ft_rotate(game->player_dir, (-1) * M_PI / 10.0f);
		game->camera_plane = ft_rotate(game->camera_plane, (-1) * M_PI / 10.0f);
		render_next_frame(game);
	}
	return (0);
}

int main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;

	t_game	game;

	srand(time(NULL));
	if (ft_game_init(argv[1], &game, SCREEN_WIDTH, SCREEN_HEIGHT))
	{
		printf( GREEN "map is ok\n" RESET );
		printf(
			"\n\
			no_texture: %s\n\
			so_texture: %s\n\
			we_texture: %s\n\
			ea_texture: %s\n\
			f_color.red: %d, f_color.green: %d, f_color.blue: %d f_color.alpha: %lf\n\
			c_color.red: %d, c_color.green: %d, c_color.blue: %d f_color.alpha: %lf\n\n\
			",
			game.map_handle.no_texture, game.map_handle.so_texture, game.map_handle.we_texture, game.map_handle.ea_texture,
			game.map_handle.f_color.red, game.map_handle.f_color.green, game.map_handle.f_color.blue, game.map_handle.f_color.alpha,
			game.map_handle.c_color.red, game.map_handle.c_color.green, game.map_handle.c_color.blue, game.map_handle.c_color.alpha
		);
		ft_tile_map_print(game.map_handle.map, game.map_handle.rows, game.map_handle.columns);
	}
	else
		printf( RED "map not ok\n" RESET );
	
	// game.player_pos = ft_get_new_2dpt(4.12, 2.41);
	// printf(CYAN"player? %c\n"RESET, game.map_handle.map[2][4]);
	// // exit(0);
	// game.player_dir = ft_get_new_2dpt(0, 1);
	// game.camera_plane = ft_get_new_2dpt(1, 0);
	// // ft_print_ray_result(raycast(&game, 0.78539816339));
	// ft_print_raycast_result(raycast(&game, (M_PI / 2) + M_PI / 4));//*	π/2 + γ where γ = angolo che formiamo rispetto al versore della direzione del player
	




	


	
	//*********************************		BRESENHAM TESTING		**************************************************
	// t_int_2d_point	vFirst = (t_int_2d_point){1919, 0};
	// t_int_2d_point	vLast = (t_int_2d_point){0, 1079};

	// t_px_row	row;

	// int	*bytes;
	// bytes = (int *) malloc(sizeof(int) * 3);
	// bytes[0] = (int) 255;
	// bytes[1] = (int) 255;
	// bytes[2] = (int) 255;

	// row.img_offset = 0;
	// row.texture = bytes;
	// // printf("%d %d %d\n",
	// // 	((unsigned char *)row.texture)[0],
	// // 	((unsigned char *)row.texture)[1],
	// // 	((unsigned char *)row.texture)[2]
	// // );
	// // exit(0);
	// row.len = 3;

	// bresenham_plot(vFirst, vLast, &game.screen_handle.frame_data, row);
	// mlx_put_image_to_window(
	// 	game.screen_handle.mlx,
	// 	game.screen_handle.window,
	// 	game.screen_handle.frame_data.img,
	// 	0, 0
	// );
	// free(row.texture);
	// mlx_loop(game.screen_handle.mlx);
//**************************************************************************************************************************************

	//*						game.player_pos = ft_get_new_2dpt(4.12, 2.41);
	//*						printf(CYAN"player? %c\n"RESET, game.map_handle.map[2][4]);
	// exit(0);
	//*						game.player_dir = ft_get_new_2dpt(0, 1);
	//*						game.camera_plane = ft_get_new_2dpt(1, 0);
	// ft_print_ray_result(raycast(&game, 0.78539816339));
	// ft_print_raycast_result(raycast(&game, (M_PI / 2) + M_PI / 4));
	render_next_frame(&game);
	//*********************************		BICUBIC TESTING		**************************************************
	(void)key_hook;

	// int		texture_width;
	// int		texture_height;

	// game.wall_texture.south;
	// game.wall_texture.west;
	// game.wall_texture.east;
	game.wall_texture.north.img = mlx_xpm_file_to_image(game.screen_handle.mlx, "img/200bosprite.xpm", &game.wall_texture.north.width, &game.wall_texture.north.height);
	game.wall_texture.north.img = mlx_get_data_addr(game.wall_texture.north.img, &game.wall_texture.north.bits_per_pixel, &game.wall_texture.north.line_length, &game.wall_texture.north.endian);


	// // printf(BOLDGREEN "texture width: %d, texture height: %d\n" RESET, texture_width, texture_height);
	// // exit(0);
	// t_2d_point	mapped;
	// const float	scaling_factor = (float)texture_width / SCREEN_WIDTH;
	// for (int i = 0; i < SCREEN_HEIGHT; i++)
	// for (int j = 0; j < SCREEN_WIDTH; j++)
	// {
	// 	mapped.x = (float)j * scaling_factor;
	// 	mapped.y = (float)i * scaling_factor;
	// 	// printf(YELLOW "putting image at pos x: %lf, y: %lf\n" BOLDGREEN "texture_size is: %d, scaling factor is: %lf\n" RESET, mapped.x, mapped.y, texture_width, scaling_factor);
	// 	ft_put_mlxpx_to_image(
	// 		&game.screen_handle.frame_data,
	// 		ft_get_pixel_offset(game.screen_handle.frame_data, (t_int_2d_point){j, i}),
	// 		bicubic_interpolation(&texture_data, texture_width, mapped)
	// 	);
	// }
	mlx_put_image_to_window(
		game.screen_handle.mlx, game.screen_handle.window,
		game.screen_handle.frame_data.img,
		0, 0);
	// mlx_key_hook(game.screen_handle.window, key_hook, &game);
	// mlx_do_key_autorepeaton(&game.screen_handle.mlx);
	mlx_hook(game.screen_handle.window, 2, 1L<<0, key_hook, &game);
	mlx_loop(game.screen_handle.mlx);
//**************************************************************************************************************************************
















	ft_free_map(&game.map_handle.map, game.map_handle.rows);
	free(game.map_handle.no_texture);
	free(game.map_handle.so_texture);
	free(game.map_handle.we_texture);
	free(game.map_handle.ea_texture);

	// void	*mlx;
	// void	*window;
	// t_data	img;

	// mlx = mlx_init();
	// window = mlx_new_window(mlx, 1920, 1080, "Grezzo 2-Parte 2");
	// img.img = mlx_new_image(mlx, 1920, 1080);

	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	// printf("\n\nline_length: %d; bits_per_pixel: %d\n", img.line_length, img.bits_per_pixel);
	// t_color	line_color;
	// t_color	cur_px_color;
	// ft_fill_color(40, 11, 3, &line_color);
	// // ft_fill_color(151, 50, 168, &line_color);
	// for (int i = 0; i < 1920; i++) {
	// 	cur_px_color = ft_get_shade(line_color, (double) i / 1920);
	// 	ft_put_px_to_image(&img, ft_get_pixel_offset(img, ft_get_new_2dpt(i, 1080 / 2)), cur_px_color);
	// }
	// mlx_put_image_to_window(mlx, window, img.img, 0, 0);
	// mlx_loop(mlx);
	printf(YELLOW "\n\n.......leaks program output......\n\n" RESET);
	return 0;
}
//		*test	leaks --atExit -- ./cub3D "Ciao vincenzo, come stai?"