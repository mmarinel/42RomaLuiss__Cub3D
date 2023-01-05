/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_entity_map_char_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:37:52 by earendil          #+#    #+#             */
/*   Updated: 2023/01/05 17:39:04 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_validation_bonus.h"

t_bool	is_entity_map_char(char c)
{
	return (
		is_door_map_char(c)
		|| is_enemy_map_char(c)
		|| is_item_map_char(c)
	);
}
