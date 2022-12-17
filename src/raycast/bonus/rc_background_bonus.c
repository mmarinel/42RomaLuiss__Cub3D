/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_background_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:38:54 by earendil          #+#    #+#             */
/*   Updated: 2022/12/17 14:58:55 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rc_bonus.h"

void	rec_background_info(
	t_raycast_data *rc_data,
	t_raycast_return *rc_ret,
	t_game *game
	)
{(void)rc_ret;
	while (e_false == is_edge(&game->map_handle, &rc_data->cur_sq))
	{
		ft_walk_through_nhp(rc_data);
	}
	if (rc_data->cur_sq.x == (int)game->map_handle.columns - 1)
	{
		
	}
}
