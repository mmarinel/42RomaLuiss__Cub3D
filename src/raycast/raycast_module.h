/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_module.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:05:17 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/11 17:47:44 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_MODULE_H
# define RAYCAST_MODULE_H

# include "ray_cast_types.h"

t_raycast_return	raycast(t_game *game, t_fixed ray_angle);
void				ft_print_ray_result(t_raycast_return raycast_info);

#endif