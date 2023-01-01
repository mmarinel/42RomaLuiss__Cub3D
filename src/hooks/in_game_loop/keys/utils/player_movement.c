/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:45:01 by earendil          #+#    #+#             */
/*   Updated: 2023/01/01 19:18:44 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "in_game_key_utils.h"

static t_2d_point	new_player_pos_direction(t_key key_pressed, t_game *game);
//*		end of static declarations

t_2d_point	new_player_pos(
	t_key key_pressed,
	t_game *game
	)
{
	const float	player_step_size = 0.4f;
	t_2d_point	direction;

	direction = new_player_pos_direction(key_pressed, game);
	return (
		map_pos_clip(
			ft_vec_sum(
				game->player.pos,
				ft_vec_prod(direction, player_step_size)
			),
			game
		)
	);
}

static t_2d_point	new_player_pos_direction(t_key key_pressed, t_game *game)
{
	if (e_W_KEY == key_pressed)
		return (game->player.dir);
	else if (e_A_KEY == key_pressed)
		return (ft_rotate(game->player.dir, (3.0f / 2.0f) * M_PI));
	else if (e_S_KEY == key_pressed)
		return (ft_rotate(game->player.dir, M_PI));
	else if (e_D_KEY == key_pressed)
		return (ft_rotate(game->player.dir, M_PI / 2));
	else
		return ((t_2d_point){0,0});
}
