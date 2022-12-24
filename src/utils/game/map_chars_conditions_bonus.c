/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chars_conditions_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:23:24 by earendil          #+#    #+#             */
/*   Updated: 2022/12/24 15:01:34 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

t_bool	is_door_map_char( char c )
{
	return (
		e_DOOR_HORIZONTAL == c || e_DOOR_VERTICAL == c
	);
}

t_bool	is_enemy_map_char( char c )
{
	return (e_ENEMY == c);
}

t_bool	is_item_map_char( char c )
{
	return (e_ITEM == c);
}
