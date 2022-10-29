/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 14:14:58 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/29 16:51:25 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define READ_ERROR -1

typedef struct s_fd_buffer {
	char			*buf;
	size_t			buffer_size;
	unsigned int	offset;
}	t_fd_buffer;

# ifndef T_BOOL
#  define T_BOOL
typedef enum e_bool
{
	e_true = 1,
	e_false = 0
}	t_bool;
# endif

//* utils

void	gnl_strcpy(char *dst, char *src);
void	gnl_strlcpy(char **dst, char *src, int dst_len);
char	*gnl_strjoin(char const *pre, char const *post, t_bool free_pre, t_bool free_post);
size_t	gnl_strlen(const char *str);
void	*gnl_memset(void *b, int c, size_t len);

#endif