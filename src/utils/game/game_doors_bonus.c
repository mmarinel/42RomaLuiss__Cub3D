/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_doors_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 14:30:03 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 13:05:45 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

t_bool	door_front_side(t_tile door_type, t_side side)
{
	return (
		(side == e_HORIZONTAL && door_type == e_DOOR_HORIZONTAL)
		|| (side == e_VERTICAL && door_type == e_DOOR_VERTICAL)
	);
}
