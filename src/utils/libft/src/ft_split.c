/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 14:56:52 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/30 12:34:33 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char *s, char c);
static int		ft_allocate_words(char *s, char c, char **words_len);
static void		ft_get_split(char *s, char c, char **split);
static int		ft_allocate_word(char **split, size_t *word_len);

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**split;

	if (NULL == s)
		return (NULL);
	size = ft_count_words((char *) s, c);
	split = ft_splitinit(size);
	if (NULL == split || size == 0)
	{
		if (split)
			split[0] = NULL;
		return (split);
	}
	if (!ft_allocate_words((char *) s, c, split))
	{
		ft_splitclear(split);
		return (NULL);
	}
	ft_get_split((char *) s, c, split);
	return (split);
}

static size_t	ft_count_words(char *s, char c)
{
	size_t	size;
	int		delim;

	delim = 0;
	if (*s != c && *s != '\0')
		size = 1;
	else
		size = 0;
	while (*s != '\0')
	{
		if (*s == c && !delim)
			delim += 1;
		else if (*s != c && delim)
		{
			size++;
			delim = 0;
		}
		s++;
	}
	return (size);
}

static int	ft_allocate_words(char *s, char c, char **split)
{
	size_t	word_len;

	word_len = 0;
	while (*s != '\0')
	{
		if (*s == c)
		{
			if (word_len > 0)
			{
				if (!ft_allocate_word(split, &word_len))
					return (0);
				split++;
			}
		}
		else if (*s != c)
			word_len++;
		s++;
	}
	if (word_len > 0)
	{
		if (!ft_allocate_word(split, &word_len))
			return (0);
	}
	return (1);
}

static void	ft_get_split(char *s, char c, char **split)
{
	int		i;

	i = 0;
	while (*s != '\0')
	{
		if (*s == c && i > 0)
		{
			i = 0;
			split++;
		}
		else if (*s != c)
		{
			*(*split + i) = *s;
			i++;
		}
		s++;
	}
}

static int	ft_allocate_word(char **split, size_t *word_len)
{
	*split = (char *) malloc((*word_len + 1) * sizeof(char));
	if (!(*split))
		return (0);
	*(*split + *word_len) = '\0';
	*word_len = 0;
	return (1);
}
