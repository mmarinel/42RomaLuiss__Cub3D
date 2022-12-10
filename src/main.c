/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:42:01 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/10 12:45:21 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 760

# include "colors.h"
# include "types.h"
# include "utils/utils_module.h"
# include "init/game_init_module.h"
# include "map_validation/map_validation_module.h"
# include "raycast/raycast_module.h"
# include "render/render_module.h"

// # include <Xplugin.h>
# include <sys/time.h>
# include <time.h>
# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>

int	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000
			+ (u_int64_t)time.tv_usec / 1000));
}

int	get_ms_from_timestamp(const struct timeval *timestamp)
{
	return ((timestamp->tv_sec * 1000
			+ (u_int64_t)timestamp->tv_usec / 1000));
}

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


t_2d_point	map_pos_clip(t_2d_point pt, t_game *game)
{
	if (pt.x >= game->map_handle.columns)
		pt.x = game->map_handle.columns - 1;
	if (pt.y >= game->map_handle.rows)
		pt.y = game->map_handle.rows - 1;
	return (pt);
}

t_2d_point	new_player_pos(t_2d_point current,
				int key_pressed, float step_size, t_game *game)
{
	t_2d_point	pos;

	pos = current;
	if (e_UP_KEY == key_pressed)
	{
		pos = map_pos_clip(
			ft_vec_sum(
				game->player_pos,
				ft_vec_prod(game->player_dir, step_size)
			),
			game
		);
	}
	if (e_DOWN_KEY == key_pressed)
	{
		pos = map_pos_clip(
				ft_vec_sum(
					game->player_pos,
					ft_vec_prod(
						ft_vec_opposite(game->player_dir),
						step_size
					)
				),
				game
			);
	}
	return (pos);
}

int	loop_hook(t_game *game)
{
	static struct timeval	*timestamp = NULL;
	struct timeval			current;
	static float			rot_angle = 0.174533f;
	static float			step_size = 0.5f;

	if (NULL == timestamp)
	{
		timestamp = (struct timeval *) malloc(sizeof(struct timeval));
		gettimeofday(timestamp, NULL);
	}
	gettimeofday(&current, NULL);
	if (get_ms_from_timestamp(&current) - get_ms_from_timestamp(timestamp) < 0)
		return (0);
	*timestamp = current;
	if (KeyPress == game->keys[UP_INDEX].state
		|| KeyRelease == game->keys[UP_INDEX].state)
	{
		if (KeyPress == game->keys[UP_INDEX].state
			|| KeyPress == game->keys[W_INDEX].state)
		{
				t_2d_point	new_pos;
	
			while (e_true)
			{
				new_pos = new_player_pos(game->player_pos, e_UP_KEY, step_size, game);
				if (is_floor(game, new_pos))
					break ;
				step_size -= 0.5f;
			}
			// if (is_floor(game, new_pos))
			// {
				// printf(YELLOW "moving upwards...\n" RESET);
				game->player_pos = new_pos;
				render_next_frame(game);
				if (step_size < 3)
					step_size += 0.5f;
			// }
		}
		else if (KeyRelease == game->keys[UP_INDEX].state)
		{
			step_size = 0.5f;
			game->keys[UP_INDEX].state = -1;
		}
	}
	if (KeyPress == game->keys[DOWN_INDEX].state
		|| KeyRelease == game->keys[DOWN_INDEX].state)
	{
		if (KeyPress == game->keys[DOWN_INDEX].state
			|| KeyPress == game->keys[S_INDEX].state)
		{
			t_2d_point	new_pos;
			
			while (e_true)
			{
				new_pos = new_player_pos(game->player_pos, e_DOWN_KEY, step_size, game);
				if (is_floor(game, new_pos))
					break ;
				step_size -= 0.5f;
			}
			// if (is_floor(game, new_pos))
			// {
				// printf(YELLOW "moving downwards...\n" RESET);
				game->player_pos = new_pos;
				render_next_frame(game);
				if (step_size < 3)
					step_size += 0.5f;
			// }
		}
		else if (KeyRelease == game->keys[UP_INDEX].state)
		{
			step_size = 0.5f;
			game->keys[DOWN_INDEX].state = -1;
		}
	}
	if (KeyPress == game->keys[RIGHT_INDEX].state
		|| KeyRelease == game->keys[RIGHT_INDEX].state)
	{
		if (KeyPress == game->keys[RIGHT_INDEX].state)
		{
			game->player_dir = ft_rotate(game->player_dir, rot_angle);//0.174533f);//M_PI / 05.0f);//ft_vec_sum(game->player_dir, ft_vec_prod(game->camera_plane, 0.05));
			game->camera_plane = ft_rotate(game->camera_plane, rot_angle);//0.174533f);// M_PI / 05.0f);
			render_next_frame(game);
			if (rot_angle < 0.314159f)
				rot_angle += 0.05f;
		}
		else if (KeyRelease == game->keys[RIGHT_INDEX].state)
		{
			rot_angle = 0.174533f;
			game->keys[RIGHT_INDEX].state = -1;
		}

	}
	if (KeyPress == game->keys[LEFT_INDEX].state
		|| KeyRelease == game->keys[LEFT_INDEX].state)
	{
		if (KeyPress == game->keys[LEFT_INDEX].state)
		{
			game->player_dir = ft_rotate(game->player_dir, 2 * M_PI - rot_angle);//0.174533f);// M_PI / 05.0f);
			game->camera_plane = ft_rotate(game->camera_plane, 2 * M_PI -  rot_angle);//0.174533f);// M_PI / 05.0f);
			render_next_frame(game);
			if (rot_angle < 0.314159f)
				rot_angle += 0.05f;
		}
		else if (KeyRelease == game->keys[LEFT_INDEX].state)
		{
			rot_angle = 0.174533f;
			game->keys[LEFT_INDEX].state = -1;
		}
	}
	return (0);
}

