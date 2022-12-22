/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:45:01 by earendil          #+#    #+#             */
/*   Updated: 2022/12/22 19:38:58 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../keys_behavior.h"

static t_2d_point	new_player_pos_direction(t_key key_pressed, t_game *game);
//*		end of static declarations

t_2d_point	new_player_pos(
	t_key key_pressed,
	t_game *game
	)
{
	const float	player_step_size = 0.5f;
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

t_raycast_return	raycast_for_newpos_mov(
	const t_2d_point *new_pos, t_game *game
	)
{
	const t_2d_point	mov_dir = ft_vec_normalize(
		ft_vec_sum(
			ft_vec_opposite(game->player.pos),
			*new_pos
		)
	);

	return (raycast_movements(game, mov_dir, new_pos));
}

void	move_across_door(t_game *game, t_2d_point *guessed, t_key keycode)
{
	const t_int_2d_point	door_square = as_int_2dpt(guessed);
	t_2d_point				new_pos;
	t_list					*door_node;
	t_door					*door;

	door_node = ft_lstfind(game->doors, door_pos, &door_square);
	if (NULL == door_node)
		return ;
	door = (t_door *)door_node->content;
	if (NULL == door)
		return ;
	if (e_DOOR_OPEN == door->status)
	{
		new_pos = map_pos_clip(
			ft_vec_sum(
				*guessed,
				new_player_pos_direction(keycode, game)
				),
				game
		);
		if (is_free_pos(game, new_pos))
			game->player.pos = new_pos;
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
		return ((t_2d_point){0,0});
}
