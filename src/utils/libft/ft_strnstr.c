/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:17:07 by mmarinel          #+#    #+#             */
/*   Updated: 2022/01/20 10:04:49 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;
	size_t		k;
	size_t		needle_len;

	i = 0;
	needle_len = ft_strlen(needle);
	if (*needle == '\0' || !ft_strncmp(haystack, needle, needle_len))
		return ((char *) haystack);
	while (haystack[i] != '\0' && i < len && needle_len <= len - i)
	{
		j = 0;
		k = i;
		while (needle[j] != '\0' && haystack[i] != '\0'
			&& haystack[i] == needle[j])
			i = k + ++j;
		if (needle[j] == '\0')
			return ((char *)(haystack + k));
		else if (haystack[i] == '\0')
			return (0);
		else
			i = k + 1;
	}
	return ((char *) 0);
}
