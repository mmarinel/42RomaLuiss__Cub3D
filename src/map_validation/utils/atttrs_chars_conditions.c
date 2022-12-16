/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atttrs_chars_conditions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 10:17:12 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/04 10:40:11 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_utils.h"

t_bool	is_attrs_char( const char *id )
{
	return (
		is_attrs_player_dir_char(id)
		|| is_attrs_color_field_char(id)
	);
}

t_bool	is_attrs_player_dir_char( const char *id )
{
	return (
		0 == ft_strcmp(id, "NO")
		|| 0 == ft_strcmp(id, "SO")
		|| 0 == ft_strcmp(id, "WE")
		|| 0 == ft_strcmp(id, "EA")
	);
}

t_bool	is_attrs_color_field_char( const char *id )
{
	return (is_floor_color_id(id) || is_ceiling_color_id(id));
}

t_bool	is_floor_color_id( const char *id )
{
	return (0 == ft_strcmp(id, "F"));
}

t_bool	is_ceiling_color_id( const char *id )
{
	return (0 == ft_strcmp(id, "C"));
}
