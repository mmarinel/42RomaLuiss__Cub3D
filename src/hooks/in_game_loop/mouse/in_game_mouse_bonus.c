/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_game_mouse_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:58:58 by earendil          #+#    #+#             */
/*   Updated: 2023/01/05 13:52:09 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "in_game_mouse_bonus.h"

static float	get_rot_angle(
	const t_int_2d_point *mouse_pos,
	const t_int_2d_point *prev_pos,
	t_game *g);
//*		end of static declarations

void	in_game_mouse_handler(t_game *game)
{
	static t_int_2d_point	prev_pos = (t_int_2d_point){-1, -1};
	t_int_2d_point			mouse_pos;
	float					rot_angle;

	mlx_mouse_get_pos(game->screen_handle.mlx, game->screen_handle.window,
		&mouse_pos.x, &mouse_pos.y
		);
	if (ft_int_2d_point_equals(&prev_pos, &(t_int_2d_point){-1, -1}))
		prev_pos = mouse_pos;
	else if (mouse_pos.x < 0 || mouse_pos.x >= SCREEN_WIDTH)
		return ;
	else if (prev_pos.x != mouse_pos.x)
	{
		rot_angle = get_rot_angle(&mouse_pos, &prev_pos, game);
		game->player.west_angle += rot_angle;
		game->player.dir = ft_rotate(
			game->player.dir, rot_angle
			);
		game->player.camera_plane = ft_rotate(
			game->player.camera_plane, rot_angle
			);
		prev_pos = mouse_pos;
	}
}

static float	get_rot_angle(
	const t_int_2d_point *mouse_pos,
	const t_int_2d_point *prev_pos,
	t_game *g)
{
	float		rot_angle;
	float		main_axis_angle;
	const float	inverse_rot_angle = (1.0f * M_PI) / 180.0f;

	main_axis_angle = M_PI / 2 - asin(
		1.0f / ft_vec_norm(ray_for_column(mouse_pos->x, g))
	);
	if (mouse_pos->x >= SCREEN_WIDTH / 2)
	{
		if (mouse_pos->x < prev_pos->x)
			rot_angle = (2 * M_PI - inverse_rot_angle);
		else
			rot_angle = (main_axis_angle);
	}
	else if (mouse_pos->x < SCREEN_WIDTH / 2)
	{
		if (mouse_pos->x > prev_pos->x)
			rot_angle = (inverse_rot_angle);
		else
			rot_angle = (2 * M_PI - main_axis_angle);
	}
	return (rot_angle);
}
