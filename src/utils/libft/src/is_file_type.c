/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_type.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:38:52 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/26 15:45:47 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft.h"

t_bool	is_file_type( const char* path_name, const char* extension )
{
	size_t	end;
	size_t	start;

	end = ft_strlen(path_name) - 1;
	start = end - ft_strlen(extension);
	if (end < 0)
		return (e_false);
	else
		return (
			ft_strcmp(
				path_name + start,
				extension
			)
		);
}
