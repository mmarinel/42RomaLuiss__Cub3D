/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:19:54 by earendil          #+#    #+#             */
/*   Updated: 2022/10/25 17:27:01 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # include "utils/libft/libft.h" //TODO DA AGGIUNGERE
# include "../types.h"
#include "gnl/get_next_line_module.h"

# define MAP_FILE_EXTENSION ".cub"

t_bool	is_valid_map( const char* path ) {
	if (e_false == is_file_type(path, MAP_FILE_EXTENSION))
		return (e_false);
}