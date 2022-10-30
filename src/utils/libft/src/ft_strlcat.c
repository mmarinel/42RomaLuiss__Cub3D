/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 11:31:47 by mmarinel          #+#    #+#             */
/*   Updated: 2022/01/20 10:03:26 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_secure(const char *str, size_t bufsize);

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t			len_dest;
	size_t			len_src;
	unsigned long	i;
	unsigned long	size;

	i = 0;
	len_dest = ft_strlen_secure(dest, dstsize);
	len_src = ft_strlen(src);
	size = dstsize - len_dest;
	if (size)
		size -= 1;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size)
		{
			dest[len_dest + i] = src[i];
			i++;
		}
		dest[len_dest + i] = '\0';
	}
	return (len_dest + len_src);
}

size_t	ft_strlen_secure(const char *str, size_t bufsize)
{
	size_t	i;

	i = 0;
	while (i < bufsize && str[i] != '\0')
		i++;
	return (i);
}
