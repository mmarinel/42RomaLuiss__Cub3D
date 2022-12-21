/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:06:16 by earendil          #+#    #+#             */
/*   Updated: 2022/12/22 00:11:38 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

static t_data	*get_enemy_texture(const t_enemy *enemy, t_game *g);
//*		end of static declarations

t_column_info	get_enemy_column_info(
	size_t resized_texture_col,
	size_t enemy_size,
	const t_rendered_enemy *enemy_data,
	t_game *g
	)
{
	const float	gap = ( 
		((float)g->screen_handle.height - enemy_size) / 2.0f
	);
	float		scaling_factor;

	{
		if (0 == enemy_size)
			scaling_factor = INFINITY;
		else
			scaling_factor = (float)get_textures_size() / enemy_size;
	}
	return ((t_column_info){
		enemy_size,
		gap,
		NULL,
		get_enemy_texture(enemy_data->enemy, g),
		&g->\
		screen_handle.frame_data,
		resized_texture_col * scaling_factor,
		scaling_factor,
		e_false
		}
	);
}

static t_data	*get_enemy_texture(const t_enemy *enemy, t_game *g)
{
	if (enemy->health)
		return (&g->textures.enemy[0]);
	else
		return (&g->textures.enemy[1]);
}
