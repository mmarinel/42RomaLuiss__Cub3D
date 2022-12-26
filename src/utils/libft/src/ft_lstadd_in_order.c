/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_in_order.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 00:39:48 by earendil          #+#    #+#             */
/*   Updated: 2022/12/26 15:43:55 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_in_order(t_list **head,
			t_list *const new_el,
			t_bool(*greater_than)(const void *, const void *)
		)
{
	t_list	**prev_next;

	if (NULL == head || NULL == new_el)
		return ;
	else if (NULL == *head)
		ft_lstadd_front(head, new_el);
	else
	{
		prev_next = ft_lst_get_prevnext(head, greater_than, new_el->content);
		new_el->next = *prev_next;
		*prev_next = new_el;
	}
}
