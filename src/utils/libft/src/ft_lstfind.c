/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 18:24:11 by earendil          #+#    #+#             */
/*   Updated: 2022/12/13 19:44:47 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *head,
			t_bool(*test)(const void *, const void *),
			const void *to_find
		)
{
	t_list	*cur;

	if (NULL == head)
		return (NULL);
	cur = head;
	while (
		cur && e_false == test(cur->content, to_find)
	)
		cur = cur->next;
	return (cur);
}
