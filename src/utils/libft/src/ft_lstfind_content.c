/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_content.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 17:13:18 by earendil          #+#    #+#             */
/*   Updated: 2023/01/04 17:14:24 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_lstfind_cont(t_list *head,
			t_bool(*test)(const void *, const void *),
			const void *to_find
		)
{
	t_list	*node;

	node = ft_lstfind(head, test, to_find);
	if (node)
		return (node->content);
	else
		return (NULL);
}
