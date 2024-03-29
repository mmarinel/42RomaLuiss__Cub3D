/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:26:27 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/12 12:04:23 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_INIT_H
# define GAME_INIT_H

# include "../includes/basic_types.h"
# include "../includes/game_types.h"
# include "../utils/utils_module.h"

# include "../includes/sys_includes.h"

# include "../map_validation/map_validation_module.h"
# include "../utils/utils_module.h"
# include "utils/init_utils_module.h"
# include "bonus/game_init_bon_module.h"

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
void	map_reset(t_map_holder *map_handle);

//*		menus
void	game_init_menus(t_game *game_ref);

#endif