/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menus_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:20:03 by earendil          #+#    #+#             */
/*   Updated: 2023/01/02 10:44:06 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game_init.h"

void	game_init_menus(t_game *game_ref)
{
	game_ref->menu.in_initial_menu = e_true;
	game_ref->menu.in_end_menu = e_false;
	game_ref->menu.menu_screen = 0;
	game_ref->menu.mouse_clicked = e_false;
	game_ref->menu.newg_btn_top_left = (t_int_2d_point){417, 282};
	game_ref->menu.newg_btn_bottom_right = (t_int_2d_point){862, 470};
	game_ref->menu.exit_btn_top_left = (t_int_2d_point){417, 463};
	game_ref->menu.exit_btn_bottom_right = (t_int_2d_point){862, 586};
}
