/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:41:11 by earendil          #+#    #+#             */
/*   Updated: 2022/12/25 17:42:35 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

void	clean_items(t_game *game)
{
	t_list	*next;
	t_list	**prev_next;

	prev_next = &game->items;
	while (*prev_next)
	{
		next = (*prev_next)->next;
		if (e_true == ((t_item *)(*prev_next)->content)->picked)
		{
			ft_lstdelone(*prev_next, free);
			*prev_next = next;
		}
		else
			prev_next = &(*prev_next)->next;
	}
}
