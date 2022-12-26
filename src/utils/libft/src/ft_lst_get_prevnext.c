/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_prevnext.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 01:00:17 by earendil          #+#    #+#             */
/*   Updated: 2022/12/26 15:43:49 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**ft_lst_get_prevnext(t_list **head,
	t_bool(*criteria)(const void *, const void *),
	const void *info
	)
{
	t_list	**prev_next;

	if (NULL == head || NULL == *head)
		return (NULL);
	prev_next = head;
	while (*prev_next)
	{
		if (criteria((*prev_next)->content, info))
			break ;
		prev_next = &(*prev_next)->next;
	}
	return (prev_next);
}
