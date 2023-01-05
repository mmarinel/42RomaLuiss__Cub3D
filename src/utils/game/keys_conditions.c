/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_conditions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:39:31 by earendil          #+#    #+#             */
/*   Updated: 2023/01/05 13:40:03 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

t_bool	is_movement_key(t_key_state *key)
{
	return (
		e_W_KEY == key->code
		|| e_A_KEY == key->code
		|| e_S_KEY == key->code
		|| e_D_KEY == key->code
		|| e_SHIFT_KEY == key->code
	);
}

t_bool	is_rotation_key(t_key_state *key)
{
	return (
		e_LEFT_KEY == key->code || e_RIGHT_KEY == key->code
	);
}
