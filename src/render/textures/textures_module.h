/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_module.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:47:38 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/22 00:17:48 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "../../types.h"
# include "../../game_types.h"
# include "../render_types.h"

//*		texture scaling
int				nearest_neighbour(t_nxt_px_f_arg *nxt_px_f_arg);
size_t			get_texture_column(const t_rc_ret_data *rc_ret_data);

//*		column info data type
t_column_info	get_wall_column_info(
	size_t rendered_size,
	float gap,
	const t_raycast_return *rc_ret,
	t_game *g
	);
t_column_info	get_enemy_column_info(
	size_t resized_texture_col,
	size_t enemy_size,
	const t_rendered_enemy *enemy_data,
	t_game *g
	);
t_column_info	get_door_column_info(
	size_t rendered_size,
	float gap,
	const t_spotted_door *door_data,
	t_game *g
	);

#endif