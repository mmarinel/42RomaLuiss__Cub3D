/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:48:36 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/02 12:48:30 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_string_new( char c, long len )
{
	char	*ret;

	if (len <= 0)
		return (NULL);
	ret = (char *) malloc((len + 1) * sizeof(char));
	ft_memset(ret, c, len);
	ret[len] = '\0';
	return (ret);
}
