/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 08:46:13 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/28 10:47:18 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *buf, char *src, size_t copy_len)
{
	size_t	i;

	if (NULL == buf)
	{
		buf = (char *) malloc((copy_len + 1) * sizeof(char));
		buf[copy_len] = '\0';
	}
	i = 0;
	while (i < copy_len)
	{
		buf[i] = src[i];
		i++;
	}
	return (buf);
}
