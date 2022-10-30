/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 08:37:22 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/27 08:38:05 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_splitlen(char **split)
{
	size_t	i;

	if (split == NULL)
		return (0);
	else
	{
		i = 0;
		while (split[i])
			i++;
		return (i);
	}
}
