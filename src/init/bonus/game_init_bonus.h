/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:50:37 by earendil          #+#    #+#             */
/*   Updated: 2023/01/07 12:06:17 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_INIT_BONUS_H
# define GAME_INIT_BONUS_H

# include "../../basic_types.h"
# include "../../game_types.h"

# include "../../sys_includes.h"
# include "../../sys_includes_bonus.h"

# include "../../utils/utils_module.h"

# include "../utils/init_utils_module.h"

//*		textures
void	load_sun_textures(t_game *game_ref, t_bool *err_flag);
void	load_menu_textures(t_game *game_ref, t_bool *err_flag);

#endif