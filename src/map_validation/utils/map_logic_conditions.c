/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_logic_conditions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:41:55 by earendil          #+#    #+#             */
/*   Updated: 2022/12/22 14:51:14 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

t_bool	is_map_edge(
	const t_map_holder *map_handle,
	int x, int y
)
{
	return (
		(0 == x || (int)map_handle->columns - 1 == x)
		|| (0 == y || (int)map_handle->rows - 1 == y)
	);
}

t_bool	map_fields_complete( t_map_holder *map_handle )
{
	return (
		map_handle->no_texture && map_handle->so_texture
		&& map_handle->we_texture && map_handle->ea_texture
		&& -1 != map_handle->f_color.alpha && -1 != map_handle->c_color.alpha
	);
}
