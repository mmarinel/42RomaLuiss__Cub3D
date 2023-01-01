/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_menu_loop_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:10:22 by earendil          #+#    #+#             */
/*   Updated: 2023/01/01 17:41:52 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "in_menu_loop_bonus.h"

void	in_menus_loop(t_game *game)
{
	in_menu_keys_handler(game);
	in_menu_mouse_handler(game);
}
