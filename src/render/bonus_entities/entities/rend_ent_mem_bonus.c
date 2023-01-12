/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend_ent_mem_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:05:02 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 15:46:21 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rend_bonus.h"

static void	update_enemy_list(
				t_list **list,
				const t_raycast_return *rc_ret,
				size_t screen_col
				);
static void	update_item_list(
				t_list **list,
				const t_raycast_return *rc_ret,
				size_t screen_col
				);
static void	entity_update_cols(
				t_rendered_entity *rend_entity, const size_t screen_col
				);
//*		end of static declarations

t_list	*ft_new_rend_entity_node(
	size_t screen_col,
	t_entity which,
	const t_raycast_return *rc_ret
	)
{
	t_rendered_entity	*data;

	data = (t_rendered_entity *) malloc(sizeof(t_rendered_entity));
	if (NULL == data)
		return (NULL);
	data->which = which;
	if (e_ENT_ENEMY == data->which)
	{
		data->entity = rc_ret->spotted_enemy.enemy;
		data->min_perp_dist = rc_ret->spotted_enemy.perp_dist;
	}
	if (e_ENT_ITEM == data->which)
	{
		data->entity = rc_ret->spotted_item.item;
		data->min_perp_dist = rc_ret->spotted_item.perp_dist;
	}
	data->mid_screen_col = screen_col;
	data->first_screen_col = screen_col;
	data->last_screen_col = screen_col;
	return (ft_lstnew(NULL, data));
}

void	update_entity_list(
	t_list **list,
	const t_raycast_return *rc_ret,
	size_t screen_col
	)
{
	update_enemy_list(list, rc_ret, screen_col);
	update_item_list(list, rc_ret, screen_col);
}

static void	update_enemy_list(
	t_list **list,
	const t_raycast_return *rc_ret,
	size_t screen_col
	)
{
	t_list				*cur;
	t_rendered_entity	*rend_entity;

	if (NULL == rc_ret->spotted_enemy.enemy || NULL == list)
		return ;
	cur = ft_lstfind(*list, rend_enemy_spotted, rc_ret->spotted_enemy.enemy);
	if (NULL == cur)
		ft_lstadd_in_order(
			list, ft_new_rend_entity_node(screen_col, e_ENT_ENEMY, rc_ret),
			rendent_greater_than
			);
	else
	{
		rend_entity = ((t_rendered_entity *)cur->content);
		if (rc_ret->spotted_enemy.perp_dist < rend_entity->min_perp_dist)
		{
			rend_entity->min_perp_dist = rc_ret->spotted_enemy.perp_dist;
		}
		entity_update_cols(rend_entity, screen_col);
	}
}

static void	update_item_list(
	t_list **list,
	const t_raycast_return *rc_ret,
	size_t screen_col
	)
{
	t_list				*cur;
	t_rendered_entity	*rend_entity;

	if (NULL == rc_ret->spotted_item.item || NULL == list)
		return ;
	cur = ft_lstfind(*list, rend_item_spotted, rc_ret->spotted_item.item);
	if (NULL == cur)
		ft_lstadd_in_order(
			list, ft_new_rend_entity_node(screen_col, e_ENT_ITEM, rc_ret),
			rendent_greater_than
			);
	else
	{
		rend_entity = ((t_rendered_entity *)cur->content);
		if (rc_ret->spotted_item.perp_dist < rend_entity->min_perp_dist)
		{
			rend_entity->min_perp_dist = rc_ret->spotted_item.perp_dist;
		}
		entity_update_cols(rend_entity, screen_col);
	}
}

static void	entity_update_cols(
	t_rendered_entity *rend_entity, const size_t screen_col
	)
{
	rend_entity->last_screen_col = screen_col;
	rend_entity->mid_screen_col = (
			(rend_entity->first_screen_col + rend_entity->last_screen_col)
			/ 2.0f
			);
}
