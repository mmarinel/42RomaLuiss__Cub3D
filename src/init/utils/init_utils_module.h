/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils_module.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:23:05 by earendil          #+#    #+#             */
/*   Updated: 2023/01/07 12:29:48 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_UTILS_MODULE_H
# define INIT_UTILS_MODULE_H

# include "../../includes/game_types.h"

size_t	open_squared_texture(
	const char *path, t_data *texture_data,
	t_game *game_ref, t_bool *err_flag
	);
size_t	open_texture(
	const char *path, t_data *texture_data,
	t_game *game_ref, t_bool *err_flag
	);

#endif