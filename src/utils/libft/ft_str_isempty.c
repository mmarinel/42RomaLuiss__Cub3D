/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isempty.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:34:51 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/30 14:43:04 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_str_isempty( const char* str )
{
	size_t	cursor;

	if (NULL == str)
		return (e_true);
	else
	{
		cursor = 0;
		while (str[cursor])
		{
			if (e_false == ft_isspace(str[cursor]))
				return (e_false);
			cursor += 1;
		}
		return (e_true);
	}
}
