/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_background_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:38:54 by earendil          #+#    #+#             */
/*   Updated: 2022/12/17 18:08:43 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "rc_bonus.h"

static void	background_raycast(t_raycast_data *rc_data, t_game *game);
static void	set_background_cardinal(
	const t_raycast_data *rc_data,
	t_raycast_return *rc_ret,
	t_game *game
	);
//*		end of static declarations

void	rc_set_background_info(
	t_raycast_data *rc_data,
	t_raycast_return *rc_ret,
	const t_2d_point *ray,
	t_game *game
	)
{
	background_raycast(rc_data, game);
	rc_ret_set_data(rc_data, &rc_ret->background.data, ray, game);
	set_background_cardinal(rc_data, rc_ret, game);
}

static void	background_raycast(t_raycast_data *rc_data, t_game *game)
{
	t_int_2d_point	cur_sq;

	while (e_true)
	{
		cur_sq = rc_data->cur_sq;
		ft_walk_through_nhp(rc_data);
		if (e_false == is_map_pos(&game->map_handle, &rc_data->cur_sq))
			break ;
	}
	rc_data->cur_sq = cur_sq;
}

/**
 * @brief Considering the world to be enclosed in a square with
 * north, south, west and east sides,
 * this function sets (in the ray_cast_return object)
 * which side of such square the given ray hits
 * 
 * @param rc_data the structure containing raycast data
 * (including the casted ray)
 * @param rc_ret
 * @param game 
 */
static void	set_background_cardinal(
	const t_raycast_data *rc_data,
	t_raycast_return *rc_ret,
	t_game *game
	)
{
	if (0 == rc_data->cur_sq.y)
		rc_ret->background.cardinal = e_RC_BG_SOUTH;
	else if ((int)game->map_handle.rows - 1 == rc_data->cur_sq.y)
		rc_ret->background.cardinal = e_RC_BG_NORTH;
	else if (0 == rc_data->cur_sq.x)
		rc_ret->background.cardinal = e_RC_BG_EAST;
	else if ((int)game->map_handle.columns - 1 == rc_data->cur_sq.x)
		rc_ret->background.cardinal = e_RC_BG_WEST;
	else
		rc_ret->background.cardinal = e_RC_BG_NONE;
}
