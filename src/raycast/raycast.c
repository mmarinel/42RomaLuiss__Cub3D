/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:03:29 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/10 10:46:02 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void		ft_print_ray_result(t_raycast_return raycast_info);
t_2d_point	ft_rotate(t_2d_point vector, double ray_angle);
double	ft_initial_delta(double p_ax_pos, double p_dir_ax_pos);
int	ft_ray_step_size(double p_dir_ax_pos);
void	ft_set_hp(t_raycast_return *raycast_info, t_game *game);
void	ft_set_hp_dist(t_raycast_return *raycast_info,
			double dist_hp_through_x, double dist_hp_through_y,
			double ray_angle
		);

static t_raycast_data	ft_ray_data_init(t_game *game, double ray_angle);
static t_dbl			ft_init_delta(t_raycast_data raycast_data, t_bool axis);
static void				ft_walk_through_nhp(t_raycast_data *raycast_data);
//*		enf of static declarations

static t_raycast_data ft_ray_data_init(t_game *game, double ray_angle)
{
	t_raycast_data	rc_data = (t_raycast_data) {
		ft_rotate(game->player_dir, ray_angle),
		t_dbl_div(t_dbl_new(1), t_dbl_new(ft_dbl_abs(rc_data.ray_dir.x.val))),
		t_dbl_div(t_dbl_new(1), t_dbl_new(ft_dbl_abs(rc_data.ray_dir.y.val))),
		ft_ray_step_size(rc_data.ray_dir.x.val),
		ft_ray_step_size(rc_data.ray_dir.y.val),
		(int) game->player_pos.x.val,
		(int) game->player_pos.y.val,
		ft_initial_delta(game->player_pos.x.val, game->player_dir.x.val),
		ft_initial_delta(game->player_pos.x.val, game->player_dir.x.val),
		e_SIDE_NONE
		};
}

static void				ft_walk_through_nhp(t_raycast_data *raycast_data)
{
	if (t_dbl_cmp(
		raycast_data->dist_nhp_through_x,
		raycast_data->dist_nhp_through_y
		) < 0)
	{
		raycast_data->cur_sq_x = raycast_data->cur_sq_x + raycast_data->step_x;
		raycast_data->dist_nhp_through_x.val += raycast_data->delta_x.val;
		raycast_data->side = e_VERTICAL;
	}
	else
	{
		raycast_data->cur_sq_y = raycast_data->cur_sq_y + raycast_data->step_y;
		raycast_data->dist_nhp_through_y.val += raycast_data->delta_y.val;
		raycast_data->side = e_HORIZONTAL;
	}
}

t_raycast_return	raycast(t_game *game, double ray_angle)
{
	t_raycast_return	ret;
	t_raycast_data		raycast_data;
	t_bool				hit;
	int					cur_sq_x;
	int					cur_sq_y;
	
	raycast_data = ft_ray_data_init(game, ray_angle);
	hit = e_false;
	while (e_false == hit)
	{
		ft_walk_through_nhp(&raycast_data);
		cur_sq_x = raycast_data.cur_sq_x;
		cur_sq_y = raycast_data.cur_sq_y;
		if (e_WALL == game->map_handle.map[cur_sq_y][cur_sq_x])
			hit = e_true;
	}
	ft_set_hp_dist(&ret, raycast_data.dist_nhp_through_x.val, raycast_data.dist_nhp_through_y.val, ray_angle);
	ft_set_hp(&ret, game);
	return (ret);
}

void	ft_set_hp(t_raycast_return *raycast_info, t_game *game)
{
	{
		raycast_info->hit_point.x
			= game->player_pos.x
				+ (game->player_dir.x * raycast_info->euclidean_dist);
	}
	{
		raycast_info->hit_point.y
			= game->player_pos.y
				+ (game->player_dir.y * raycast_info->euclidean_dist);
	}
}

void	ft_set_hp_dist(t_raycast_return *raycast_info,
			double dist_hp_through_x, double dist_hp_through_y,
			double ray_angle
		)
{
	if (dist_hp_through_x > dist_hp_through_y && dist_hp_through_x != __DBL_MAX__)
		raycast_info->euclidean_dist = dist_hp_through_x;
	else
		raycast_info->euclidean_dist = dist_hp_through_y;
	raycast_info->perp_dist = raycast_info->euclidean_dist * sin(ray_angle);
}

double	ft_initial_delta(double p_ax_pos, double p_dir_ax_pos)
{
	int	sq_ax_pos;

	sq_ax_pos = (int) p_ax_pos;
	if (p_dir_ax_pos > 0)
	{
		p_ax_pos = ft_int_abs(sq_ax_pos + 1 - p_ax_pos) / ft_dbl_abs(p_dir_ax_pos);
	}
	else if (0 == p_dir_ax_pos)
	{
		p_ax_pos = __DBL_MAX__;
	}
	else
	{
		p_ax_pos = ft_int_abs(p_ax_pos - sq_ax_pos) / ft_dbl_abs(p_dir_ax_pos);
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

void	ft_print_ray_result(t_raycast_return raycast_info)
{
	ft_print_2d_point("hit_point", raycast_info.hit_point);
	ft_print_2d_point("square", raycast_info.hit_point);
	if (raycast_info.side == e_HORIZONTAL)
		printf(YELLOW "side is HORIZONTAL\n" RESET);
	else
		printf(YELLOW "side is VERTICAL\n" RESET);
	printf("Euclidean distance is: %lf\n", raycast_info.euclidean_dist);
	printf("Perp distance is: %lf\n", raycast_info.perp_dist);
}

/**
 * @brief 
 * 				mapX, mapY		coordinate del muro che colpiamo (hitpoint)
 * 				side 			dove colpiamo il muro
 * 				theta			angolo di incidenza
 * 				euclidean_dist	
 * 				perp_dist		proiezione ortogonale dello hitpoint
 */
