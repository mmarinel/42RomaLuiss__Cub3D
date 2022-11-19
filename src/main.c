/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:42:01 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/19 18:42:52 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "colors.h"
# include "types.h"
# include "utils/utils_module.h"
# include "map_validation/map_validation_module.h"
# include "raycast/raycast_module.h"
# include "render/line_drawing/line_drawing_module.h"

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;

	t_game			game;

	ft_game_init(&game);
	if (is_valid_map(argv[1], &game.map_handle))
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
	void	*mlx;
	void	*window;
	t_data	img;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 1920, 1080, "Grezzo 2-Parte 2");
	img.img = mlx_new_image(mlx, 1920, 1080);

	t_2d_point	vFirst = (t_2d_point){0, 0};
	t_2d_point	vLast = (t_2d_point){1019, 0};

	t_px_row	row;

	row.img_offset = 0;
	row.texture = (char *) malloc(sizeof(char) * 3);
	((char *)row.texture)[0] = (char) 255;
	((char *)row.texture)[1] = (char) 255;
	((char *)row.texture)[2] = (char) 255;
	row.len = 3;

	bresenham_algo(vFirst, vLast, &img, row);
	free(row.texture);
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