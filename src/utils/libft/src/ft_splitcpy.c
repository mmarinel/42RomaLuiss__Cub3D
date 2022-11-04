/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 08:43:39 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/04 08:42:42 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_splitcpy(char **split_buf, char **split_src, size_t copy_len)
{
	size_t	i;

	if (NULL == split_buf)
		split_buf = ft_splitinit(copy_len);
	i = 0;
	while (i < copy_len)
	{
		split_buf[i] = ft_strcpy(
						split_buf[i],
						split_src[i],
						ft_strlen(split_src[i])
					);
		// split_buf[i][ft_strlen(split_src[i])] = '\0';
		i++;
	}
	return (split_buf);
}