static int	get_key_index(int key_code)
{
	if (e_UP_KEY == key_code)
		return (UP_INDEX);
	if (e_DOWN_KEY == key_code)
		return (DOWN_INDEX);
	if (e_RIGHT_KEY == key_code)
		return (RIGHT_INDEX);
	if (e_LEFT_KEY == key_code)
		return (LEFT_INDEX);
	// if (e_W_KEY == key_code)
	// 	return (UP_INDEX);
	// if (e_UP_KEY == key_code)
	// 	return (UP_INDEX);
	// if (e_UP_KEY == key_code)
	// 	return (UP_INDEX);
	// if (e_UP_KEY == key_code)
	// 	return (UP_INDEX);
	return (0);
}

int	key_press_hook(int key_code, t_game *game)
{
	const size_t	key_index = get_key_index(key_code);

	game->keys[key_index].state = KeyPress;
	return (0);
}

int	key_release_hook(int key_code, t_game *game)
{
	const size_t	key_index = get_key_index(key_code);

	game->keys[key_index].state = KeyRelease;
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
	//**********
	// game.wall_texture.north.img = mlx_xpm_file_to_image(
	// 	game.screen_handle.mlx,
	// 	"img/200doggo.xpm",
	// 	&game.wall_texture.north.width, &game.wall_texture.north.height
	// );
	// game.wall_texture.north.addr = mlx_get_data_addr(
	// 	game.wall_texture.north.img,
	// 	&game.wall_texture.north.bits_per_pixel,
	// 	&game.wall_texture.north.line_length, &game.wall_texture.north.endian
	// );
	//**********
	// mlx_put_image_to_window(game.screen_handle.mlx, game.screen_handle.window, game.wall_texture.north.img, 0, 0);
	// mlx_loop(game.screen_handle.mlx);
	// printf(YELLOW "texture width: %d; texture height: %d\n" RESET, game.wall_texture.north.width, game.wall_texture.north.height);
	// exit(0);
	//*********************************		BICUBIC TESTING		**************************************************
	//** (void)key_hook;

	// int		texture_width;
	// int		texture_height;

	// game.wall_texture.south;
	// game.wall_texture.west;
	// game.wall_texture.east;

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
	// mlx_put_image_to_window(
	// 	game.screen_handle.mlx, game.screen_handle.window,
	// 	game.screen_handle.frame_data.img,
	// 	0, 0);
	// mlx_key_hook(game.screen_handle.window, key_hook, &game);
	// mlx_do_key_autorepeaton(&game.screen_handle.mlx);
	mlx_hook(game.screen_handle.window, KeyPress, KeyPressMask, key_press_hook, &game);
	mlx_hook(game.screen_handle.window, KeyRelease, KeyReleaseMask, key_release_hook, &game);
	mlx_do_sync(game.screen_handle.mlx);
	render_next_frame(&game);
	mlx_loop_hook(game.screen_handle.mlx, loop_hook, &game);
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