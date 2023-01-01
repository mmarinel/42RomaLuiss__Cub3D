/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_game_loops_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 19:29:29 by earendil          #+#    #+#             */
/*   Updated: 2023/01/01 20:24:05 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IN_GAME_LOOPS_BONUS_H
# define IN_GAME_LOOPS_BONUS_H

# include "../../../types.h"
# include "../../../game_types.h"

# include "../../../sys_includes.h"
# include "../../../sys_includes_bonus.h"

# include "../../../utils/utils_module.h"
# include "../../../raycast/raycast_module.h"

//*		player
void	player_enemy_collision_check(t_game *game);
void	player_item_collision_check(t_game *game);

//*		doors
void	animate_doors(t_game *game);

//*		enemies
void	move_enemies(t_game *game);
void	enemies_anim_death(t_game *game);
void	clean_enemies(t_game *game);

//*		items
void	clean_items(t_game *game);

//*		west_angle
void	west_angle_adjust(t_game *game);

#endif