/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:36:03 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 13:18:23 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

void	render_minimap(t_list *rays, t_game *g)
{
	const t_int_2d_point	mmp_bottom_left = (t_int_2d_point){
		g->screen_handle.width / MMP_OFFSET,
		g->screen_handle.height - g->screen_handle.height / MMP_OFFSET
	};

	mmp_border_draw_horizontal_frames(&mmp_bottom_left, g);
	mmp_border_draw_vertical_frames(&mmp_bottom_left, g);
	mmp_draw_background(&mmp_bottom_left, g);
	mmp_draw_map(&mmp_bottom_left, g);
	mmp_draw_rays(rays, &mmp_bottom_left, g);
}
