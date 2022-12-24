/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend_item_mem_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:32:53 by earendil          #+#    #+#             */
/*   Updated: 2022/12/24 20:45:06 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rend_bonus.h"

static t_bool	item_spotted(const void *list, const void *item);
//*		end of static declarations

t_list	*ft_new_rend_item_node(
	size_t screen_col,
	const t_raycast_return *rc_ret
	)
{
	t_rendered_item	*data;

	data = (t_rendered_item *) malloc(sizeof(t_rendered_item));
	if (NULL == data)
		return (NULL);
	data->item = rc_ret->spotted_item.item;
	data->min_perp_dist = rc_ret->spotted_item.perp_dist;
	data->mid_screen_col = screen_col;
	data->first_screen_col = screen_col;
	data->last_screen_col = screen_col;
	return (ft_lstnew(NULL, data));
}

void	update_item_list(
	t_list **list,
	const t_raycast_return *rc_ret,
	size_t screen_col
	)
{
	t_list	*cur;

	if (NULL == rc_ret->spotted_item.item || NULL == list)
		return ;
	cur = ft_lstfind(*list, item_spotted, rc_ret->spotted_item.item);
	if (NULL == cur)
		ft_lstadd_back(list, ft_new_rend_item_node(screen_col, rc_ret));
	else if (
		((t_rendered_item *)cur->content)\
			->min_perp_dist > rc_ret->spotted_item.perp_dist
	)
	{
		((t_rendered_item *)cur->content)->min_perp_dist
			= rc_ret->spotted_item.perp_dist;
		((t_rendered_item *)cur->content)->last_screen_col
			= screen_col;
		((t_rendered_item *)cur->content)->mid_screen_col
			= (
				((t_rendered_item *)cur->content)->first_screen_col
				+ ((t_rendered_item *)cur->content)->last_screen_col
			)
			/ 2.0f;
	}
}

static t_bool	item_spotted(const void *cur, const void *item)
{
	const t_rendered_item	*__cur = (const t_rendered_item *)cur;
	const t_item			*__item = (const t_item *)item;

	return (
		item_equals(__cur->item, __item)
	);
}
