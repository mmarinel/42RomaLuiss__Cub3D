/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_game_keys_bonus_module.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:04:12 by earendil          #+#    #+#             */
/*   Updated: 2023/01/01 19:46:35 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IN_GAME_KEYS_BONUS_MODULE_H
# define IN_GAME_KEYS_BONUS_MODULE_H

# include "../../../../types.h"
# include "../../../../game_types.h"

void	in_game_e_key(t_key_state *key, t_game *game);
void	in_game_space_key(t_key_state *key, t_game *game);

#endif