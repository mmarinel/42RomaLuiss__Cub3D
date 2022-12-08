/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_nonl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:00:08 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/08 20:00:16 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line_nonl(int fd)
{
	char	*ret;
	char	*line;

	ret = NULL;
	line = get_next_line(fd);
	if (line)
	{
		gnl_strlcpy(&ret, line, gnl_strlen(line) - 1);
		free(line);
	}
	return (ret);
}
