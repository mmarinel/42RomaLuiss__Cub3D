/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_initialization.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:28:32 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/20 14:04:06 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_init.h"

static void	game_set_map( t_game *game_ref );
static void	game_set_mlx( t_game *game_ref, size_t width, size_t height );
static void	game_set_inital_vectors( t_game *game_ref );
static void	initial_dir_vectors(
				t_tile inital_dir,
				t_2d_point *player_dir, t_2d_point *camera_plane
			);
void	load_textures(t_game *game_ref, t_bool *err_flag);
void	game_set_key_state(t_game *game_ref);
//*		end of static declarations

// static t_2d_point	get_initial_dir(t_tile dir)
// {
// 	t_2d_point	pt;

// 	if (e_PLAYER_N == dir)
// 	{
// 		pt.x = 0;
// 		pt.y = 1;
// 	}
// 	if (e_PLAYER_S == dir)
// 	{
// 		pt.x = 0;
// 		pt.y = -1;
// 	}
// 	if (e_PLAYER_W == dir)
// 	{
// 		pt.x = 1;
// 		pt.y = 0;
// 	}
// 	if (e_PLAYER_E == dir)
// 	{
// 		pt.x = -1;
// 		pt.y = 0;
// 	}
// 	return (pt);
// }

float	player_west_angle(t_game *game_ref);

t_bool	ft_game_init(
			const char *map_path,
			t_game *game_ref,
			size_t width, size_t height
		)
{
	t_bool	error;

	if (game_ref)
	{
		error = e_false;
		game_set_map(game_ref);
		if (e_false == is_valid_map(map_path, &game_ref->map_handle))
			error = e_true;
		else
		{
			game_set_inital_vectors(game_ref);
			game_ref->enemies = NULL;
			game_ref->doors = NULL;
			if (BONUS)
			{
				scan_enemies(game_ref);
				scan_doors(game_ref);
			}
			map_reset(&game_ref->map_handle);
			//*	TESTING
			ft_lstadd_back(&game_ref->enemies, ft_new_enemy_node(
				(t_2d_point){game_ref->player.pos.x - 1, game_ref->player.pos.y}
			));
			ft_lstadd_back(&game_ref->enemies, ft_new_enemy_node(
				(t_2d_point){21, 16}
			));
			ft_lstadd_back(&game_ref->enemies, ft_new_enemy_node(
				(t_2d_point){53, 15}
			));
			//*
			t_2d_point_print(&game_ref->player.dir, "player_dir");
			t_2d_point_print(&game_ref->player.camera_plane, "cmaera_plane");
			t_2d_point_print(&game_ref->player.pos, "player_pos");
		}
	}
	else
		error = e_true;
	game_set_mlx(game_ref, width, height);
	game_set_key_state(game_ref);
	load_textures(game_ref, &error);
	game_ref->in_game = e_true;
	game_ref->in_menu = e_true;
	game_ref->unit_rot_angle = INITIAL_ROT_ANGLE;
	game_ref->player.alive = e_true;
	game_ref->player.hp = 100;
	game_ref->player.mana = 100;
	game_ref->player.attacking = e_false;
	game_ref->player.colliding = e_false;
	game_ref->player.west_angle = player_west_angle(game_ref);
	return (error == e_false);
}

float	player_west_angle(t_game *game_ref)
{
	if (e_PLAYER_W == game_ref->map_handle.player_initial_dir)
		return (0);
	if (e_PLAYER_N == game_ref->map_handle.player_initial_dir)
		return (M_PI / 2);
	if (e_PLAYER_E == game_ref->map_handle.player_initial_dir)
		return (M_PI);
	if (e_PLAYER_S == game_ref->map_handle.player_initial_dir)
		return (M_PI * 3.0f / 2);
	return (-1);
}

size_t	open_texture(const char *path, t_data *texture_data,
			t_game *game_ref, t_bool *err_flag)
{
	texture_data->img = mlx_xpm_file_to_image(
		game_ref->screen_handle.mlx,
		(char *)path,
		&texture_data->width, &texture_data->height
	);
	if (texture_data->img)
		texture_data->addr = mlx_get_data_addr(
			texture_data->img,
			&texture_data->bits_per_pixel,
			&texture_data->line_length, &texture_data->endian
		);
	if (NULL == texture_data->img
		|| NULL == texture_data->addr
		|| texture_data->width != texture_data->height
	)
		*err_flag = e_true;

	if (!texture_data->img || !texture_data->addr)
		printf(RED "NULL\n" RESET);
	else
		printf(GREEN "OK\n" RESET);
	printf(YELLOW "texture path:%sT\n" RESET, path);
	return (texture_data->width);
}

