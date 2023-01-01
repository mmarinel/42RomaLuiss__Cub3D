/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:19:15 by earendil          #+#    #+#             */
/*   Updated: 2023/01/01 19:58:15 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "in_game_loops_bonus.h"

static void	change_enemy_pos(t_enemy *enemy, t_game *game);
// static void	enemy_move_across_door(
// 	t_enemy *enemy, 
// 	const t_2d_point *door_position, const t_2d_point *enemy_dir,
// 	t_game *game
// 	);
//*		end of static declarations

void	move_enemies(t_game *game)
{
	t_list	*cur;

	cur = game->enemies;
	while (cur)
	{
		if (((t_enemy *)cur->content)->health
			&& e_false == enemy_colliding(cur->content, &game->player.pos)
		)
			change_enemy_pos(cur->content, game);
		cur = cur->next;
	}
}

void	enemies_anim_death(t_game *game)
{
	t_list	*cur;

	cur = game->enemies;
	while (cur)
	{
		if (0 == ((t_enemy *)cur->content)->health)
		{
			((t_enemy *)cur->content)->die_anim_frames -= 1;
			if (0 == ((t_enemy *)cur->content)->die_anim_frames)
				((t_enemy *)cur->content)->alive = e_false;
		}
		cur = cur->next;
	}
}

void	clean_enemies(t_game *game)
{
	t_list	*next;
	t_list	**prev_next;

	prev_next = &game->enemies;
	while (*prev_next)
	{
		next = (*prev_next)->next;
		if (e_false == ((t_enemy *)(*prev_next)->content)->alive)
		{
			ft_lstdelone(*prev_next, free);
			*prev_next = next;
		}
		else
			prev_next = &(*prev_next)->next;
	}
}

static size_t	ampl(const t_2d_point *dist_v, t_enemy *enemy)
{
	const size_t	dist = ft_vec_norm(*dist_v);
	const size_t	max_apl = 4;
	size_t			cur_ampl;

	cur_ampl = max_apl;
	while (cur_ampl > 1)
	{
		if (dist >= enemy->collision_radius + enemy->step_size * cur_ampl)
			break ;
		cur_ampl /= 2;
	}
	return (cur_ampl);
}

static void	change_enemy_pos(t_enemy *enemy, t_game *game)
{
	const t_2d_point		dist_v
		= ft_vec_sum(
			game->player.pos,
			ft_vec_opposite(enemy->pos)
			);
	const t_2d_point		new_pos
		= map_pos_clip(
			ft_vec_sum(
				enemy->pos,
				ft_change_magnitude(
					dist_v, enemy->step_size * ampl(&dist_v, enemy)
					)
			),
			game
		);
	// const t_int_2d_point	next_tile = as_int_2dpt(&new_pos);

	if (is_traversable_pos(game, &enemy->pos, &new_pos))
	{
		// if (BONUS && is_door_map_char(
		// 	game->map_handle.map[next_tile.y][next_tile.x]
		// ))
		// 	enemy_move_across_door(enemy, &new_pos, &dir, game);
		// else
			enemy->pos = new_pos;
	}
}

// static void	enemy_move_across_door(
// 	t_enemy *enemy, 
// 	const t_2d_point *door_position, const t_2d_point *enemy_dir,
// 	t_game *game
// 	)
// {
// 	const t_2d_point	new_pos
// 		= ft_vec_sum(*door_position, ft_vec_normalize(*enemy_dir));

// 	if (is_free_pos_for_en(game, new_pos, enemy))
// 		enemy->pos = new_pos;
// }
