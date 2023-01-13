/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:45:01 by earendil          #+#    #+#             */
/*   Updated: 2023/01/13 10:54:21 by mmarinel         ###   ########.fr       */
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
	float		player_step_size;
	float		player_step_ampl;
	t_2d_point	direction;
	t_2d_point	new_pos;

	direction = new_player_pos_direction(key_pressed, game);
	player_step_size = game->player.step_size;
	player_step_ampl = game->player.step_ampl;
	while (e_true)
	{
		new_pos = ft_vec_sum(
				game->player.pos,
				ft_vec_prod(
					direction, player_step_size * (player_step_ampl + 1)
					)
				);
		if (is_map_posf(&game->map_handle, &new_pos)
			&& is_free_pos(game, new_pos))
			return (new_pos);
		if (0 == player_step_ampl)
			return (map_pos_clip(new_pos, game));
		player_step_ampl -= game->player.acceleration;
	}
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
		return ((t_2d_point){0, 0});
}
