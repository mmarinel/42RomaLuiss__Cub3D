/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:44:15 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 12:36:55 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

static void	t_map_holder_clean(t_game *game);
static void	t_screen_holder_clean(t_game *game);
static void	textures_clean(t_game *game);
//*		end of static declarations

void	clean_game(t_game *game)
{
	ft_lstclear(&game->doors, free);
	ft_lstclear(&game->items, free);
	ft_lstclear(&game->enemies, free);
	t_map_holder_clean(game);
	if (game->textures.loaded)
		textures_clean(game);
	t_game_set_nulls(game);
}

int	exit_game(t_game *game)
{
	clean_game(game);
	t_screen_holder_clean(game);
	exit(EXIT_SUCCESS);
	return (0);
}

static void	t_map_holder_clean(t_game *game)
{
	size_t	i;

	ft_free(game->map_handle.no_texture);
	ft_free(game->map_handle.so_texture);
	ft_free(game->map_handle.ea_texture);
	ft_free(game->map_handle.we_texture);
	i = 0;
	while (i < game->map_handle.rows)
	{
		ft_free(game->map_handle.map[i]);
		i++;
	}
	ft_free(game->map_handle.map);
}

static void	t_screen_holder_clean(t_game *game)
{
	mlx_destroy_image(
		game->screen_handle.mlx, game->screen_handle.frame_data.img
		);
	mlx_destroy_window(
		game->screen_handle.mlx, game->screen_handle.window
		);
	mlx_destroy_display(game->screen_handle.mlx);
	free(game->screen_handle.mlx);
}

static void	textures_clean(t_game *game)
{
	wall_texture_clean(game);
	if (BONUS)
	{
		door_texture_clean(game);
		background_texture_clean(game);
		sun_texture_clean(game);
		enemy_texture_clean(game);
		item_texture_clean(game);
		menu_texture_clean(game);
	}
}