size_t	open_bg_texture(const char *path, t_data *texture_data,
			t_game *game_ref, t_bool *err_flag)
{
	texture_data->img = mlx_xpm_file_to_image(
		game_ref->screen_handle.mlx,
		(char *)path,
		&texture_data->width, &texture_data->height
	);
	if (texture_data->img)
		texture_data->addr = mlx_get_data_addr(
			texture_data->img,
			&texture_data->bits_per_pixel,
			&texture_data->line_length, &texture_data->endian
		);
	if (NULL == texture_data->img
		|| NULL == texture_data->addr
	)
		*err_flag = e_true;

	if (!texture_data->img || !texture_data->addr)
		printf(RED "NULL\n" RESET);
	else
		printf(GREEN "OK\n" RESET);
	printf(YELLOW "texture path:%sT\n" RESET, path);
	return (texture_data->width);
}

void	load_enemy_textures(t_game *game_ref, t_bool *err_flag)
{
	open_bg_texture(
		"./img/enemy/kindpng_200x200.xpm",
		 &game_ref->textures.enemy[0],
		game_ref, err_flag
	);
	open_bg_texture(
		"./img/enemy/kindpng_dead_200x200.xpm",
		 &game_ref->textures.enemy[1],
		game_ref, err_flag
	);
}

static void load_background_textures(t_game *game_ref, t_bool *err_flag)
{
	open_bg_texture(
		"./img/Background/background.xpm",
		 &game_ref->textures.background,
		game_ref, err_flag
	);
}

static void load_sun_textures(t_game *game_ref, t_bool *err_flag)
{
	open_bg_texture(
		"./img/Sun/frame-1.xpm",
		 &game_ref->textures.sun[0],
		game_ref, err_flag
	);
	open_bg_texture(
		"./img/Sun/frame-2.xpm",
		 &game_ref->textures.sun[1],
		game_ref, err_flag
	);
	open_bg_texture(
		"./img/Sun/frame-3.xpm",
		 &game_ref->textures.sun[2],
		game_ref, err_flag
	);
	open_bg_texture(
		"./img/Sun/frame-4.xpm",
		 &game_ref->textures.sun[3],
		game_ref, err_flag
	);
	open_bg_texture(
		"./img/Sun/frame-5.xpm",
		 &game_ref->textures.sun[4],
		game_ref, err_flag
	);
	open_bg_texture(
		"./img/Sun/frame-6.xpm",
		 &game_ref->textures.sun[5],
		game_ref, err_flag
	);
	open_bg_texture(
		"./img/Sun/frame-7.xpm",
		 &game_ref->textures.sun[6],
		game_ref, err_flag
	);
	open_bg_texture(
		"./img/Sun/frame-8.xpm",
		 &game_ref->textures.sun[7],
		game_ref, err_flag
	);
	open_bg_texture(
		"./img/Sun/frame-9.xpm",
		 &game_ref->textures.sun[8],
		game_ref, err_flag
	);
	open_bg_texture(
		"./img/Sun/frame-10.xpm",
		 &game_ref->textures.sun[9],
		game_ref, err_flag
	);
	open_bg_texture(
		"./img/Sun/frame-11.xpm",
		 &game_ref->textures.sun[10],
		game_ref, err_flag
	);
	open_bg_texture(
		"./img/Sun/frame-12.xpm",
		 &game_ref->textures.sun[11],
		game_ref, err_flag
	);
	open_bg_texture(
		"./img/Sun/frame-13.xpm",
		 &game_ref->textures.sun[12],
		game_ref, err_flag
	);
	open_bg_texture(
		"./img/Sun/frame-14.xpm",
		 &game_ref->textures.sun[13],
		game_ref, err_flag
	);
	open_bg_texture(
		"./img/Sun/frame-15.xpm",
		 &game_ref->textures.sun[14],
		game_ref, err_flag
	);
	open_bg_texture(
		"./img/Sun/frame-16.xpm",
		 &game_ref->textures.sun[15],
		game_ref, err_flag
	);
	open_bg_texture(
		"./img/Sun/frame-17.xpm",
		 &game_ref->textures.sun[16],
		game_ref, err_flag
	);
	open_bg_texture(
		"./img/Sun/frame-18.xpm",
		 &game_ref->textures.sun[17],
		game_ref, err_flag
	);
	open_bg_texture(
		"./img/Sun/frame-19.xpm",
		 &game_ref->textures.sun[18],
		game_ref, err_flag
	);
}

/**
 * @brief this function opens the textures of the game.
 * All textures are 200 px wide squares.
 * Everything but walls can have a padding with transparent px (e.g. enemies)
 * 
 * @param game_ref 
 */
