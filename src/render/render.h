/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 09:32:32 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/22 00:48:58 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../colors.h"

# include "render_types.h"
# include "../types.h"
# include "../game_types.h"

# include "../utils/utils_module.h"
# include "textures/textures_module.h"
# include "line_drawing/line_drawing_module.h"
# include "../raycast/raycast_module.h"
# include "utils/uti_render_module.h"

# include "bonus_entities/rend_bonus_module.h"
# include "../utils/utils_module.h"

# include "../sys_includes.h"

void	draw_background(t_game *g);

//*		uhd
void	render_health_bar(t_game *g);
void	render_mana_bar(t_game *g);


//******		bonuses

void	draw_background_bonus(t_game *g);
void	draw_sun(t_game *g);
void	render_attack(t_game *g);
void	render_collision(t_game *g);

#endif