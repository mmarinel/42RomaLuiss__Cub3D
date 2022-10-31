/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 15:48:36 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/31 15:51:06 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_string_new( char c, long size )
{
	char	*ret;

	if (size <= 0)
		return (NULL);
	ret = (char *) malloc((size + 1) * sizeof(char));
	ft_memset(ret, c, size - 1);
	ret[size] = '\0';
	return (ret);
}
