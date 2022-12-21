/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   E_key_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:23:29 by earendil          #+#    #+#             */
/*   Updated: 2022/12/21 18:32:09 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "keys_behavior.h"

static void		open_door(t_game *game);
static t_bool	door_opened(t_2d_point forward_pos, t_game *game);
//*		end of static declarations

void	e_key_handler(t_game *game)
{
	open_door(game);
}

static void	open_door(t_game *game)
{
	const float		check_step_size = 0.15f;
	t_2d_point		cur_guess;
	float			cur_dilation;

	cur_dilation = -0.5f;
	while (cur_dilation < +0.5f)
	{
		cur_guess = ft_vec_sum(
			game->player.pos,
			ft_vec_normalize(
				ft_vec_sum(
					game->player.dir,
					ft_vec_prod(game->player.camera_plane, cur_dilation)
				)
			)
		);
		if (door_opened(cur_guess, game))
			return ;
		cur_dilation += check_step_size;
	}
}

static t_bool	door_opened(t_2d_point forward_pos, t_game *game)
{
	const t_int_2d_point	forward_tile = as_int_2dpt(&forward_pos);
	t_list					*door_node;
	t_door					*door;

	if (is_door_map_char(game->map_handle.map[forward_tile.y][forward_tile.x]))
	{
		door_node = ft_lstfind(game->doors, door_pos, &forward_tile);
		if (door_node)
		{
			door = (t_door *)door_node->content;
			if (door)
			{
				if (e_DOOR_CLOSED == door->status
					|| e_DOOR_OPEN == door->status)
				{
					door->prev_status = door->status;
					door->status = e_DOOR_AJAR;
					return (e_true);
				}
			}
		}
	}
	return (e_false);
}
