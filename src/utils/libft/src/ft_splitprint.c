/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 16:01:30 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/04 11:43:07 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_splitprint( char **split )
{
	size_t	i;

	if (NULL == split)
		return ;
	i = 0;
	while (split[i])
	{
		if (0 == ft_strcmp(split[i], " "))
			ft_printf("split[%zu]: <space>\n", i);
		else if (0 == ft_strcmp(split[i], "\t"))
			ft_printf("split[%zu]: <tab>\n", i);
		else
			ft_printf("split[%zu]: %s\n", i, split[i]);
		i++;
	}
}
