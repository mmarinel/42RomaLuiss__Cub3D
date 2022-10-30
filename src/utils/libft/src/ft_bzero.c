/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 17:27:37 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/30 12:17:49 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char		*str;
	size_t		i;

	if (NULL == s)
		return ;
	else
	{
		str = s;
		i = 0;
		while (i < n)
			str[i++] = '\0';
	}
}
