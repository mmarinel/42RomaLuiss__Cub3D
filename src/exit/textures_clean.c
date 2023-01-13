/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_clean.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:30:11 by earendil          #+#    #+#             */
/*   Updated: 2023/01/13 15:24:46 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	wall_texture_clean(t_game *game)
{
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.wall.north
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.wall.south
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.wall.east
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.wall.west
		);
}
