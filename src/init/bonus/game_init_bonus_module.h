/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus_module.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:51:46 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 13:36:24 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_INIT_BONUS_MODULE_H
# define GAME_INIT_BONUS_MODULE_H

# include "../../game_types.h"

//*		textures
void	load_bonus_textures(t_game *game_ref, t_bool *err_flag);

//*		entities lists
void	scan_enemies(t_game *game_ref);
void	scan_items(t_game *game_ref);
void	scan_doors(t_game *game_ref);

#endif