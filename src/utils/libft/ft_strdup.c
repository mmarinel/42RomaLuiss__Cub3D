/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 10:57:58 by mmarinel          #+#    #+#             */
/*   Updated: 2022/01/20 10:02:31 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*scopy;
	size_t	len;

	len = ft_strlen(s1);
	scopy = (char *) malloc((len + 1) * sizeof(char));
	if (scopy == NULL)
		return (NULL);
	return (ft_memcpy(scopy, s1, len + 1));
}
