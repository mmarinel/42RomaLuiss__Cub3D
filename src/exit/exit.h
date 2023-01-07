/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:43:32 by earendil          #+#    #+#             */
/*   Updated: 2023/01/07 12:21:29 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include "../includes/basic_types.h"
# include "../includes/game_types.h"
# include "../utils/utils_module.h"

void	clean_game(t_game *game);

//*		textures mandatory
void	wall_texture_clean(t_game *game);

//*		textures bonus
void	door_texture_clean(t_game *game);
void	background_texture_clean(t_game *game);
void	enemy_texture_clean(t_game *game);
void	item_texture_clean(t_game *game);
void	menu_texture_clean(t_game *game);
void	sun_texture_clean(t_game *game);

//*		memory
void	t_game_set_nulls(t_game *game);

#endif