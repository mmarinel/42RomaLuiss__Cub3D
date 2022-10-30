/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 10:00:31 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/30 11:44:14 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*last_occ;

	if (NULL == s)
		return ((char *)0);
	last_occ = (char *) 0;
	while (*s != '\0')
	{
		if (*s == (char) c)
			last_occ = (char *) s;
		s++;
	}
	if (((char) c) == '\0')
		return ((char *) s);
	return (last_occ);
}
