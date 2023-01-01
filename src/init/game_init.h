/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:26:27 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/01 14:40:53 by earendil         ###   ########.fr       */
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
# include "../utils/utils_module.h"

# include "utils/init_utils_module.h"
# include "bonus/game_init_bonus_module.h"

//*		geometry

void	game_set_inital_vectors(t_game *game_ref);
float	player_west_angle(t_game *game_ref);

//*		t_game
void	t_game_init(t_game *game_ref);
void	t_game_set(const char *map_path, t_game *game_ref);

//*		mlx
void	game_set_mlx( t_game *game_ref, size_t width, size_t height );

//*		textures
void	game_init_textures(t_game *game_ref);
void	load_textures(t_game *game_ref, t_bool *err_flag);

//*		keys
void	game_init_keys(t_game *game_ref);

//*		map
void	game_init_map( t_game *game_ref );

//*		sys bonus
void	set_rand(void);

# endif