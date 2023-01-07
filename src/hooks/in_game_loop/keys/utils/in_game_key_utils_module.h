/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_game_key_utils_module.h                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:10:16 by earendil          #+#    #+#             */
/*   Updated: 2023/01/07 12:24:20 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IN_GAME_KEY_UTILS_MODULE_H
# define IN_GAME_KEY_UTILS_MODULE_H

# include "../../../../includes/basic_types.h"
# include "../../../../includes/game_types.h"

t_2d_point	new_player_pos(t_key key_pressed, t_game *game);

#endif