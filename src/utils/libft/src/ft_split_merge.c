/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_merge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 09:32:31 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/31 09:34:29 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief this function is the inverse of ft_split.
 * It takes a split and compresses it to a string by using separator sep.
 * 
 * @param split 
 * @param sep 
 * @param free_split true iff the input has to be freed
 * @return char* 
 */
char	*ft_split_merge(char	**split, char *const sep, t_bool free_split)
{
	char	*merge;
	size_t	i;

	if (NULL == split)
		return (NULL);
	merge = NULL;
	i = 0;
	while (split[i])
	{
		if (!merge)
			merge = ft_strdup(split[i]);
		else
			merge = ft_strjoin(
					ft_strjoin(merge, sep, e_true, e_false),
					split[i],
					e_true, e_false
					);
		i++;
	}
	if (free_split)
		ft_splitclear(split);
	return (merge);
}
