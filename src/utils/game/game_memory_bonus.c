/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_memory_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:15:44 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/05 20:00:46 by earendil         ###   ########.fr       */
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

t_list	*ft_new_enemy_node(const t_2d_point *pos)
{
	const size_t	die_anim_frames = ENEMY_DIE_ANIM_FRAMES;
	const float		alignment = 0.5f;//*	was 0.1f
	t_enemy			*enemy;

	enemy = (t_enemy *) malloc(sizeof(t_enemy));
	if (NULL == enemy)
		return (NULL);
	enemy->alive = e_true;
	enemy->health = 100;
	enemy->collision_radius = ENEMIES_DEFAULT_COLLISION_RADIUS;
	enemy->step_size = 0.25f;
	enemy->pos = (t_2d_point){pos->x + alignment, pos->y + alignment};
	enemy->die_anim_frames = die_anim_frames;
	return (ft_lstnew(NULL, enemy));
}

t_list	*ft_new_item_node(const t_2d_point *pos)
{
	const float		alignment = 0.5f;//*	was 0.1f
	t_item			*item;

	item = (t_item *) malloc(sizeof(t_item));
	if (NULL == item)
		return (NULL);
	item->picked = e_false;
	item->pos = (t_2d_point){pos->x + alignment, pos->y + alignment};
	item->cur_shift = 0;
	item->cur_increment = 0;
	item->anim_dir = (+1);
	item->bouncing_clock = 0;
	return (ft_lstnew(NULL, item));
}

t_enemy	*ft_clone_enemy(const t_enemy *enemy)
{
	t_enemy	*clone;

	clone = (t_enemy *) malloc(sizeof(t_enemy));
	if (NULL == clone)
		return (clone);
	clone->alive = enemy->alive;
	clone->health = enemy->health;
	clone->collision_radius = enemy->collision_radius;
	clone->pos = enemy->pos;
	clone->die_anim_frames = enemy->die_anim_frames;
	return (clone);
}

t_list	*ft_new_ray_node(const t_raycast_return *rc_ret)
{
	t_raycast_return	*clone;

	clone = (t_raycast_return *) malloc(sizeof(t_raycast_return));
	if (NULL == rc_ret)
		return (NULL);
	clone->doors = rc_ret->doors;
	clone->spotted_enemy = rc_ret->spotted_enemy;
	clone->spotted_item = rc_ret->spotted_item;
	clone->final_tile = rc_ret->final_tile;
	return (ft_lstnew(NULL, clone));
}
