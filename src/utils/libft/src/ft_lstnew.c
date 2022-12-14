/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:14:45 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/13 19:30:00 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *(*clone)(void *), void *content)
{
	t_list	*el;

	el = (t_list *) malloc(sizeof(t_list));
	if (!el)
		return (NULL);
	if (clone)
		el->content = clone(content);
	else
		el->content = content;
	el->next = NULL;
	return (el);
}
