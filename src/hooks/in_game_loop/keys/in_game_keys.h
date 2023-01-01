/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_game_keys.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:24:17 by earendil          #+#    #+#             */
/*   Updated: 2023/01/01 19:51:12 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IN_GAME_KEYS_H
# define IN_GAME_KEYS_H

# include "../../../types.h"
# include "../../../game_types.h"

# include "../../../utils/utils_module.h"

# include "../../../sys_includes.h"

# include "bonus/in_game_keys_bonus_module.h"
# include "utils/in_game_key_utils_module.h"

//*		player movement
void	in_game_movement_key(t_key_state *key, t_game *game);

//*		player visual
void	in_game_rotation_key(t_key_state *key, t_game *game);

#endif