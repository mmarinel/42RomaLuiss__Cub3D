/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_member.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:45:43 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/30 11:48:26 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

size_t	ft_str_member( const char* str, char c )
{
	size_t	occurrences;
	size_t	cursor;

	if (NULL == str)
		return (0);
	else
	{
		occurrences = 0;
		cursor = 0;
		while ( str[cursor] )
		{
			if ( c == str[cursor] )
				occurrences += 1;
			cursor++;
		}
		return (occurrences);
	}
}
