/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_items_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:17:41 by earendil          #+#    #+#             */
/*   Updated: 2022/12/24 20:17:31 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

t_item	*get_item(const t_int_2d_point *pos, t_game *game)
{
	t_list	*item_node;

	item_node = ft_lstfind(game->items, item_pos, pos);
	if (NULL == item_node)
		return (NULL);
	else
		return (item_node->content);
}
