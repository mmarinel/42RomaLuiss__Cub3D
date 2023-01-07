/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 09:32:32 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/07 12:06:47 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "../colors.h"

# include "render_types.h"
# include "../basic_types.h"
# include "../game_types.h"

# include "../utils/utils_module.h"
# include "textures/textures_module.h"
# include "line_drawing/line_drawing_module.h"
# include "../raycast/raycast_module.h"
# include "utils/uti_render_module.h"

# include "bonus_entities/rend_bon_module.h"
# include "../utils/utils_module.h"

# include "../sys_includes.h"

void	draw_background_mand(t_game *g);

//*		hud
void	render_minimap(t_list *rays, t_game *g);
void	mmp_draw_map(
			const t_int_2d_point *mmp_bottom_left, t_game *g
			);
void	mmp_draw_rays(
			t_list *rays,
			const t_int_2d_point *mmp_bottom_left,
			t_game *g
			);
void	mmp_border_draw_vertical_frames(
			const t_int_2d_point *mmp_start, t_game *g
			);
void	mmp_border_draw_horizontal_frames(
			const t_int_2d_point *mmp_start, t_game *g
			);
void	mmp_draw_background(
			const t_int_2d_point *mmp_bottom_left, t_game *g
			);
void	render_health_bar(t_game *g);
void	render_mana_bar(t_game *g);
void	render_items_bar(t_game *g);

//******		bonuses

//*		in_menu
void	render_menu_next_frame(t_game *g);

//*		in_game
void	render_game_next_frame(t_game *g);

void	draw_background_bonus(t_game *g);
void	draw_sun(t_game *g);
void	render_attack(t_game *g);
void	render_collision(t_game *g);

//*		memory
void	clean_rays(t_list **rays);
void	clean_entities(t_list **entities);

#endif