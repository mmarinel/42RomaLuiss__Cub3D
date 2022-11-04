/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:15:44 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/04 11:15:49 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

void	ft_game_init( t_game *game_ref )
{
	if (NULL == game_ref)
		return ;
	game_ref->map_handle.map = NULL;
	game_ref->map_handle.rows = 0;
	game_ref->map_handle.columns = 0;
	game_ref->map_handle.no_texture = NULL;
	game_ref->map_handle.so_texture = NULL;
	game_ref->map_handle.we_texture = NULL;
	game_ref->map_handle.ea_texture = NULL;
	game_ref->map_handle.f_color.alpha = -1;
	game_ref->map_handle.f_color.red = 0;
	game_ref->map_handle.f_color.green = 0;
	game_ref->map_handle.f_color.blue = 0;
	game_ref->map_handle.c_color.alpha = -1;
	game_ref->map_handle.c_color.red = 0;
	game_ref->map_handle.c_color.green = 0;
	game_ref->map_handle.c_color.blue = 0;
}
