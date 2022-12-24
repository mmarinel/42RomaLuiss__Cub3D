/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend_bonus_module.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:24:10 by earendil          #+#    #+#             */
/*   Updated: 2022/12/24 20:46:21 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REND_BONUS_MODULE_H
# define REND_BONUS_MODULE_H

# include "../../types.h"
# include "../../game_types.h"
# include "../../raycast/raycast_types.h"
# include "../render_types.h"

//*		doors
void	render_doors(
	const size_t screen_col,
	const t_raycast_return *rc_ret,
	t_game *g
	);

//*		enemies
void	render_enemies(
	t_list *enemies,
	t_game *g
	);
void	update_enemy_list(
	t_list **list,
	const t_raycast_return *rc_ret,
	size_t screen_col
	);
t_list	*ft_new_rend_enem_node(
	size_t screen_col,
	const t_raycast_return *rc_ret
	);

//*		items
void	update_item_list(
	t_list **list,
	const t_raycast_return *rc_ret,
	size_t screen_col
	);
t_list	*ft_new_rend_item_node(
	size_t screen_col,
	const t_raycast_return *rc_ret
	);

#endif