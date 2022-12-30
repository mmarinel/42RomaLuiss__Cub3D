/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:44:15 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 12:47:45 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	exit_game(t_game *game)
{
	ft_lstclear(&game->doors, free);
	ft_lstclear(&game->items, free);
	ft_lstclear(&game->enemies, free);
	exit(EXIT_SUCCESS);
}
