/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitinit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 08:58:13 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/04 11:26:11 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_splitinit( size_t size )
{
	char	**split;
	size_t	i;

	split = (char **) malloc(sizeof(char *) * (size + 1));
	if (NULL == split)
		return (NULL);
	else
	{
		i = 0;
		while (i < size)
		{
			split[i] = NULL;
			i++;
		}
		split[size] = NULL;
		return (split);
	}
}
