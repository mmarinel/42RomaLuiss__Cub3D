/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 08:30:00 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/04 09:18:21 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

void	*ft_splitclear(char ***split_ref)
{
	size_t	i;
	char	**_split;
	char	**_backup;

	if ( NULL == split_ref || NULL == *split_ref )
		return (NULL);
	else
	{
		_split = *split_ref;
		_backup = _split;
		i = 0;
		while (_split[i])
		{
			free(_split[i]);
			i++;
		}
		free(_backup);
		*split_ref = NULL;
	}
	return (NULL);
}
