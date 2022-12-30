/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:50:37 by earendil          #+#    #+#             */
/*   Updated: 2022/12/30 14:06:51 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_INIT_BONUS_H
# define GAME_INIT_BONUS_H

# include "../../types.h"
# include "../../game_types.h"
# include "../../utils/utils_module.h"
# include "../../sys_includes.h"
# include "../../map_validation/map_validation_module.h"
# include "../../map_validation/utils/map_utils_module.h"
# include "../../render/utils/uti_render_module.h"
# include "../../utils/utils_module.h"

# include "../utils/init_utils_module.h"

//*		textures
void	load_sun_textures(t_game *game_ref, t_bool *err_flag);
void	load_menu_textures(t_game *game_ref, t_bool *err_flag);

#endif