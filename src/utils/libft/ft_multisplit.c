/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multisplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 07:59:42 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/28 10:42:26 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_multisplit_rec( char** str_s, char** delimiters);
//* end of static declarations

/**
 * @brief 
 * 
 * @param str 
 * @param delimiters 
 * @param del_sep seprator for the delimiters string
 * @return char** 
 */
char	**ft_multisplit( const char* str, const char* delimiters, char del_sep )
{
	char	**ret;
	char	**first_split;
	char	**dels;

	if (NULL == str || NULL == delimiters)
		return (NULL);
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

	if ( NULL == str_s[0] )
		return (NULL);
	ret = str_s;
	if ( NULL != delimiters[0] )
	{
		first_splitted = ft_split(ret[0], delimiters[0][0]);
		ret = ft_splitjoin(
				ft_multisplit_rec(first_splitted, delimiters + 1),
				ft_multisplit_rec(ret + 1, delimiters),
				e_true, e_true
			);
		ft_splitclear(first_splitted);
	}
	return (ret);
}