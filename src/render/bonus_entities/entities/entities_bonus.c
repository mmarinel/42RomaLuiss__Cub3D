/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 01:30:39 by earendil          #+#    #+#             */
/*   Updated: 2023/01/05 23:53:26 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rend_bonus.h"

static t_2d_point	*get_ent_pos(t_rendered_entity *ent);
static void			render_entity(t_rendered_entity *ent, t_game *g);
//*		end of static declarations

void	render_entities(t_list *entities, t_game *g)
{
	t_list				*cur;
	t_rendered_entity	*spotted_entity;

	cur = entities;
	while (cur)
	{
		spotted_entity = (t_rendered_entity *)cur->content;
		if (is_traversable_pos(g, get_ent_pos(spotted_entity), &g->player.pos))
			render_entity(spotted_entity, g);
		cur = cur->next;
	}
}

static void	render_entity(t_rendered_entity *ent, t_game *g)
{
	if (e_ENT_ENEMY == ent->which)
		render_enemy(ent, g);
	if (e_ENT_ITEM == ent->which)
		render_item(ent, g);
}

static t_2d_point	*get_ent_pos(t_rendered_entity *ent)
{
	if (e_ENT_ENEMY == ent->which)
		return (
			&((t_enemy *)ent->entity)->pos
		);
	else if (e_ENT_ITEM == ent->which)
		return (
			&((t_item *)ent->entity)->pos
		);
	else
		return (NULL);
}
