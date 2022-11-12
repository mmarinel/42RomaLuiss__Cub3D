/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_initialization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:25:05 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/12 18:29:44 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

t_raycast_data	ft_ray_data_init(t_game *game, float ray_angle)
{
	t_2d_point	ray_dir = ft_rotate(game->player_dir, ray_angle);
	t_raycast_data	rc_data = (t_raycast_data) {
		ray_dir,
		1 / ft_flt_abs(ray_dir.x),
		1 / ft_flt_abs(ray_dir.y),
		ft_ray_step_size(ray_dir.x),
		ft_ray_step_size(ray_dir.y),
		(int) game->player_pos.x,
		(int) game->player_pos.y,
		ft_initial_delta(game->player_pos.x, ray_dir.x),
		ft_initial_delta(game->player_pos.y, ray_dir.y),
		e_SIDE_NONE
		};

	return (rc_data);
}

float	ft_initial_delta(float p_ax_pos, float p_dir_ax_pos)
{
	int	sq_ax_pos;

	sq_ax_pos = (int) p_ax_pos;
	if (p_dir_ax_pos > 0)
	{//*						can be inf !!!
		p_ax_pos = flt_round(((float) sq_ax_pos + 1 - p_ax_pos) / ft_flt_abs(p_dir_ax_pos), 6);
	}
	else if (p_dir_ax_pos < 0)
	{//*					CANNOT be inf !!!
		p_ax_pos = flt_round(((float) p_ax_pos - sq_ax_pos) / ft_flt_abs(p_dir_ax_pos), 6);
	}
	else
		p_ax_pos = INFINITY;
	return (p_ax_pos);
}

int	ft_ray_step_size(float p_dir_ax_pos)
{
	if (p_dir_ax_pos > 0.0f)
		return (1);
	else if (p_dir_ax_pos < 0.0f)
		return (-1);
	else
		return (0);
}
