/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:06:16 by earendil          #+#    #+#             */
/*   Updated: 2022/12/26 16:10:21 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

static void		set_scaling_factor(
	float *scaling_factor, const size_t enemy_size
	);
static t_data	*get_enemy_texture(const t_enemy *enemy, t_game *g);
//*		end of static declarations

t_column_info	get_enemy_column_info(
	size_t resized_texture_col,
	size_t enemy_size,
	t_enemy *enemy,
	t_game *g
	)
{
	const float	gap = ( 
		((float)g->screen_handle.height - enemy_size) / 2.0f
	);
	float		scaling_factor;

	set_scaling_factor(&scaling_factor, enemy_size);
	return ((t_column_info){
		enemy_size,
		gap,
		NULL,
		get_enemy_texture(enemy, g),
		&g->\
		screen_handle.frame_data,
		resized_texture_col * scaling_factor,
		scaling_factor,
		e_false
		}
	);
}

static void	set_scaling_factor(float *scaling_factor, const size_t enemy_size)
{
	if (0 == enemy_size)
		*scaling_factor = INFINITY;
	else
		*scaling_factor = (float)get_textures_size() / enemy_size;
}

static t_data	*get_enemy_texture(const t_enemy *enemy, t_game *g)
{
	if (enemy->health)
		return (&g->textures.enemy[0]);
	else
		return (&g->textures.enemy[1]);
}
