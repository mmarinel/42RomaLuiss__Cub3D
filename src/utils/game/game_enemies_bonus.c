/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_enemies_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:17:41 by earendil          #+#    #+#             */
/*   Updated: 2022/12/22 14:46:12 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

static t_bool	trapped_check_pos(
	const t_enemy *enemy,
	const float cur_collision_radius,
	t_game *game
	);
//*		end of static declarations

/**
 * @brief this function returns true iff
 * the given enemy is trapped behind a door or wall.
 * If the player is not in the collision radius of the enemy,
 * the result is undefined.
 * 
 * @param enemy 
 * @param game 
 * @return t_bool 
 */
t_bool	is_enemy_trapped(t_enemy *enemy, t_game *game)
{
	const float	max_collision_radius = enemy->collision_radius;
	const float	collision_step_size = max_collision_radius / 20.0f;
	float		radius;

	if (0 == collision_step_size)
		return (e_false);
	radius = collision_step_size;
	while (radius < max_collision_radius)
	{
		if (trapped_check_pos(enemy, radius, game))
			return (e_true);
		radius += collision_step_size;
	}
	return (e_false);
}

t_enemy	*get_enemy(const t_int_2d_point *pos, t_game *game)
{
	t_list	*enemy_node;

	enemy_node = ft_lstfind(game->enemies, enemy_pos, pos);
	if (NULL == enemy_node)
		return (NULL);
	else
		return (enemy_node->content);
}

/**
 * @brief this function checks for the next position in the frontier
 * made of such vector rotated by -ang_shift, 0, +ang_shift
 * radians respectively
 * 
 * @param enemy 
 * @param cur_collision_radius 
 * @param game 
 * @return t_bool 
 */
static t_bool	trapped_check_pos(
	const t_enemy *enemy,
	const float cur_collision_radius,
	t_game *game
	)
{
	const t_2d_point	towards_player_dir = ft_change_magnitude(
		ft_vec_sum(
			game->player.pos,
			ft_vec_opposite(enemy->pos)
			),
		cur_collision_radius
	);
	const t_2d_point	new_pos = map_pos_clip(
		ft_vec_sum(enemy->pos, towards_player_dir),
		game
	);

	return (e_false == is_free_pos(game, new_pos));
}
