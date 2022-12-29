/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:58:58 by earendil          #+#    #+#             */
/*   Updated: 2022/12/29 17:46:32 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys_behavior.h"

static int		get_rot_sign(
	const t_int_2d_point *mouse_pos,
	const t_int_2d_point *prev_pos
	);
static float	get_rot_angle(
	const t_int_2d_point *mouse_pos,
	const t_int_2d_point *prev_pos,
	t_game *g);
//*		end of static declarations

void	mouse_hook(t_game *game)
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

static int		get_rot_sign(
	const t_int_2d_point *mouse_pos,
	const t_int_2d_point *prev_pos
	)
{
	if (mouse_pos->x < prev_pos->x)
		return (-1);
	else if (mouse_pos->x == prev_pos->x)
		return (0);
	else
		return (+1);
}

static float	get_rot_angle(
	const t_int_2d_point *mouse_pos,
	const t_int_2d_point *prev_pos,
	t_game *g)
{
	int		rot_sign;
	float	theta;
	
	rot_sign = get_rot_sign(mouse_pos, prev_pos);
	theta = M_PI / 2 - asin(
		1.0f / ft_vec_norm(ray_for_column(mouse_pos->x, g))
	);
	if (rot_sign > 0)
		return (theta);
	else if (0 == rot_sign)
		return (0);
	else
		return (2 * M_PI - theta);
}
