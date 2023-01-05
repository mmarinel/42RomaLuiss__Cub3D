/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:01:43 by earendil          #+#    #+#             */
/*   Updated: 2023/01/05 19:59:54 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

t_column_info	get_wall_column_info(
	size_t rendered_size,
	float gap,
	const t_raycast_return *rc_ret,
	t_game *g
	)
{
	float	scaling_factor;

	{
		if (0 == rendered_size)
			scaling_factor = INFINITY;
		else
			scaling_factor = (float)get_textures_size() / rendered_size;
	}
	return ((t_column_info){
		rendered_size,
		gap,
		NULL,//TODO			RIMUOVERE in t_column_info		!!!!!!!!!!!!!!!!!!!!!!!
		get_wall_texture(g, &rc_ret->final_tile),
		&g->\
		screen_handle.frame_data,
		get_texture_column(&rc_ret->final_tile),
		scaling_factor,
		e_true
		}
	);
}

t_data *get_wall_texture(t_game *game, const t_rc_ret_data *rc_ret_data)
{
	if (e_VERTICAL == rc_ret_data->side)
	{
		if (e_RAY_EAST == rc_ret_data->view_side_direction)
			return (&game->textures.wall.east);
		else
			return (&game->textures.wall.west);
	}
	else if (e_HORIZONTAL == rc_ret_data->side)
	{
		if (e_RAY_NORTH == rc_ret_data->view_forw_direction)
			return (&game->textures.wall.north);
		else
			return (&game->textures.wall.south);
	}
	else
		return (NULL);
}
