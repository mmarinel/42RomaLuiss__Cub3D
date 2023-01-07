/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_module.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:27:00 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/07 12:27:53 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_INIT_MODULE_H
# define GAME_INIT_MODULE_H

# include "../includes/basic_types.h"
# include "../includes/game_types.h"
# include "../utils/utils_module.h"

# include "../includes/sys_includes.h"

t_bool	ft_game_init(
			const char *map_path,
			t_game *game_ref,
			size_t width, size_t height
		);
void	t_game_init(t_game *game_ref);

# endif