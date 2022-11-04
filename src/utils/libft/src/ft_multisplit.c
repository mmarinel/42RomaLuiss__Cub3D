/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multisplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 07:59:42 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/04 09:23:36 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_multisplit_rec( char** cur_split, char** delimiters);
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
	ft_splitclear(&dels);
	ft_splitclear(&first_split);
	return (ret);
}

static char	**ft_multisplit_rec( char** cur_split, char** delimiters)
{
	char	**ret;
	char	**first_el_splitted;
	char	**tail;

	if ( NULL == cur_split || NULL == cur_split[0] )
		return (NULL);
	if ( NULL != delimiters[0] )
	{
		first_el_splitted = ft_split(cur_split[0], delimiters[0][0]);
		tail = ft_splitcpy(NULL, cur_split + 1, ft_splitlen(cur_split) - 1);
		ret = ft_splitjoin(
				ft_multisplit_rec(first_el_splitted, delimiters + 1),
				ft_multisplit_rec(tail, delimiters),
				e_true, e_true
			);
		ft_splitclear(&first_el_splitted);
		ft_splitclear(&tail);
	}
	else
		ret = ft_splitcpy(NULL, cur_split, ft_splitlen(cur_split));
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
