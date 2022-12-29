/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:30:33 by earendil          #+#    #+#             */
/*   Updated: 2022/12/29 13:03:56 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../rend_bonus.h"

static void	render_door_col(
	const size_t screen_col,
	t_spotted_door *spotted_door,
	t_game *g
);
//*		end of static declarations

void	render_doors(
	const size_t screen_col,
	const t_raycast_return *rc_ret,
	t_game *g
	)
{
	t_list	*cur;

	cur = rc_ret->doors;
	while (cur)
	{
		render_door_col(screen_col, cur->content, g);
		cur = cur->next;
	}
}

static void	render_door_col(
	const size_t screen_col,
	t_spotted_door *spotted_door,
	t_game *g
)
{
	const size_t			door_size = roundf(
		g->screen_handle.height / spotted_door->rc_data.perp_dist
	);
	const float				gap = ( 
		((float)g->screen_handle.height - door_size) / 2.0f
	);
	const t_column_info		col_info = get_door_column_info(
		door_size, gap, spotted_door, g
		);
	t_int_2d_point			endpoint[2];
	
	endpoint[0] = endpoint_clip((t_int_2d_point){screen_col, gap});
	endpoint[1] = endpoint_clip((t_int_2d_point){
		screen_col, gap + (door_size - 1)
		}
	);
	if (0 == door_size)
		return ;
	else
		bresenham_plot(
			endpoint,
			&g->screen_handle.frame_data,
			nearest_neighbour, &(t_nxt_px_f_arg){&col_info, NULL}
		);
}
