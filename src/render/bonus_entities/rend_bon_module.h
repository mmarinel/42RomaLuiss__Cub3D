/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend_bon_module.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:24:10 by earendil          #+#    #+#             */
/*   Updated: 2023/01/07 12:06:50 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REND_BONUS_MODULE_H
# define REND_BONUS_MODULE_H

# include "../../basic_types.h"
# include "../../game_types.h"
# include "../../raycast/raycast_types.h"
# include "../render_types.h"

//*		doors
void	render_doors(
	const size_t screen_col,
	const t_raycast_return *rc_ret,
	t_game *g
	);

//*		entities (enemy and item)
void	render_entities(t_list *entities, t_game *g);
void	update_entity_list(
	t_list **list,
	const t_raycast_return *rc_ret,
	size_t screen_col
	);

#endif