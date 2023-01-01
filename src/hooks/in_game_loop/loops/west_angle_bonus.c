/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   west_angle_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:16:13 by earendil          #+#    #+#             */
/*   Updated: 2023/01/01 19:36:42 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "in_game_loops_bonus.h"

void	west_angle_adjust(t_game *game)
{
	if (game->player.west_angle >= 2 * M_PI)
		game->player.west_angle
			-= 2 * M_PI;
	else if (game->player.west_angle < 0)
		game->player.west_angle
			= 2 * M_PI - ft_flt_abs(game->player.west_angle);
}
