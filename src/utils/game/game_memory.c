/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:15:44 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/20 21:25:23 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

t_list	*ft_new_door_node(t_int_2d_point pos, t_tile type)
{
	const size_t	opening_delay_frames = DOOR_OPENING_DELAY_FRAMES;
	t_door			*door;

	door = (t_door *) malloc(sizeof(t_door));
	if (NULL == door)
		return (NULL);
	door->status = e_DOOR_CLOSED;
	door->type = type;
	door->pos = pos;
	door->opening_delay_frames = opening_delay_frames;
	return (ft_lstnew(NULL, door));
}

t_list	*ft_new_enemy_node(t_2d_point pos)
{
	const size_t	die_anim_frames = ENEMY_DIE_ANIM_FRAMES;
	t_enemy			*enemy;

	enemy = (t_enemy *) malloc(sizeof(t_enemy));
	if (NULL == enemy)
		return (NULL);
	enemy->alive = e_true;
	enemy->health = 100;
	enemy->pos = pos;
	enemy->die_anim_frames = die_anim_frames;
	return (ft_lstnew(NULL, enemy));
}

t_enemy	*ft_clone_enemy(const t_enemy *enemy)
{
	t_enemy	*clone;

	clone = (t_enemy *) malloc(sizeof(t_enemy));
	if (NULL == clone)
		return (clone);
	clone->alive = enemy->alive;
	clone->pos = enemy->pos;
	clone->die_anim_frames = enemy->die_anim_frames;
	return (clone);
}
