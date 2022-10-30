/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:33:09 by mmarinel          #+#    #+#             */
/*   Updated: 2022/01/20 06:34:44 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_map(char *s, char *mapped, size_t cur_index,
				char (*f)(unsigned int, char));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	char	*mapped;

	if (!s || !f)
		return (NULL);
	s_len = ft_strlen((const char *) s);
	mapped = (char *) malloc((s_len + 1) * sizeof(char));
	if (!mapped)
		return (NULL);
	ft_map((char *) s, mapped, 0, f);
	return (mapped);
}

static void	ft_map(char *s, char *mapped, size_t cur_index,
	char (*f)(unsigned int, char))
{
	if (s[cur_index] != '\0')
	{
		mapped[cur_index] = f(cur_index, s[cur_index]);
		ft_map(s, mapped, cur_index + 1, f);
	}
	else
		mapped[cur_index] = '\0';
}
