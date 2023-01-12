/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_initialization.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:25:05 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/12 11:12:37 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rc_utils.h"

static float	ft_initial_delta(float p_ax_pos, float p_dir_ax_pos);
static int		ft_ray_step_size(float p_dir_ax_pos);
//*		end of static declarations

void	ft_ray_data_init(t_raycast_data *rc_data,
			const t_2d_point *pos, const t_2d_point *ray
	)
{
	rc_data->ray = *ray;
	rc_data->ray_dir = ft_vec_normalize(*ray);
	rc_data->delta_x = (float)1 / ft_flt_abs(rc_data->ray_dir.x);
	rc_data->delta_y = (float)1 / ft_flt_abs(rc_data->ray_dir.y);
	rc_data->step_x = ft_ray_step_size(rc_data->ray_dir.x);
	rc_data->step_y = ft_ray_step_size(rc_data->ray_dir.y);
	rc_data->cur_sq.x = (int)pos->x;
	rc_data->cur_sq.y = (int)pos->y;
	rc_data->prev_sq = rc_data->cur_sq;
	rc_data->dist_nhp_through_x = ft_initial_delta(pos->x, rc_data->ray_dir.x);
	rc_data->dist_nhp_through_y = ft_initial_delta(pos->y, rc_data->ray_dir.y);
	rc_data->spotted_enemy.enemy = NULL;
	rc_data->spotted_item.item = NULL;
	rc_data->doors = NULL;
	rc_data->door_obstacle = e_false;
	rc_data->side = e_SIDE_NONE;
}

static float	ft_initial_delta(float p_ax_pos, float p_dir_ax_pos)
{
	int	sq_ax_pos;

	sq_ax_pos = (int) p_ax_pos;
	if (p_dir_ax_pos > 0)
	{
		p_ax_pos = (
				((float) sq_ax_pos + 1 - p_ax_pos) / ft_flt_abs(p_dir_ax_pos)
				);
	}
	else if (p_dir_ax_pos < 0)
	{
		p_ax_pos = (
				((float) p_ax_pos - sq_ax_pos) / ft_flt_abs(p_dir_ax_pos)
				);
	}
	else
		p_ax_pos = INFINITY;
	return (p_ax_pos);
}

static int	ft_ray_step_size(float p_dir_ax_pos)
{
	if (p_dir_ax_pos > 0.0f)
		return (1);
	else if (p_dir_ax_pos < 0.0f)
		return (-1);
	else
		return (0);
}
