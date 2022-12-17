/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_logic_conditions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 17:41:55 by earendil          #+#    #+#             */
/*   Updated: 2022/12/17 14:36:09 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

static t_bool	player_tracker(char c);
//* end of static declarations

t_bool	is_edge(const t_map_holder *map_handle, const t_int_2d_point *pos)
{
	if (NULL == map_handle)
		return (e_false);
	else
		return (
			(0 == pos->x || pos->x == (int)map_handle->columns - 1)
			|| (0 == pos->y || pos->y == (int)map_handle->rows - 1)
		);
}

/**
 * @brief this functions returns true iff [c] is a valid map character.
 * Valid map characters are wall, floor and player characters,
 * with the player characters been excluded when player has already been found.
 * 
 * @param c 
 * @return t_bool 
 */
t_bool	is_valid_map_char( char c )
{
	if (is_player_map_char(c))
	{
		if (is_player_found())
			return (e_false);
		else
		{
			player_tracker(c);
			return (e_true);
		}
	}
	if (is_floor_map_char(c)
		|| is_wall_map_char(c)
		|| is_empty_map_char(c))
	{
		return (e_true);
	}
	return (e_false);
}

t_bool	is_player_found(void)
{
	return (player_tracker(e_WALL));
}

t_bool	map_fields_complete( t_map_holder *map_handle )
{
	return (
		map_handle->no_texture && map_handle->so_texture
		&& map_handle->we_texture && map_handle->ea_texture
		&& -1 != map_handle->f_color.alpha && -1 != map_handle->c_color.alpha
	);
}

/**
 * @brief This function returns true iff player has already been found.
 * That means if a previous call to this function was successful
 * or the given input is a player map character.
 * 
 * @param c a map character
 * @return t_bool 
 */
t_bool	player_tracker(char c)
{
	static t_bool	player_found = e_false;

	if (is_player_map_char(c))
		player_found = e_true;
	return (player_found);
}
