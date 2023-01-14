/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:19:15 by earendil          #+#    #+#             */
/*   Updated: 2023/01/14 11:28:04 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "in_game_loops_bonus.h"

static void		change_enemy_pos(t_enemy *enemy, t_game *game);
static size_t	ampl(const t_2d_point *dist_v, t_enemy *enemy);
//*		end of static declarations

void	move_enemies(t_game *game)
{
	static int	frame = 0;
	const int	anim_clock = 3;
	t_list	*cur;

	frame = (frame + 1) % anim_clock;
	if (0 == frame)
	{
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
}

void	enemies_anim_death(t_game *game)
{
	static int	frame = 0;
	const int	anim_clock = 3;
	t_list	*cur;

	frame = (frame + 1) % anim_clock;
	if (0 == frame)
	{
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

/**
 * @brief domain rule: no more than one enemy in the same tile.
 * Enemies start in different tiles; so, when moving, if there is another enemy
 * in the new position, this enemy is a different one if we stepped
 * onto a new tile, or the same one if we remained in the same tile.
 * Enemies move with a step_size < 1, so there is needed more than one step
 * to go onto a next tile.
 * To check if we remained in the same tile, all that is needed is to check
 * if the enemy found is in the same exact position of the current one.
 * 
 * @param enemy 
 * @param game 
 */
static void	change_enemy_pos(t_enemy *enemy, t_game *game)
{
	const t_2d_point		dist_v
		= ft_vec_sum(
			game->player.pos, ft_vec_opposite(enemy->pos)
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
	const t_int_2d_point	next_tile = as_int_2dpt(&new_pos);
	t_enemy					*other;

	other = (t_enemy *) ft_lstfind_cont(game->enemies, enemy_pos, &next_tile);
	if (is_traversable_pos(game, &enemy->pos, &new_pos)
		&& (NULL == other || ft_2d_point_equals(&other->pos, &enemy->pos))
	)
	{
		enemy->pos = new_pos;
	}
}

/**
 * @brief enemies move at different velocities
 * based on how far they are from the player.
 * The farthest they are, the faster they move.
 * 
 * @param dist_v 
 * @param enemy 
 * @return size_t 
 */
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
