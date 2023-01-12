/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_border_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:48:07 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 15:31:28 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../render.h"

static void	draw_border_frame(
				t_int_2d_point first,
				t_int_2d_point last,
				t_game *g
				);
static void	set_border_increments(
				const t_int_2d_point *first,
				const t_int_2d_point *last,
				int *x_increment, int *y_increment
				);
static int	mmp_border_next_px(t_nxt_px_f_arg *farg);
//*		end of static declarations

void	mmp_border_draw_horizontal_frames(
	const t_int_2d_point *mmp_start, t_game *g
	)
{
	const t_int_2d_point	bottom_left = (t_int_2d_point){
		mmp_start->x - MMP_BORDER_WIDTH,
		mmp_start->y
	};
	const t_int_2d_point	bottom_right = (t_int_2d_point){
		mmp_start->x + MMP_WIDTH + MMP_BORDER_WIDTH - 1,
		mmp_start->y
	};
	const t_int_2d_point	top_left = (t_int_2d_point){
		mmp_start->x - MMP_BORDER_WIDTH,
		mmp_start->y - MMP_HEIGHT - MMP_BORDER_WIDTH + 1
	};
	const t_int_2d_point	top_right = (t_int_2d_point){
		mmp_start->x + MMP_WIDTH + MMP_BORDER_WIDTH - 1,
		mmp_start->y - MMP_HEIGHT - MMP_BORDER_WIDTH + 1
	};

	draw_border_frame(top_left, top_right, g);
	draw_border_frame(bottom_left, bottom_right, g);
}

void	mmp_border_draw_vertical_frames(
	const t_int_2d_point *mmp_start, t_game *g
	)
{
	const t_int_2d_point	bottom_left = (t_int_2d_point){
		mmp_start->x - MMP_BORDER_WIDTH,
		mmp_start->y
	};
	const t_int_2d_point	bottom_right = (t_int_2d_point){
		mmp_start->x + MMP_WIDTH + MMP_BORDER_WIDTH - 1,
		mmp_start->y
	};
	const t_int_2d_point	top_left = (t_int_2d_point){
		mmp_start->x - MMP_BORDER_WIDTH,
		mmp_start->y - MMP_HEIGHT - MMP_BORDER_WIDTH + 1
	};
	const t_int_2d_point	top_right = (t_int_2d_point){
		mmp_start->x + MMP_WIDTH + MMP_BORDER_WIDTH - 1,
		mmp_start->y - MMP_HEIGHT - MMP_BORDER_WIDTH + 1
	};

	draw_border_frame(bottom_left, top_left, g);
	draw_border_frame(bottom_right, top_right, g);
}

static void	draw_border_frame(
	t_int_2d_point first,
	t_int_2d_point last,
	t_game *g
	)
{
	const t_color	border_col = (t_color){76, 79, 168, 1};
	int				x_increment;
	int				y_increment;
	int				i;

	set_border_increments(&first, &last, &x_increment, &y_increment);
	i = 0;
	while (i < MMP_BORDER_WIDTH)
	{
		bresenham_plot(
			(t_int_2d_point[2]){first, last},
			&g->screen_handle.frame_data,
			mmp_border_next_px,
			&(t_nxt_px_f_arg){&border_col, NULL}
			);
		first.x += x_increment;
		first.y += y_increment;
		last.x += x_increment;
		last.y += y_increment;
		i++;
	}
}

static void	set_border_increments(
	const t_int_2d_point *first,
	const t_int_2d_point *last,
	int *x_increment, int *y_increment
	)
{
	if (first->x == last->x)
	{
		*x_increment = +1;
		*y_increment = 0;
	}
	else
	{
		*x_increment = 0;
		*y_increment = +1;
	}
}

static int	mmp_border_next_px(t_nxt_px_f_arg *farg)
{
	return (
		*((int *)farg->arg)
	);
}
