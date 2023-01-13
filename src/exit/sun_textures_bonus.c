/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sun_textures_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:39:04 by earendil          #+#    #+#             */
/*   Updated: 2023/01/13 15:22:45 by earendil         ###   ########.fr       */
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
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.sun[0]
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.sun[1]
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.sun[2]
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.sun[3]
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.sun[4]
		);
}

static void	clean_second_batch(t_game *game)
{
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.sun[5]
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.sun[6]
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.sun[7]
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.sun[8]
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.sun[9]
		);
}

static void	clean_third_batch(t_game *game)
{
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.sun[10]
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.sun[11]
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.sun[12]
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.sun[13]
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.sun[14]
		);
}

static void	clean_fourth_batch(t_game *game)
{
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.sun[15]
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.sun[16]
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.sun[17]
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.sun[18]
		);
}
