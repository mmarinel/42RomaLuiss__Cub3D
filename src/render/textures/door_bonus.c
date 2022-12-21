/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:14:02 by earendil          #+#    #+#             */
/*   Updated: 2022/12/22 00:15:06 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

static t_data	*get_door_texture(const t_spotted_door *door_data, t_game *g);
//*		end of static declarations

t_column_info	get_door_column_info(
	size_t rendered_size,
	float gap,
	const t_spotted_door *door_data,
	t_game *g
	)
{
	const t_data	*door_texture = get_door_texture(door_data, g);
	t_bool			draw_shadow;
	float			scaling_factor;

	if (door_texture == &g->textures.door.closed)
		draw_shadow = e_true;
	else
		draw_shadow = e_false;
	if (0 == rendered_size)
		scaling_factor = INFINITY;
	else
		scaling_factor = (float)get_textures_size() / rendered_size;
	return ((t_column_info){
		rendered_size,
		gap,
		NULL,//TODO			RIMUOVERE in t_column_info		!!!!!!!!!!!!!!!!!!!!!!!
		door_texture,
		&g->\
		screen_handle.frame_data,
		get_texture_column(&door_data->rc_data),
		scaling_factor,
		draw_shadow
		}
	);
}

static t_data	*get_door_texture(const t_spotted_door *door_data, t_game *g)
{
	if (door_front_side(door_data->door_ref->type, door_data->rc_data.side))
	{
		if (e_DOOR_CLOSED == door_data->door_ref->status)
			return (&g->textures.door.closed);
		if (e_DOOR_AJAR == door_data->door_ref->status)
			return (&g->textures.door.ajar);
		if (e_DOOR_OPEN == door_data->door_ref->status)
			return (&g->textures.door.open);
		return (NULL);
	}
	else
		return (get_wall_texture(g, &door_data->rc_data));
}
