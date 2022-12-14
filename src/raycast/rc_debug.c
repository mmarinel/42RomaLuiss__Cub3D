/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_debug.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:26:47 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/14 13:21:27 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

void	ft_print_raycast_result(t_raycast_return raycast_info)
{
	printf(YELLOW"---RAY-CAST-" CYAN"RET"RESET "---PRINT---\n"RESET);
	ft_print_2d_point("hit_point", raycast_info.hit_point);
	ft_print_int_2d_point("square", raycast_info.square);
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
	printf("cursq_x: %d\n", rc_data.cur_sq.x);
	printf("cursq_y: %d\n", rc_data.cur_sq.y);
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
