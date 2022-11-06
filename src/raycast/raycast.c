/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:03:29 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/06 13:26:38 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

t_raycast_return	raycast(t_game *game, double ray_angle)
{
	t_bool				hit;
	t_2d_point			ray_dir;
	double				dist_nhp_through_x;
	double				dist_nhp_through_y;
	const double		delta_x = 1 / ft_dbl_abs(game->player_dir.x);
	const double		delta_y = 1 / ft_dbl_abs(game->player_dir.y);
	double				cur_square_x;
	double				cur_square_y;
	int					step_x;
	int					step_y;
	t_side				side;

	ray_dir = ft_rotate(game->player_dir, ray_angle);
	dist_nhp_through_x = ft_initial_delta(game->player_dir.x);
	dist_nhp_through_y = ft_initial_delta(game->player_dir.y);
	cur_square_x = (int) game->player_pos.x;
	cur_square_y = (int) game->player_pos.y;
	step_x = ft_ray_step_size(game->player_dir.x);
	step_y = ft_ray_step_size(game->player_dir.y);
	hit = e_false;
	while (e_false == hit)
	{
		if (dist_nhp_through_x < dist_nhp_through_y)
		{
			cur_square_x = cur_square_x + step_x;
			dist_nhp_through_x += delta_x;
			side = e_HORIZONTAL;
		}
		else
		{
			cur_square_y = cur_square_y + step_y;
			dist_nhp_through_y += delta_y;
			side = e_VERTICAL;
		}
		if (game->map_handle.map[cur_square_x][cur_square_y] == e_WALL)
			hit = e_true;
	}
	return ();
}

double	ft_initial_delta(double p_ax_pos)
{
	int	sq_ax_pos;

	sq_ax_pos = (int) p_ax_pos;
	if (p_ax_pos > 0)
	{
		p_ax_pos = ft_int_abs(sq_ax_pos + 1 - p_ax_pos) / ft_dbl_abs(p_ax_pos);
	}
	else if (0 == p_ax_pos)
	{
		p_ax_pos = __DBL_MAX__;
	}
	else
	{
		p_ax_pos = ft_int_abs(p_ax_pos - sq_ax_pos) / ft_dbl_abs(p_ax_pos);
	}
	return (p_ax_pos);
}

int	ft_ray_step_size(double p_dir_ax_pos)
{
	if (p_dir_ax_pos > 0)
		return (1);
	else if (p_dir_ax_pos < 0)
		return (-1);
	else
		return (0);
}

/**
 * @brief 
 * 				mapX, mapY		coordinate del muro che colpiamo (hitpoint)
 * 				side 			dove colpiamo il muro
 * 				theta			angolo di incidenza
 * 				euclidean_dist	
 * 				perp_dist		proiezione ortogonale dello hitpoint
 */