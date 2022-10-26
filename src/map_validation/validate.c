/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:19:54 by earendil          #+#    #+#             */
/*   Updated: 2022/10/26 15:06:34 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "utils/libft/libft.h"
# include "../types.h"
#include "gnl/get_next_line_module.h"

# define MAP_FILE_EXTENSION ".cub"

t_bool	is_valid_map( const char* path ) {
	if (e_false == is_file_type(path, MAP_FILE_EXTENSION))
		return (e_false);
}
