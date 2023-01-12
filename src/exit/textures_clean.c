/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:30:11 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 12:38:31 by alazzari         ###   ########.fr       */
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
