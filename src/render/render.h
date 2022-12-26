/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 09:32:32 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/26 20:56:18 by earendil         ###   ########.fr       */
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

# define UHD_HP_VERT_OFFS (0					+	0 * UHD_BAR_HEIGHT)
# define UHD_MANA_VERT_OFFS (UHD_HP_VERT_OFFS	+	2 * UHD_BAR_HEIGHT)
# define UHD_ITEM_VERT_OFFS (UHD_MANA_VERT_OFFS	+	2 * UHD_BAR_HEIGHT)

# define MMP_OFFSET (15)
# define MMP_WIDTH (500)
# define MMP_HEIGHT (200)
# define MMP_BORDER_WIDTH (10)

void	draw_background(t_game *g);

//*		uhd
void	render_minimap(t_game *g);
void	render_health_bar(t_game *g);
void	render_mana_bar(t_game *g);
void	render_items_bar(t_game *g);
void	mmp_border_draw_vertical_frames(
			const t_int_2d_point *mmp_start, t_game *g
			);
void	mmp_border_draw_horizontal_frames(
			const t_int_2d_point *mmp_start, t_game *g
			);


//******		bonuses

void	draw_background_bonus(t_game *g);
void	draw_sun(t_game *g);
void	render_attack(t_game *g);
void	render_collision(t_game *g);

#endif