/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_module.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:12:53 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/05 18:52:21 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_UTILS_MODULE_H
# define GAME_UTILS_MODULE_H

# include "../../types.h"
# include "game_utils.h"

//*		coordinates
t_2d_point	ft_get_new_2dpt(int x, int y);

//*		game memory management
void		ft_game_init( t_game *game_ref );

#endif