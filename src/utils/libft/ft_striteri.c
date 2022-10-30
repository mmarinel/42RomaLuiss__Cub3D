/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:57:21 by mmarinel          #+#    #+#             */
/*   Updated: 2022/01/19 20:11:55 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_map(char *s, size_t cur_index,
				void (*f)(unsigned int, char *));

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	if (s)
		ft_map((char *) s, 0, f);
}

static void	ft_map(char *s, size_t cur_index,
				void (*f)(unsigned int, char *))
{
	if (s[cur_index] != '\0')
	{
		f(cur_index, s + cur_index);
		ft_map(s, cur_index + 1, f);
	}
}
