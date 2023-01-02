/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:29:22 by earendil          #+#    #+#             */
/*   Updated: 2023/01/02 10:32:08 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

t_bool	rect_button_focused(
	const t_int_2d_point *px,
	const t_int_2d_point *top_left,
	const t_int_2d_point *bottom_right
	)
{
	return (
		(px->x >= top_left->x && px->x <= bottom_right->x)
		&& (px->y >= top_left->y && px->y <= bottom_right->y)
	);
}
