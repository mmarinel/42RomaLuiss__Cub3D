/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multisplit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 07:59:42 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/29 18:27:21 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_multisplit_rec( char** str_s, char** delimiters);
// static char	**ft_non_empty_split( char const *str, char del );
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
	// ft_splitprint(dels);
	// exit(0);
	first_split = ft_split(str, dels[0][0]);
	// ft_splitprint(first_split);
	// exit(0);
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

// static char	**ft_non_empty_split( char const *str, char del )
// {
// 	char	**split;

// 	split = ft_split(str, del);
// 	if (NULL == split || NULL == split[0])
// 	{
// 		ft_splitclear(split);
// 		split = NULL;
// 	}
// 	return (split);
// }
