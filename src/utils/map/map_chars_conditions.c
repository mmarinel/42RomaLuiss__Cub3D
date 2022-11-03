/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conditions_simple.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:49:24 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/03 17:43:15 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"
#include <stdio.h>

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
	return (e_FLOOR == c );
}

t_bool	is_wall_map_char( char c )
{
	return (e_WALL == c );
}

t_bool	is_empty_map_char( char c )
{
	return (ft_isspace(c));
}
