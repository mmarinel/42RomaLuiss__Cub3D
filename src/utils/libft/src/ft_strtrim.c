/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:13:16 by mmarinel          #+#    #+#             */
/*   Updated: 2022/01/20 10:05:48 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	long long	start;
	long long	end;
	size_t		trim_size;
	char		*trimmed;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1) - 1;
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	while (end > 0 && ft_strchr(set, s1[end]))
		end--;
	if (start > end)
		trim_size = 0;
	else
		trim_size = (end - start + 1);
	trimmed = (char *) malloc((trim_size + 1) * sizeof(char));
	if (!trimmed)
		return (NULL);
	trimmed = (char *) ft_memcpy(trimmed, s1 + start, trim_size);
	trimmed[trim_size] = '\0';
	return (trimmed);
}
