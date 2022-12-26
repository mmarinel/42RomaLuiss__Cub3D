/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:36:28 by earendil          #+#    #+#             */
/*   Updated: 2022/12/26 16:13:24 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rend_bonus.h"

static t_bool	renderable(
	t_rendered_entity *enemy_data, const size_t enemy_size
	);
static void	enemy_render_col(
	const size_t screen_col,
	const size_t resized_texture_col,
	const t_rendered_entity *enemy_data,
	t_game *g
	);
//*		end of static declarations

void	render_enemy(
	t_rendered_entity *enemy_data,
	t_game *g
	)
{
	const size_t	enemy_size = roundf(
		g->screen_handle.height / enemy_data->min_perp_dist
	);
	size_t			i;
	int				screen_col;

	if (e_false == renderable(enemy_data, enemy_size))
		return ;
	enemy_data->entity_size = enemy_size;
	screen_col = enemy_data->mid_screen_col - (float)enemy_size / 2;
	i = 0;
	while (i < enemy_size)
	{
		if (screen_col >= 0 && screen_col < (int)g->screen_handle.width)
			enemy_render_col(screen_col, i, enemy_data, g);
		screen_col += 1;
		i += 1;
	}
}

static t_bool	renderable(
	t_rendered_entity *enemy_data, const size_t enemy_size
	)
{
	t_enemy	*enemy;

	if (e_ENT_ENEMY != enemy_data->which)
		return (e_false);
	else
	{
		enemy = (t_enemy *)enemy_data->entity;
		return (
			enemy->alive
			&& (enemy->health > 0 || 0 != enemy->die_anim_frames % 2)
			&& enemy_size > 0
			&& enemy_size / 2.0f <= (
				enemy_data->last_screen_col - enemy_data->first_screen_col
			)
		);
	}
}

static void	enemy_render_col(
	const size_t screen_col,
	const size_t resized_texture_col,
	const t_rendered_entity *enemy_data,
	t_game *g
	)
{
	const t_column_info		col_info = get_enemy_column_info(
		resized_texture_col,
		enemy_data->entity_size,
		enemy_data->entity,
		g
	);
	t_int_2d_point	endpoint[2];
	
	endpoint[0] = (t_int_2d_point){
		screen_col,
		col_info.gap
		};
	endpoint[1] = (t_int_2d_point){
		screen_col,
		col_info.gap + (col_info.rendered_height - 1)
		};
	bresenham_plot(
		endpoint,
		&g->screen_handle.frame_data,
		nearest_neighbour, &(t_nxt_px_f_arg){&col_info, NULL}
	);
}
