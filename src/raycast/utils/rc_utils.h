/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:14:51 by earendil          #+#    #+#             */
/*   Updated: 2023/01/07 11:34:48 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RC_UTILS_H
# define RC_UTILS_H

# include "../raycast_types.h"

# include "../../utils/utils_module.h"

# include "../../sys_includes.h"

//*		calculations
float	perp_calc(
					float euclidean_dist,
					const t_raycast_data *rc_data
				);
float	euclid_calc(
					const t_raycast_data *rc_data
				);

#endif