/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 08:30:00 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/27 09:11:55 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

void	*ft_splitclear(char **split)
{
	size_t	i;
	char	**backup;

	if ( NULL == split )
		return (NULL);
	else
	{
		backup = split;
		i = 0;
		while (split[i])
		{
			ft_free(split[i]);
			i++;
		}
		ft_free(backup);
	}
	return (NULL);
}
