/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend_enem_mem_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:32:53 by earendil          #+#    #+#             */
/*   Updated: 2022/12/25 19:38:06 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rend_bonus.h"

static t_bool	enemy_spotted(const void *list, const void *enemy);
static void		enemy_update_cols(
	t_rendered_enemy *rend_enemy, const size_t screen_col
	);
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
	t_list			*cur;
	t_rendered_enemy	*rend_enemy;

	if (NULL == rc_ret->spotted_enemy.enemy || NULL == list)
		return ;
	cur = ft_lstfind(*list, enemy_spotted, rc_ret->spotted_enemy.enemy);
	if (NULL == cur)
		ft_lstadd_back(list, ft_new_rend_enem_node(screen_col, rc_ret));
	else
	{
		rend_enemy = ((t_rendered_enemy *)cur->content);
		if (rc_ret->spotted_enemy.perp_dist < rend_enemy->min_perp_dist)
		{
			rend_enemy->min_perp_dist = rc_ret->spotted_enemy.perp_dist;
		}
		enemy_update_cols(rend_enemy, screen_col);
	}
}

static void		enemy_update_cols(
	t_rendered_enemy *rend_enemy, const size_t screen_col
	)
{
	rend_enemy->last_screen_col = screen_col;
	rend_enemy->mid_screen_col = (
			(rend_enemy->first_screen_col + rend_enemy->last_screen_col)
			/ 2.0f
		);
}

static t_bool	enemy_spotted(const void *cur, const void *enemy)
{
	const t_rendered_enemy	*__cur = (const t_rendered_enemy *)cur;
	const t_enemy			*__enemy = (const t_enemy *)enemy;

	return (
		enemy_equals(__cur->enemy, __enemy)
	);
}
