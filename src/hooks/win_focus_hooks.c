/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_focus_hooks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:29:28 by earendil          #+#    #+#             */
/*   Updated: 2022/12/21 18:29:33 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hooks.h"

int	leave_window(t_game *game)
{
	game->in_game = e_false;
	return (0);
}

int	enter_window(t_game *game)
{
	game->in_game = e_true;
	return (0);
}
