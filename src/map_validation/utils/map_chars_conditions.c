/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chars_conditions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:49:24 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/04 11:17:30 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

t_bool	is_player_map_char( char c )
{
	return (
		e_PLAYER_N == c
		|| e_PLAYER_S == c
		|| e_PLAYER_W == c
		|| e_PLAYER_E == c
	);
}

t_bool	is_floor_map_char( char c )
{
	return (e_FLOOR == c);
}

t_bool	is_wall_map_char( char c )
{
	return (e_WALL == c);
}

t_bool	is_empty_map_char( char c )
{
	return (ft_isspace(c));
}
