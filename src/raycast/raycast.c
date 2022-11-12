/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:03:29 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/12 17:54:57 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void		ft_print_raycast_data(t_raycast_data rc_data);
void		ft_print_raycast_result(t_raycast_return raycast_info);
t_2d_point	ft_rotate(t_2d_point vector, float ray_angle);
float		ft_initial_delta(float p_ax_pos, float p_dir_ax_pos);
int			ft_ray_step_size(float p_dir_ax_pos);
void		ft_set_hp(t_raycast_return *raycast_info, t_raycast_data rc_data,
				t_game *game);
void		ft_set_hp_dist(t_raycast_return *rc_ret,
				t_raycast_data rc_data,
				float ray_angle
			);

static t_raycast_data	ft_ray_data_init(t_game *game, float ray_angle);
static void				ft_walk_through_nhp(t_raycast_data *raycast_data);
//*		enf of static declarations

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

static t_raycast_data ft_ray_data_init(t_game *game, float ray_angle)
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

/**
 * @brief 
 * 
 * @param game 
 * @param ray_angle angle the ray forms with the camera plane
 * @return t_raycast_return 
 */
t_raycast_return	raycast(t_game *game, float ray_angle)
{
	t_raycast_return	ret;
	t_raycast_data		raycast_data;
	t_bool				hit;
	int					cur_sq_x;
	int					cur_sq_y;

	raycast_data = ft_ray_data_init(game, ray_angle - M_PI / 2);
	ft_print_raycast_data(raycast_data);
	// exit(0);
	hit = e_false;
	while (e_false == hit)
	{
		ft_walk_through_nhp(&raycast_data);
		cur_sq_x = raycast_data.cur_sq_x;
		cur_sq_y = raycast_data.cur_sq_y;
		if (e_WALL == game->map_handle.map[cur_sq_y][cur_sq_x])
			hit = e_true;
	}
	ft_set_hp_dist(&ret, raycast_data, ray_angle);
	ft_set_hp(&ret, raycast_data, game);
	return (ret);
}

static void				ft_walk_through_nhp(t_raycast_data *rc_data)
{
	printf(GREEN "iter\n" RESET);
	ft_print_raycast_data(*rc_data);
	if (rc_data->dist_nhp_through_x < rc_data->dist_nhp_through_y)
	{
		rc_data->cur_sq_x = rc_data->cur_sq_x + rc_data->step_x;
		rc_data->dist_nhp_through_x += rc_data->delta_x;
		rc_data->side = e_VERTICAL;
	}
	else
	{
		rc_data->cur_sq_y = rc_data->cur_sq_y + rc_data->step_y;
		rc_data->dist_nhp_through_y += rc_data->delta_y;
		rc_data->side = e_HORIZONTAL;
	}
	ft_print_raycast_data(*rc_data);
}

void	ft_set_hp_dist(t_raycast_return *rc_ret,
			t_raycast_data rc_data,
			float ray_angle
		)
{
	const float	dist_nhp_through_x = flt_round(rc_data.dist_nhp_through_x - rc_data.delta_x, 6);
	const float	dist_nhp_through_y = flt_round(rc_data.dist_nhp_through_y - rc_data.delta_y, 6);

	printf(YELLOW"ft_set_hp_dist\t dist_nhp_through_x: %lf; dist_nhp_through_y: %lf\n", dist_nhp_through_x, dist_nhp_through_y);
	if (rc_data.side == e_VERTICAL)
		rc_ret->euclidean_dist = flt_round(dist_nhp_through_x, 6);
	else
		rc_ret->euclidean_dist = flt_round(dist_nhp_through_y, 6);
	rc_ret->perp_dist = flt_round(rc_ret->euclidean_dist * sin(ray_angle), 6);
}

void	ft_set_hp(t_raycast_return *raycast_info, t_raycast_data rc_data,
			t_game *game)
{
	{
		raycast_info->hit_point.x
			= flt_round(
				game->player_pos.x
				+ (rc_data.ray_dir.x * raycast_info->euclidean_dist),
				4
			);
	}
	{
		raycast_info->hit_point.y
			= flt_round(
				game->player_pos.y
				+ (rc_data.ray_dir.y * raycast_info->euclidean_dist),
				4
			);
	}
	raycast_info->square.x = rc_data.cur_sq_x;
	raycast_info->square.y = rc_data.cur_sq_y;
}

void	ft_print_raycast_result(t_raycast_return raycast_info)
{
	printf(YELLOW"---RAY-CAST-" CYAN"RET"RESET "---PRINT---\n"RESET);
	ft_print_2d_point("hit_point", raycast_info.hit_point);
	ft_print_2d_point("square", raycast_info.square);
	if (raycast_info.side == e_HORIZONTAL)
		printf(YELLOW "side is HORIZONTAL\n" RESET);
	else
		printf(YELLOW "side is VERTICAL\n" RESET);
	printf(YELLOW"Euclidean distance is: %lf\n"RESET, raycast_info.euclidean_dist);
	printf(YELLOW"Perp distance is: %lf\n"RESET, raycast_info.perp_dist);
	printf("\n");
}

void	ft_print_raycast_data(t_raycast_data rc_data)
{
	printf(YELLOW"---RAY-CAST-" BOLDGREEN"DATA"RESET "---PRINT---\n"RESET);
	ft_print_2d_point("ray_dir", rc_data.ray_dir); printf("\n");
	printf(BOLDRED "const " RESET "delta_x: %lf\n", rc_data.delta_x);
	printf(BOLDRED "const " RESET "delta_y: %lf\n", rc_data.delta_y);
	printf(BOLDRED "const " RESET "step_x: %d\n", rc_data.step_x);
	printf(BOLDRED "const " RESET "step_y: %d\n", rc_data.step_y);
	printf("cursq_x: %d\n", rc_data.cur_sq_x);
	printf("cursq_y: %d\n", rc_data.cur_sq_y);
	printf("dist_nhp_through_x: %lf\n", rc_data.dist_nhp_through_x);
	printf("dist_nhp_through_y: %lf\n", rc_data.dist_nhp_through_y);
	if (e_HORIZONTAL == rc_data.side)
		printf("side: e_HORIZONTAL\n");
	else if (e_VERTICAL == rc_data.side)
		printf("side: e_VERTICAL\n");
	else
		printf("side: e_SIDE_NONE\n");
	printf("\n");
}
