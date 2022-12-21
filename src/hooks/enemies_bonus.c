/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:19:15 by earendil          #+#    #+#             */
/*   Updated: 2022/12/21 18:22:24 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

static void	change_enemy_pos(t_enemy *enemy, t_game *game);
//*		end of static declarations

void	move_enemies(t_game *game)
{
	t_list	*cur;

	cur = game->enemies;
	while (cur)
	{
		if (((t_enemy *)cur->content)->health
			&& e_false == enemy_collision(cur->content, &game->player.pos)
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

void	attack_enemies(t_game *game)
{
	const size_t	radius = 4;
	size_t			i;
	t_2d_point		pos;
	t_int_2d_point	square;
	t_list			*enemy_node;

	i = 0;
	while (i < radius)
	{
		pos = ft_vec_sum(
			game->player.pos,
			ft_vec_prod(game->player.dir, i)
		);
		square = (t_int_2d_point){pos.x, pos.y};
		enemy_node = ft_lstfind(game->enemies, enemy_pos, &square);
		if (enemy_node && ((t_enemy *)enemy_node->content)->health)
			((t_enemy *)enemy_node->content)->health -= 10;
		i++;
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

static void	change_enemy_pos(t_enemy *enemy, t_game *game)
{
	const t_2d_point	dir = ft_change_magnitude(
		ft_vec_sum(
			game->player.pos,
			ft_vec_opposite(enemy->pos)
			),
			0.25f
	);
	const t_2d_point	new_pos = map_pos_clip(
		ft_vec_sum(
			enemy->pos,
			dir
		),
		game
	);

	if (is_free_pos_for_en(game, new_pos, enemy))
		enemy->pos = new_pos;
}