void	load_textures(t_game *game_ref, t_bool *err_flag)
{
	size_t	north_texture_size;
	size_t	south_texture_size;
	size_t	west_texture_size;
	size_t	east_texture_size;

	north_texture_size = open_texture(game_ref->map_handle.no_texture,
		&game_ref->textures.wall.north, game_ref, err_flag
	);
	south_texture_size = open_texture(game_ref->map_handle.so_texture,
		&game_ref->textures.wall.south, game_ref, err_flag
	);
	west_texture_size = open_texture(game_ref->map_handle.we_texture,
		&game_ref->textures.wall.west, game_ref, err_flag
	);
	east_texture_size = open_texture(game_ref->map_handle.ea_texture,
		&game_ref->textures.wall.east, game_ref, err_flag
	);
	if (north_texture_size != south_texture_size
		|| north_texture_size != west_texture_size
		|| north_texture_size != east_texture_size
	)
		*err_flag = e_true;
	else
		texture_pt_clipper(e_TEXTURE_CLIPPER_INITIALIZE, north_texture_size);
	load_background_textures(game_ref, err_flag);
	load_sun_textures(game_ref, err_flag);
	load_enemy_textures(game_ref, err_flag);
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
	game_ref->screen_handle.frame_data.width = width;
	game_ref->screen_handle.frame_data.height = height;
	mlx_holder_set(&game_ref->screen_handle);
}

void	game_set_key_state(t_game *game_ref)
{
	// const t_key_state keys[BOUND_KEYS] = {
	// 	(t_key_state){e_UP_KEY, -1},
	// 	(t_key_state){e_DOWN_KEY, -1},
	// 	(t_key_state){e_RIGHT_KEY, -1},
	// 	(t_key_state){e_LEFT_KEY, -1},
	// 	(t_key_state){e_W_KEY, -1},
	// 	(t_key_state){e_A_KEY, -1},
	// 	(t_key_state){e_S_KEY, -1},
	// 	(t_key_state){e_D_KEY, -1},
	// 	(t_key_state){e_E_KEY, -1},
	// 	(t_key_state){e_Q_KEY, -1},
	// 	(t_key_state){e_SPACE_KEY, -1},
	// 	(t_key_state){e_TAB_KEY, -1},
	// 	(t_key_state){e_CTRL_KEY, -1},
	// 	(t_key_state){e_CMD_KEY, -1},
	// }

	size_t	cur_key;

	cur_key = 0;
	while (cur_key < BOUND_KEYS)
	{
		game_ref->keys[cur_key].state = -1;
		cur_key += 1;
	}
	// return (keys);
}

static void	game_set_inital_vectors( t_game *game_ref )
{
	const t_tile	player_init_dir = game_ref->map_handle.player_initial_dir;
	t_tile **const	map = game_ref->map_handle.map;
	size_t			row;
	size_t			col;

	initial_dir_vectors(
		game_ref->map_handle.player_initial_dir,
		&game_ref->player.dir, &game_ref->player.camera_plane
	);
	row = 0;
	while (row < game_ref->map_handle.rows)
	{
		col = 0;
		while (col < game_ref->map_handle.columns)
		{
			printf("%c ", map[row][col]);
			if (player_init_dir == map[row][col])
			{
				game_ref->player.pos.y = row + 0.5f;
				game_ref->player.pos.x = col + 0.5f;
				break ;
			}
			col += 1;
		}
		printf("\n");
		row += 1;
	}
	printf("\n");
}

static void	initial_dir_vectors(
				t_tile inital_dir,
				t_2d_point *player_dir, t_2d_point *camera_plane
			)
{
	const float	scaling_factor = tan(FOV / 2);

	if (e_PLAYER_N == inital_dir)
		*player_dir = ft_get_new_2dpt(0, +1);
	else if (e_PLAYER_S == inital_dir)
		*player_dir = ft_get_new_2dpt(0, -1);
	else if (e_PLAYER_W == inital_dir)
		*player_dir = ft_get_new_2dpt(+1, 0);
	else if (e_PLAYER_E == inital_dir)
		*player_dir = ft_get_new_2dpt(-1, 0);
	else
		return;
	*camera_plane = ft_rotate(*player_dir, M_PI / 2);
	// ft_print_2d_point("CAMERA PLANE", *camera_plane);
	*camera_plane = ft_change_magnitude(*camera_plane, scaling_factor);
	// printf(BOLDCYAN RESET)
	// ft_print_2d_point("CAMERA PLANE", *camera_plane);
	// printf(BOLDCYAN "tan: %lf" RESET, scaling_factor);
}
