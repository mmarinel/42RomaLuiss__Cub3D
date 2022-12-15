/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend_enem_mem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:32:53 by earendil          #+#    #+#             */
/*   Updated: 2022/12/15 11:38:55 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rend_enem.h"

static t_bool	enemy_spotted(const void *list, const void *enemy);
//*		end of static declarations

t_list	*ft_new_rend_enem_node(
	size_t screen_col,
	const t_raycast_return *rc_ret
	)
{
	t_rendered_enemy	*data;

	data = (t_rendered_enemy *) malloc(sizeof(t_rendered_enemy));
	if (NULL == data)
		return (NULL);
	data->enemy = rc_ret->spotted_enemy.enemy;
	data->min_perp_dist = rc_ret->spotted_enemy.perp_dist;
	data->mid_screen_col = screen_col;
	data->first_screen_col = screen_col;
	data->last_screen_col = screen_col;
	return (ft_lstnew(NULL, data));
}

void	update_enemy_list(
	t_list **list,
	const t_raycast_return *rc_ret,
	size_t screen_col
	)
{
	t_list	*cur;

	if (NULL == list)
		return ;
	cur = ft_lstfind(*list, enemy_spotted, rc_ret->spotted_enemy.enemy);
	if (NULL == cur)
		ft_lstadd_back(list, ft_new_rend_enem_node(screen_col, rc_ret));
	else if (
		((t_rendered_enemy *)cur->content)\
			->min_perp_dist > rc_ret->spotted_enemy.perp_dist
	)
	{
		((t_rendered_enemy *)cur->content)->min_perp_dist
			= rc_ret->spotted_enemy.perp_dist;
		((t_rendered_enemy *)cur->content)->last_screen_col
			= screen_col;
		((t_rendered_enemy *)cur->content)->mid_screen_col
			= (
				((t_rendered_enemy *)cur->content)->first_screen_col
				+ ((t_rendered_enemy *)cur->content)->last_screen_col
			)
			/ 2.0f;
	}
}

static t_bool	enemy_spotted(const void *cur, const void *enemy)
{
	const t_rendered_enemy	*__cur = (const t_rendered_enemy *)cur;
	const t_enemy			*__enemy = (const t_enemy *)enemy;

	return (
		enemy_equals(__cur->enemy, __enemy)
	);
}
