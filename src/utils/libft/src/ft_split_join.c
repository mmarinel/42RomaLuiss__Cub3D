/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_join.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 08:34:16 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/04 11:42:14 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**empty_split( void );
//* end of static declarations

char	**ft_splitjoin( char **pre, char **post,
			t_bool free_pre, t_bool free_post )
{
	char	**joined;
	size_t	len_pre;
	size_t	len_post;

	if (NULL == pre && NULL == post)
		return (NULL);
	if (NULL == pre)
		return (ft_splitjoin(post, empty_split(), free_post, e_true));
	if (NULL == post)
		return (ft_splitjoin(pre, empty_split(), free_pre, e_true));
	len_pre = ft_splitlen(pre);
	len_post = ft_splitlen(post);
	joined = ft_splitinit(len_pre + len_post);
	ft_splitcpy(joined, pre, ft_splitlen(pre));
	ft_splitcpy(joined + ft_splitlen(pre), post, ft_splitlen(post));
	if (free_pre)
		ft_splitclear(&pre);
	if (free_post)
		ft_splitclear(&post);
	return (joined);
}

static char	**empty_split( void )
{
	return (ft_splitinit(0));
}
