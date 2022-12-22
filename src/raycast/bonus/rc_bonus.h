/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:36:14 by earendil          #+#    #+#             */
/*   Updated: 2022/12/22 22:26:58 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RC_BONUS_H
# define RC_BONUS_H

# include "../raycast_types.h"
# include "../utils/rc_utils_module.h"
# include "../../map_validation/utils/map_utils_module.h"

//*		memory utils
t_spotted_door *new_spotted_door_data(
	const t_raycast_data *rc_data,
	const t_2d_point *pos, const t_2d_point *ray,
	t_game *game
	);

#endif