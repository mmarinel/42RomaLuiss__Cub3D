/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   west_angle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:16:13 by earendil          #+#    #+#             */
/*   Updated: 2022/12/21 18:17:12 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

void	west_angle_update(t_game *game)
{
	if (game->player.west_angle >= 2 * M_PI)
		game->player.west_angle
			-= 2 * M_PI;
	else if (game->player.west_angle < 0)
		game->player.west_angle
			= 2 * M_PI - ft_flt_abs(game->player.west_angle);
}
