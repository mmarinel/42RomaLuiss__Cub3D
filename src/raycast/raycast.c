/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:03:29 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/10 12:42:53 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	ft_print_ray_data(t_raycast_data rc_data);
void		ft_print_ray_result(t_raycast_return raycast_info);
t_2d_point	ft_rotate(t_2d_point vector, double ray_angle);
t_dbl	ft_initial_delta(t_dbl p_ax_pos, t_dbl p_dir_ax_pos);
int	ft_ray_step_size(t_dbl p_dir_ax_pos);
void	ft_set_hp(t_raycast_return *raycast_info, t_game *game);
void	ft_set_hp_dist(t_raycast_return *rc_ret,
			t_raycast_data rc_data,
			double ray_angle
		);

static t_raycast_data	ft_ray_data_init(t_game *game, double ray_angle);
static void				ft_walk_through_nhp(t_raycast_data *raycast_data);
//*		enf of static declarations

static t_raycast_data ft_ray_data_init(t_game *game, double ray_angle)
{
	t_2d_point	ray_dir = ft_rotate(game->player_dir, ray_angle);
	t_raycast_data	rc_data = (t_raycast_data) {
		ray_dir,
		t_dbl_div(t_dbl_new(1), t_dbl_new(ft_dbl_abs(ray_dir.x.val))),
		t_dbl_div(t_dbl_new(1), t_dbl_new(ft_dbl_abs(ray_dir.y.val))),
		ft_ray_step_size(ray_dir.x),
		ft_ray_step_size(ray_dir.y),
		(int) game->player_pos.x.val,
		(int) game->player_pos.y.val,
		ft_initial_delta(game->player_pos.x, game->player_dir.x),
		ft_initial_delta(game->player_pos.x, game->player_dir.x),
		e_SIDE_NONE
		};

	return (rc_data);
}

static void				ft_walk_through_nhp(t_raycast_data *raycast_data)
{
	printf("iter\n");
	ft_print_ray_data(*raycast_data);
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
	ft_print_ray_data(*raycast_data);
}

t_raycast_return	raycast(t_game *game, double ray_angle)
{
	t_raycast_return	ret;
	t_raycast_data		raycast_data;
	t_bool				hit;
	int					cur_sq_x;
	int					cur_sq_y;
	
	raycast_data = ft_ray_data_init(game, ray_angle);
	ft_print_ray_data(raycast_data);
	exit(0);
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
	ft_set_hp(&ret, game);
	return (ret);
}

void	ft_set_hp(t_raycast_return *raycast_info, t_game *game)
{
	{
		raycast_info->hit_point.x
			= t_dbl_sum(
				game->player_pos.x,
				t_dbl_mult(game->player_dir.x, raycast_info->euclidean_dist)
				);
	}
	{
		raycast_info->hit_point.y
			= t_dbl_sum(
				game->player_pos.y,
				t_dbl_mult(game->player_dir.y, raycast_info->euclidean_dist)
				);
	}
}

void	ft_set_hp_dist(t_raycast_return *rc_ret,
			t_raycast_data rc_data,
			double ray_angle
		)
{
	const t_dbl	dist_nhp_through_x = t_dbl_diff(rc_data.dist_nhp_through_x, rc_data.delta_x);
	const t_dbl	dist_nhp_through_y = t_dbl_diff(rc_data.dist_nhp_through_y, rc_data.delta_y);
	if (rc_data.side == e_VERTICAL)
		rc_ret->euclidean_dist = dist_nhp_through_x;
	else
		rc_ret->euclidean_dist = dist_nhp_through_y;
	rc_ret->perp_dist = t_dbl_mult(
		rc_ret->euclidean_dist,
		t_dbl_new( sin(ray_angle))
		);
}

t_dbl	ft_initial_delta(t_dbl p_ax_pos, t_dbl p_dir_ax_pos)
{
	int	sq_ax_pos;

	sq_ax_pos = (int) p_ax_pos.val;
	if (p_dir_ax_pos.val >= 0)
	{//*						can be inf !!!
		p_ax_pos = t_dbl_div(
			t_dbl_new(ft_int_abs(sq_ax_pos + 1 - p_ax_pos.val)),
			t_dbl_new(ft_dbl_abs(p_dir_ax_pos.val))
		);
	}
	else
	{//*					CANNOT be inf !!!
		p_ax_pos = t_dbl_div(
			t_dbl_new(ft_int_abs(p_ax_pos.val - sq_ax_pos)),
			t_dbl_new(ft_dbl_abs(p_dir_ax_pos.val))
		);
	}
	return (p_ax_pos);
}

int	ft_ray_step_size(t_dbl p_dir_ax_pos)
{
	if (p_dir_ax_pos.val > 0.00000000001f)
		return (1);
	else if (p_dir_ax_pos.val < 0.0f)
		return (-1);
	else
		return (0);
}

void	ft_print_ray_result(t_raycast_return raycast_info)
{
	printf(YELLOW"---RAY-CAST-" CYAN"RET"RESET "---PRINT---\n"RESET);
	ft_print_2d_point("hit_point", raycast_info.hit_point);
	ft_print_2d_point("square", raycast_info.hit_point);
	if (raycast_info.side == e_HORIZONTAL)
		printf(YELLOW "side is HORIZONTAL\n" RESET);
	else
		printf(YELLOW "side is VERTICAL\n" RESET);
	printf(YELLOW"Euclidean distance is: %lf\n"RESET, raycast_info.euclidean_dist.val);
	printf(YELLOW"Perp distance is: %lf\n"RESET, raycast_info.perp_dist.val);
}

void	ft_print_ray_data(t_raycast_data rc_data)
{
	printf(YELLOW"---RAY-CAST-" BOLDGREEN"DATA"RESET "---PRINT---\n"RESET);
	ft_print_2d_point("ray_dir", rc_data.ray_dir); printf("\n");
	printf("delta_x: "); ft_print_t_dbl(rc_data.delta_x); printf("\n");
	printf("delta_y: "); ft_print_t_dbl(rc_data.delta_y); printf("\n");
	printf("step_x: %d", rc_data.step_x); printf("\n");
	printf("step_y: %d", rc_data.step_y); printf("\n");
	printf("cursq_x: %d", rc_data.cur_sq_x); printf("\n");
	printf("cursq_y: %d", rc_data.cur_sq_y); printf("\n");
	printf("dist_nhp_through_x: "); ft_print_t_dbl(rc_data.dist_nhp_through_x); printf("\n");
	printf("dist_nhp_through_y: "); ft_print_t_dbl(rc_data.dist_nhp_through_y); printf("\n");
	if (e_HORIZONTAL == rc_data.side)
		printf("side: e_HORIZONTAL\n");
	else if (e_VERTICAL == rc_data.side)
		printf("side: e_VERTICAL\n");
	else
		printf("side: e_SIDE_NONE\n");
}
