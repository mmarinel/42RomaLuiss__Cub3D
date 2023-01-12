/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_bon_module.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:12:18 by alazzari          #+#    #+#             */
/*   Updated: 2023/01/12 11:14:11 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_INIT_BON_MODULE_H
# define GAME_INIT_BON_MODULE_H

# include "../../includes/game_types.h"

//*		textures
void	load_bonus_textures(t_game *game_ref, t_bool *err_flag);

//*		entities lists
void	scan_enemies(t_game *game_ref);
void	scan_items(t_game *game_ref);
void	scan_doors(t_game *game_ref);

//*		others
void	set_rand(void);

#endif