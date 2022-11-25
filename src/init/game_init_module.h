/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init_module.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 14:27:00 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/25 15:01:18 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_INIT_MODULE_H
# define GAME_INIT_MODULE_H

# include "../types.h"

# include <unistd.h>

t_bool	ft_game_init(
			const char *path,
			t_game *game_ref,
			size_t width, size_t height
		);

# endif