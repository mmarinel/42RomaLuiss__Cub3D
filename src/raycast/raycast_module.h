/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_module.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:05:17 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/17 11:42:50 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_MODULE_H
# define RAYCAST_MODULE_H

# include "raycast_types.h"
# include "../game_types.h"
# include "../utils/math/uti_math_types.h"

t_raycast_return	raycast(t_game *game, t_2d_point ray_dir);

//*		debug
void				ft_print_raycast_result(t_raycast_return raycast_info);

#endif