/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:25:26 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 11:57:24 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

/**
 * @brief this function provides the stopping criteria 
 * for the  raycast_wall function
 * 
 * @param hit_flag the flag indicating whether a wall has been hit until now
 * @param _ unused. Present only for compatibility reasons
 * @return t_bool 
 */
static t_bool	rc_wall_hit(const void *_, const void *hit_flag);
/**
 * @brief this function provides the initialization criteria
 * for the raycast_wall function.
 * All initialization functions must act as "decorators"
 * for the [ft_ray_data_init] function (.../utils/)
 * 
 * @param rc_data 
 * @param pos 
 * @param ray 
 */
static void		rc_wall_init(void *rc_data, const void *pos, const void *ray);
//*		end of static declarations

/**
 * @brief this function performs the standard raycast algorithm.
 * It stops when a wall is hit and it takes track of the bonus data
 * iff the [BONUS] MACRO is set.
 * 
 * @param game 
 * @param ray the ray spawning from the player position.
 * @return t_raycast_return 
 */
t_raycast_return	raycast_wall(
	t_game *game, t_2d_point ray
	)
{
	const t_rc_handlers	rc_handlers = (t_rc_handlers){
		rc_wall_hit, rc_wall_init
	};

	return (raycast_algorithm(&game->player.pos, &ray, rc_handlers, game));
}

static void	rc_wall_init(void *rc_data, const void *pos, const void *ray)
{
	t_raycast_data *const	__rc_data = (t_raycast_data *)rc_data;
	const t_2d_point		*__pos = (const t_2d_point *)pos;
	const t_2d_point		*__ray = (const t_2d_point *)ray;

	ft_ray_data_init(__rc_data, __pos, __ray);
	__rc_data->process_bonus_doors = e_true;
	__rc_data->process_bonus_enemies = e_true;
	__rc_data->process_bonus_items = e_true;
}

static t_bool	rc_wall_hit(const void *_, const void *hit_flag)
{
	const t_bool	*__hit_flag = (const t_bool *)hit_flag;

	if (_)
	{
	}
	return (e_true == *__hit_flag);
}
