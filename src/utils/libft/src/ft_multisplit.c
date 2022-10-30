/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multisplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 07:59:42 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/30 12:25:27 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_multisplit_rec( char** str_s, char** delimiters);
static char	get_dels_separator( const char* delimiters );
//* end of static declarations

/**
 * @brief this function splits a string on multiple delimiters.
 * 
 * @param str 
 * @param delimiters a string of delimiters separated by a special character.
 * @return char** the splitted string if the delimiter string is well formed,
 * otherwise undefined behavior emerges.
 */
char	**ft_multisplit( const char* str, const char* delimiters )
{
	char	**ret;
	char	**first_split;
	char	**dels;
	char	del_sep;

	if (NULL == str || NULL == delimiters)
		return (NULL);
	del_sep = get_dels_separator(delimiters);
	dels = ft_split(delimiters, del_sep);
	first_split = ft_split(str, dels[0][0]);
	ret = ft_multisplit_rec( first_split, dels + 1 );
	ft_splitclear(dels);
	ft_splitclear(first_split);
	return (ret);
}

static char	**ft_multisplit_rec( char** str_s, char** delimiters)
{
	char	**ret;
	char	**first_splitted;

	if ( NULL == str_s || NULL == str_s[0] )
		return (NULL);
	ret = str_s;
	if ( NULL != delimiters[0] )
	{
		first_splitted = ft_split(str_s[0], delimiters[0][0]);
		ret = ft_splitjoin(
				ft_multisplit_rec(first_splitted, delimiters + 1),
				ft_multisplit_rec(str_s + 1, delimiters),
				e_true, e_true
			);
		if (delimiters[1])
			ft_splitclear(first_splitted);
	}
	return (ret);
}

static char	get_dels_separator( const char* delimiters )
{
	size_t	cursor;

	cursor = 0;
	while ( delimiters[cursor] )
	{
		if ( ft_str_member(delimiters, delimiters[cursor]) > 1 )
			return (delimiters[cursor]);
		cursor++;
	}
	return ('\0');
}
