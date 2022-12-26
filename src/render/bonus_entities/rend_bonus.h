/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:24:10 by earendil          #+#    #+#             */
/*   Updated: 2022/12/26 16:02:08 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REND_BONUS_H
# define REND_BONUS_H

# include "../../types.h"
# include "../../game_types.h"
# include "../../raycast/raycast_types.h"
# include "../render_types.h"

# include "../line_drawing/line_drawing_module.h"
# include "../textures/textures_module.h"
# include "../../utils/utils_module.h"

# include "../../sys_includes.h"

//*		entities rendering (enemy and item)
void	render_item(t_rendered_entity *item_data, t_game *g);
void	render_enemy(t_rendered_entity *enemy_data, t_game *g);

//*		entities lst callbacks
t_bool	rend_enemy_spotted(const void *cur, const void *enemy);
t_bool	rend_item_spotted(const void *cur, const void *item);
t_bool	rendent_greater_than(const void *ent_1, const void *ent_2);

#endif