/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:01:30 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/29 16:12:18 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

# include <stdio.h>

void	ft_splitprint( char** split )
{
	size_t	i;

	if (NULL == split)
		return ;
	i = 0;
	while (split[i])
	{
		if (0 == ft_strcmp(split[i]," "))
			printf("split[%zu]: <space>\n", i);
		else if (0 == ft_strcmp(split[i], "\t"))
			printf("split[%zu]: <tab>\n", i);
		else
			printf("split[%zu]: %s\n", i, split[i]);
		i++;
	}
}
