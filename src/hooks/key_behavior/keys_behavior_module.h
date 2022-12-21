/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_behavior_module.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 17:24:17 by earendil          #+#    #+#             */
/*   Updated: 2022/12/21 20:10:01 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_BEHAVIOR_MODULE_H
# define KEYS_BEHAVIOR_MODULE_H

# include "../../types.h"
# include "../../game_types.h"

//*		player movement
void	w_key_handler_pressed(t_game *game);
void	a_key_handler_pressed(t_game *game);
void	s_key_handler_pressed(t_game *game);
void	d_key_handler_pressed(t_game *game);

//*		player visual
void	right_key_handler_pressed(t_game *game);
void	right_key_handler_released(t_game *game);
void	left_key_handler_pressed(t_game *game);
void	left_key_handler_released(t_game *game);

//*		bonuses
void	e_key_handler(t_game *game);
void	space_key_handler_pressed(t_game *game);
void	space_key_handler_released(t_game *game);

#endif