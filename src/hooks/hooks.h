/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:15:46 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 12:46:50 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

# include "../types.h"
# include "../game_types.h"

# include "../macros.h"
# include "../X11_macros.h"

# include "../sys_includes.h"

# include "../exit/exit_module.h"
# include "../utils/utils_module.h"
# include "key_behavior/keys_behavior_module.h"
# include "../render/render_module.h"

//*		loop bonuses

void	in_game_loop(t_game *game);
void	in_menu_loop(t_game *game);
void	west_angle_update(t_game *game);

//*			enemies
void	move_enemies(t_game *game);
void	enemies_anim_death(t_game *game);
void	attack_enemies(t_game *game);
void	clean_enemies(t_game *game);

//*		items
void	clean_items(t_game *game);

//*			doors
void	animate_doors(t_game *game);

//*			player
void	player_enemy_collision_check(t_game *game);
void	player_item_collision_check(t_game *game);

#endif