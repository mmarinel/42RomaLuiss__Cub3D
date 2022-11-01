/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conditions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 15:49:24 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/01 17:38:57 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

t_bool	is_map_char( char c )
{
	return (
		e_true == ft_isspace(c)
		|| '0' == c
		|| '1' == c
		|| 'N' == c
		|| 'S' == c
		|| 'W' == c
		|| 'E' == c
	);
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
