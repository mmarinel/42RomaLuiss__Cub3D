/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_game_keys_bon_module.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:04:12 by earendil          #+#    #+#             */
/*   Updated: 2023/01/13 10:48:50 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IN_GAME_KEYS_BON_MODULE_H
# define IN_GAME_KEYS_BON_MODULE_H

# include "../../../../includes/basic_types.h"
# include "../../../../includes/game_types.h"

void	in_game_e_key(t_key_state *key, t_game *game);
void	in_game_space_key(t_key_state *key, t_game *game);
void	in_game_shift_key(t_key_state *key, t_game *game);

#endif