/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:22:37 by mmarinel          #+#    #+#             */
/*   Updated: 2022/01/20 10:03:04 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*s_join;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s_join = (char *) malloc((s1_len + s2_len + 1) * sizeof(char));
	if (s_join == NULL)
		return (NULL);
	return ((char *) ft_memcpy(
			ft_memcpy(s_join, s1, s1_len) + s1_len,
			s2,
			s2_len + 1) - s1_len);
}
