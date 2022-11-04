/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 10:47:02 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/04 11:20:26 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	ft_isdigit_string( const char *string )
{
	size_t	cursor;

	if (NULL == string)
		return (e_false);
	if (e_true == ft_str_isempty(string))
		return (e_false);
	cursor = 0;
	while (string[cursor])
	{
		if (e_false == ft_isdigit(string[cursor])
			&& e_false == ft_isspace(string[cursor])
		)
			return (e_false);
		cursor++;
	}
	return (e_true);
}
