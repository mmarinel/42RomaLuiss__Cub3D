/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_geometry.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:28:02 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 13:33:31 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_init.h"

static void	initial_pos_vector(
	const size_t row,
	const size_t col,
	t_game *game_ref
	);
static void	initial_dir_vectors(
	t_tile inital_dir,
	t_2d_point *player_dir, t_2d_point *camera_plane
			);
//*		end of static declarations

void	game_set_inital_vectors( t_game *game_ref )
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
			if (player_init_dir == map[row][col])
			{
				initial_pos_vector(row, col, game_ref);
				break ;
			}
			col += 1;
		}
		row += 1;
	}
}

static void	initial_pos_vector(
	const size_t row,
	const size_t col,
	t_game *game_ref
	)
{
	const float	horizontal_alignment = 0.5f;
	const float	vertical_alignment = 0.5f;

	game_ref->player.pos.y = row + vertical_alignment;
	game_ref->player.pos.x = col + horizontal_alignment;
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
	*camera_plane = ft_change_magnitude(*camera_plane, scaling_factor);
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
