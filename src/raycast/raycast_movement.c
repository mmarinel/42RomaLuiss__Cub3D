/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_movement.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:33:50 by earendil          #+#    #+#             */
/*   Updated: 2022/12/23 23:03:48 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"

/**
 * @brief this function provides the stopping criteria 
 * for the raycast_movement function
 * 
 * @param rc_data structure holding all relevant data
 * to be processed by the raycast algorithm (raycast_algorithm.c)
 * @param _ unused. Present only for compatibility reasons
 * @return t_bool 
 */
static t_bool			rc_mov_endpoint_reached(const void *rc_data, const void *_);
/**
 * @brief this function provides the initialization criteria
 * for the raycast_movement function.
 * All initialization functions must act as "decorators"
 * for the [ft_ray_data_init] function (.../utils/)
 * 
 * @param rc_data 
 * @param pos 
 * @param ray 
 */
static void				rc_mov_init(void *rc_data, const void *pos, const void *ray);
static t_2d_point		rcmov_endpoint_holder(const t_2d_point *given);
//*		end of static declarations

t_raycast_return	raycast_movement(
	const t_2d_point *old_pos, const t_2d_point *end_point,
	t_game *game
	)
{
	const t_rc_handlers	rc_handlers = (t_rc_handlers){
		rc_mov_endpoint_reached, rc_mov_init
		};
	const t_2d_point	mov_dir = ft_vec_normalize(
		ft_vec_sum(
			ft_vec_opposite(*old_pos),
			*end_point
		)
	);

	rcmov_endpoint_holder(end_point);
	return (raycast_algorithm(old_pos, &mov_dir, rc_handlers, game));
}

static void	rc_mov_init(void *rc_data, const void *pos, const void *ray)
{
	t_raycast_data		*__rc_data = (t_raycast_data *)rc_data;
	const t_2d_point	*__pos = (const t_2d_point *)pos;
	const t_2d_point	*__ray = (const t_2d_point *)ray;

	ft_ray_data_init(__rc_data, __pos, __ray);
	__rc_data->process_bonus_doors = e_true;
	__rc_data->process_bonus_enemies = e_false;
}

static t_bool	rc_mov_endpoint_reached(const void *rc_data, const void *_)
{
	const t_raycast_data	*__rc_data = (const t_raycast_data *)rc_data;
	const t_2d_point		endpoint = rcmov_endpoint_holder(NULL);
	const t_int_2d_point	endtile = as_int_2dpt(&endpoint);

	if (_)
	{}
	return (
		ft_int_2d_point_equals(&__rc_data->cur_sq, &endtile)
	);
}

static t_2d_point	rcmov_endpoint_holder(const t_2d_point *given)
{
	static t_2d_point	endpoint = (t_2d_point){0.0f, 0.0f};

	if (given)
		endpoint = *given;
	return (endpoint);
}
