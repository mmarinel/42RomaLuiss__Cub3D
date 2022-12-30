/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:30:11 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 17:34:05 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	wall_texture_clean(t_game *game)
{
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.wall.north.img
	);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.wall.south.img
	);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.wall.east.img
	);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.wall.west.img
	);
}
