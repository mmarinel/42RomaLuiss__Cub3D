/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chars_conditions_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:23:24 by earendil          #+#    #+#             */
/*   Updated: 2022/12/20 13:25:26 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation_bonus.h"

t_bool	is_door_map_char( char c )
{
	return (
		e_DOOR == c
	);
}
