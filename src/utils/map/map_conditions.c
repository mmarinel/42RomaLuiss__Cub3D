/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conditions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:49:24 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/02 09:14:38 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"
#include <stdio.h>
/**
 * @brief this functions returns true iff [c] is a valid map character.
 * Valid map characters are wall, floor and player characters;
 * with the player characters been excluded when player has already been found.
 * 
 * @param c 
 * @return t_bool 
 */
t_bool	is_valid_map_char( char c )
{
	static t_bool	player_found = e_false;

	if (is_player_map_char(c))
	{
		if (e_false == player_found)
		{
			player_found = e_true;
			return (e_true);
		}
		else
			return (e_false);
	}
	if (is_floor_map_char(c)
		|| is_wall_map_char(c)
		|| is_empty_map_char(c))
	{
		return (e_true);
	}
		printf("HEREEEE\n");
	return (e_false);
}

t_bool	is_player_map_char( char c )
{
	return (
		'N' == c
		|| 'S' == c
		|| 'W' == c
		|| 'E' == c
	);
}

t_bool	is_floor_map_char( char c )
{
	return ('0' == c );
}

t_bool	is_wall_map_char( char c )
{
	return ('1' == c );
}

t_bool	is_empty_map_char( char c )
{
	return (ft_isspace(c));
}
