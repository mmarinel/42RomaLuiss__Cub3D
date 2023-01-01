/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_menu_loop_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:48:21 by earendil          #+#    #+#             */
/*   Updated: 2023/01/01 17:40:13 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IN_MENU_LOOP_BONUS_H
# define IN_MENU_LOOP_BONUS_H

# include "../../types.h"
# include "../../game_types.h"

# include "../../macros.h"
# include "../../X11_macros.h"

# include "../../sys_includes.h"

# include "../../init/game_init_module.h"
# include "../../exit/exit_module.h"

void	in_menu_keys_handler(t_game *game);
void	in_menu_mouse_handler(t_game *game);

//*		keys
void	in_menu_enter_key(t_key_state *key, t_game *game);
void	in_menu_move(t_key_state *key, t_game *game);

#endif