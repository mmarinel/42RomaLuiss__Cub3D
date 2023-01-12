/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sun_textures_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:39:04 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 12:38:11 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

static void	clean_first_batch(t_game *game);
static void	clean_second_batch(t_game *game);
static void	clean_third_batch(t_game *game);
static void	clean_fourth_batch(t_game *game);
//*		end of static declarations

void	sun_texture_clean(t_game *game)
{
	clean_first_batch(game);
	clean_second_batch(game);
	clean_third_batch(game);
	clean_fourth_batch(game);
}

static void	clean_first_batch(t_game *game)
{
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.sun[0].img
		);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.sun[1].img
		);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.sun[2].img
		);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.sun[3].img
		);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.sun[4].img
		);
}

static void	clean_second_batch(t_game *game)
{
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.sun[5].img
		);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.sun[6].img
		);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.sun[7].img
		);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.sun[8].img
		);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.sun[9].img
		);
}

static void	clean_third_batch(t_game *game)
{
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.sun[10].img
		);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.sun[11].img
		);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.sun[12].img
		);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.sun[13].img
		);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.sun[14].img
		);
}

static void	clean_fourth_batch(t_game *game)
{
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.sun[15].img
		);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.sun[16].img
		);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.sun[17].img
		);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.sun[18].img
		);
}
