/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_game_loop_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 10:59:49 by earendil          #+#    #+#             */
/*   Updated: 2023/01/01 19:53:37 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "in_game_loop.h"

void	in_game_loop(t_game *game)
{
	in_game_keys_handler(game);
	in_game_mouse_handler(game);
	in_game_loops_handler(game);
}
