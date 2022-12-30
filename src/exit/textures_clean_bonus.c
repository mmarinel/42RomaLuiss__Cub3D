/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_clean_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 17:34:12 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 17:38:40 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	door_texture_clean(t_game *game)
{
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.door.open.img
	);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.door.ajar.img
	);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.door.closed.img
	);
}

void	background_texture_clean(t_game *game)
{
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.background.img
	);
}

void	enemy_texture_clean(t_game *game)
{
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.enemy[0].img
	);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.enemy[1].img
	);
}

void	item_texture_clean(t_game *game)
{
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.item.img
	);
}

void	menu_texture_clean(t_game *game)
{
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.menu[MENU_NEWG].img
	);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.menu[MENU_EXIT].img
	);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.game_over[MENU_NEWG].img
	);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.game_over[MENU_EXIT].img
	);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.game_win[MENU_NEWG].img
	);
	mlx_destroy_image(
		game->screen_handle.mlx,
		game->textures.game_win[MENU_EXIT].img
	);
}
