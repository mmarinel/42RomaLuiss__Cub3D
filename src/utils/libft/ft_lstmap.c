/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:17:59 by mmarinel          #+#    #+#             */
/*   Updated: 2022/01/20 09:03:45 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lstmap_rec(t_list *lst, t_list **new_list, void *(*f)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;

	if (!f || !lst || !ft_lstmap_rec(lst, &new_list, f))
		return (NULL);
	if (del)
		;
	return (new_list);
}

static int	ft_lstmap_rec(t_list *lst, t_list **new_lst, void *(*f)(void *))
{
	if (!lst)
	{
		if (new_lst)
			*new_lst = NULL;
	}
	else
	{
		*new_lst = (t_list *) malloc(sizeof(t_list));
		if (!(*new_lst)
			||!ft_lstmap_rec(lst->next, &((*new_lst)->next), f))
			return (0);
		(*new_lst)->content = f(lst->content);
	}
	return (1);
}
