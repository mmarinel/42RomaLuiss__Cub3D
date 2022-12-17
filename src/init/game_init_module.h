/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_module.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:27:00 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/17 11:42:40 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_INIT_MODULE_H
# define GAME_INIT_MODULE_H

# include "../types.h"
# include "../game_types.h"
# include "../utils/utils_module.h"
# include "../sys_includes.h"

t_bool	ft_game_init(
			const char *map_path,
			t_game *game_ref,
			size_t width, size_t height
		);

# endif