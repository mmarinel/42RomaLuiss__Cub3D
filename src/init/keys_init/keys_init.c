/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:39:32 by earendil          #+#    #+#             */
/*   Updated: 2023/01/01 14:40:35 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_init.h"

void	game_init_keys(t_game *game_ref)
{
	game_ref->key_map = (t_key_state_map){
		(t_key_state){e_W_KEY, -1},
		(t_key_state){e_A_KEY, -1},
		(t_key_state){e_S_KEY, -1},
		(t_key_state){e_D_KEY, -1},
		(t_key_state){e_SHIFT_KEY, -1},
		(t_key_state){e_UP_KEY, -1},
		(t_key_state){e_DOWN_KEY, -1},
		(t_key_state){e_RIGHT_KEY, -1},
		(t_key_state){e_LEFT_KEY, -1},
		(t_key_state){e_SPACE_KEY, -1},
		(t_key_state){e_E_KEY, -1},
		(t_key_state){e_ENTER_KEY, -1},
		(t_key_state){e_ESC_KEY, -1},
	};
}
