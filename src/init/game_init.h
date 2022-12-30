/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:26:27 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/30 13:46:17 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_INIT_H
# define GAME_INIT_H

# include "../types.h"
# include "../game_types.h"
# include "bonus/game_init_bonus_module.h"
# include "../utils/utils_module.h"
# include "../sys_includes.h"
# include "../map_validation/map_validation_module.h"
# include "../render/utils/uti_render_module.h"
# include "../utils/utils_module.h"

# include "utils/init_utils_module.h"
# include "bonus/game_init_bonus_module.h"

//*		geometry

void	game_set_inital_vectors(t_game *game_ref);
float	player_west_angle(t_game *game_ref);

//*		t_game
void	t_game_set(t_game *game_ref);

//*		mlx
void	game_set_mlx( t_game *game_ref, size_t width, size_t height );

//*		textures
void	load_textures(t_game *game_ref, t_bool *err_flag);

//*		keys
void	game_set_key_state(t_game *game_ref);

//*		map
void	game_set_map( t_game *game_ref );

# endif