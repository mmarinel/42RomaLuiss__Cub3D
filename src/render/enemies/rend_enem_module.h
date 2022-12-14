/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend_enem_module.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:47:05 by earendil          #+#    #+#             */
/*   Updated: 2022/12/14 14:14:19 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REND_ENEM_MODULE_H
# define REND_ENEM_MODULE_H

# include "../render_types.h"

void	update_enemy_list(
	t_list **list,
	const t_raycast_return *rc_ret,
	size_t screen_col
	);
t_list	*ft_new_rend_enem_node(
	size_t screen_col,
	const t_raycast_return *rc_ret
	);

#endif