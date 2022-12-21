/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:45:01 by earendil          #+#    #+#             */
/*   Updated: 2022/12/21 18:40:15 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../keys_behavior.h"

int	new_player_pos_direction(int key_pressed)
{
	if (e_W_KEY == key_pressed)
		return (+1);
	else if (e_S_KEY == key_pressed)
		return (-1);
	else
		return (0);
}

t_2d_point	new_player_pos(
	int key_pressed,
	t_game *game
	)
{
	const float	player_step_size = 0.5f;
	int			sign;

	sign = new_player_pos_direction(key_pressed);
	return (
		map_pos_clip(
			ft_vec_sum(
				game->player.pos,
				ft_vec_prod(
					game->player.dir,
					player_step_size * sign
				)
			),
			game
		)
	);
}

void	move_across_door(t_game *game, t_2d_point *guessed, t_key keycode)
{
	const t_int_2d_point	door_square = as_int_2dpt(guessed);
	t_2d_point				new_pos;
	int						sign;
	t_list					*door_node;
	t_door					*door;

	door_node = ft_lstfind(game->doors, door_pos, &door_square);
	if (e_W_KEY == keycode)
		sign = +1;
	else
		sign = -1;
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
				ft_vec_prod(game->player.dir, sign)
				),
				game
		);
		if (is_free_pos(game, new_pos))
			game->player.pos = new_pos;
	}
}
