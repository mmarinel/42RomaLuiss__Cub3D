/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:47:10 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/12 15:56:13 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "../../includes/basic_types.h"
# include "../../includes/game_types.h"
# include "../render_types.h"

# include "../../utils/utils_module.h"
# include "../utils/uti_render_module.h"

# include "../../includes/sys_includes.h"

t_data	*get_wall_texture(t_game *game, const t_rc_ret_data *rc_ret_data);
size_t	get_texture_column(const t_rc_ret_data *rc_ret_data);

#endif