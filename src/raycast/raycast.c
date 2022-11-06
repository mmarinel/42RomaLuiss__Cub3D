/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:03:29 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/06 20:15:53 by mmarinel         ###   ########.fr       */
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

t_raycast_return	raycast(t_game *game, double ray_angle)
{
	t_raycast_return	ret;
	t_bool				hit;
	t_2d_point			ray_dir;
	double				dist_nhp_through_x;
	double				dist_nhp_through_y;
	const double		delta_x = game->player_dir.x != 0 ? 1 / ft_dbl_abs(game->player_dir.x) : __DBL_MAX__;
	const double		delta_y = game->player_dir.y != 0 ? 1 / ft_dbl_abs(game->player_dir.y) : __DBL_MAX__;
	int					cur_square_x;
	int					cur_square_y;
	int					step_x;//TODO const
	int					step_y;//TODO const
	t_side				side;

	ray_dir = ft_rotate(game->player_dir, ray_angle);
	dist_nhp_through_x = ft_initial_delta(game->player_pos.x, game->player_dir.x);
	dist_nhp_through_y = ft_initial_delta(game->player_pos.y, game->player_dir.y);
	printf(YELLOW "\ndist_nhp_through_x: %lf; dist_nhp_through_y: %lf\n\n\n" RESET, dist_nhp_through_x, dist_nhp_through_y);
	printf(YELLOW "delta_x: %lf; delta_y: %lf\n\n\n" RESET, delta_x, delta_y);
	// exit(0);
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
			side = e_VERTICAL;
			printf(RED "HERE\n" RESET);
			exit(0);
		}
		else
		{
			cur_square_y = cur_square_y + step_y;
			dist_nhp_through_y += delta_y;
			side = e_HORIZONTAL;
		}
		printf(BOLDGREEN "dist_nhp_through_x: %lf; dist_nhp_through_y: %lf\n, cur_square_x: %d; cur_square_y: %d\n\n" RESET,
			dist_nhp_through_x, dist_nhp_through_y, cur_square_x, cur_square_y);
		if (e_WALL == *( *(game->map_handle.map + cur_square_y) + cur_square_x) )
			hit = e_true;
		else
			printf(BOLDGREEN "map[cur_square_y][cur_square_x]: %d\n" RESET, game->map_handle.map[cur_square_y][cur_square_x]);
	}
	ft_set_hp_dist(&ret, dist_nhp_through_x, dist_nhp_through_y, ray_angle);
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
