/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:36:28 by earendil          #+#    #+#             */
/*   Updated: 2022/12/24 03:40:18 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rend_bonus.h"

static void	render_enemy(
	t_rendered_enemy *enemy_data,
	t_game *g
	);
static void	enemy_render_col(
	const size_t screen_col,
	const size_t resized_texture_col,
	const t_rendered_enemy *enemy_data,
	t_game *g
	);
//*		end of static declarations

void	render_enemies(
	t_list *enemies,
	t_game *g
	)
{
	t_list				*cur;
	t_rendered_enemy	*spotted_enemy;

	cur = enemies;
	while (cur)
	{
		spotted_enemy = (t_rendered_enemy *)cur->content;
		if (is_traversable_pos(g, &spotted_enemy->enemy->pos, &g->player.pos))
			render_enemy(spotted_enemy, g);
		cur = cur->next;
	}
}

static void	render_enemy(
	t_rendered_enemy *enemy_data,
	t_game *g
	)
{
	const size_t	enemy_size = roundf(
		g->screen_handle.height / enemy_data->min_perp_dist
	);
	size_t			i;
	int				screen_col;

	if (
		0 == enemy_size
		|| e_false == enemy_data->enemy->alive
		|| (
			0 == enemy_data->enemy->health
			&& 0 == enemy_data->enemy->die_anim_frames % 2
			)
		)
		return ;
	enemy_data->enemy_size = enemy_size;
	screen_col = enemy_data->mid_screen_col;
	i = 0;
	while (i < enemy_size)
	{
		if (screen_col >= 0 && screen_col <= (int)g->screen_handle.width)
			enemy_render_col(screen_col, i, enemy_data, g);
		screen_col += 1;
		i += 1;
	}
}

static void	enemy_render_col(
	const size_t screen_col,
	const size_t resized_texture_col,
	const t_rendered_enemy *enemy_data,
	t_game *g
	)
{
	const t_column_info		col_info = get_enemy_column_info(
		resized_texture_col,
		enemy_data->enemy_size,
		enemy_data,
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
