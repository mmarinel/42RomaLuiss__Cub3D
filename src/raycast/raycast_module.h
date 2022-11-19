/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_module.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 12:05:17 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/19 15:39:46 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_MODULE_H
# define RAYCAST_MODULE_H

# include "raycast_types.h"

t_raycast_return	raycast(t_game *game, float ray_angle);
void				ft_print_raycast_result(t_raycast_return raycast_info);

#endif