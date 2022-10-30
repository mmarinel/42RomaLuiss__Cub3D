/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 11:50:13 by mmarinel          #+#    #+#             */
/*   Updated: 2022/01/20 10:06:22 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len - 1)
	{
		substr = (char *) malloc(sizeof(char));
		*substr = '\0';
		return (substr);
	}
	if (len > s_len - start)
		len = s_len - start;
	substr = (char *) malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	substr[len] = '\0';
	return ((char *) ft_memcpy(substr, s + start, len));
}
