/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:38:52 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/04 11:29:52 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	is_file_type( const char *path_name, const char *extension )
{
	size_t	end;
	int		start;

	end = ft_strlen(path_name);
	start = end - ft_strlen(extension);
	if (start < 0)
		return (e_false);
	else
		return (
			0 == ft_strcmp(
				path_name + start,
				extension
			)
		);
}
