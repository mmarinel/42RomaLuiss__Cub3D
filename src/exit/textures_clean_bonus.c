/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_clean_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:34:12 by earendil          #+#    #+#             */
/*   Updated: 2023/01/13 15:24:02 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	door_texture_clean(t_game *game)
{
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.door.open
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.door.ajar
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.door.closed
		);
}

void	background_texture_clean(t_game *game)
{
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.background
		);
}

void	enemy_texture_clean(t_game *game)
{
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.enemy[0]
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.enemy[1]
		);
}

void	item_texture_clean(t_game *game)
{
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.item
		);
}

void	menu_texture_clean(t_game *game)
{
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.menu[MENU_NEWG]
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.menu[MENU_EXIT]
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.game_over[MENU_NEWG]
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.game_over[MENU_EXIT]
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.game_win[MENU_NEWG]
		);
	ft_mlx_destroy_image(
		game->screen_handle.mlx,
		&game->textures.game_win[MENU_EXIT]
		);
}
