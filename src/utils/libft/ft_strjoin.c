/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:22:37 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/27 09:09:06 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *pre, char *post, t_bool free_pre, t_bool free_post)
{
	char	*joined;

	if ( NULL == pre && NULL == post)
		return (NULL);
	if ( NULL == pre)
		return (ft_strjoin(post, "", free_post, e_false));
	if ( NULL == post)
		return (ft_strjoin(pre, "", free_pre, e_false));
	joined = (char *) malloc(sizeof(char)
			* (ft_strlen(pre) + ft_strlen(post) + 1));
	joined[ft_strlen(pre) + ft_strlen(post)] = '\0';
	ft_strcpy(joined, pre, ft_strlen(pre));
	ft_strcpy(joined + ft_strlen(pre), post, ft_strlen(post));
	if (free_pre && pre)
		free(pre);
	if (free_post && post)
		free(post);
	return (joined);
}
