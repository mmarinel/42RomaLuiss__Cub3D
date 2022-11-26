/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bicubic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:58:07 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/26 16:46:58 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

static int				row_interpolation(
							int row_index,
							int col[4],
							int x,
							const t_data *img_data
						);
static int				get_texture_px(int x, int y, const t_data *img_data);
static int				bc_clip(int coordinate, int max_size);
static t_px_row			next_row(
									int row_index,
									t_2d_point position,
									const int texture_size
								);
//*		end of static declaration

int	bicubic_interpolation(
		const t_data *img_data,
		const int texture_size,
		t_2d_point position
	)
{
	const t_px_row	row_0[4] = next_row(0, position, texture_size);
	const t_px_row	row_1[4] = next_row(1, position, texture_size);
	const t_px_row	row_2[4] = next_row(2, position, texture_size);
	const t_px_row	row_3[4] = next_row(3, position, texture_size);

	bicubic(
		bicubic(row_0, position.x),
		bicubic(row_1, position.x),
		bicubic(row_2, position.x),
		bicubic(row_3, position.x),
		position.y
	);
}

static int	row_interpolation(
	int row_index,
	int col[4],
	int x,
	const t_data *img_data
)
{
	int		px[4] = {
		get_texture_px(col[0], row_index, img_data),
		get_texture_px(col[1], row_index, img_data),
		get_texture_px(col[2], row_index, img_data),
		get_texture_px(col[3], row_index, img_data),
	};
	char	*byte_ptr;

	byte_ptr = img_data->addr + ft_get_pixel_offset(*img_data, ft_get_new_int_2dpt(col[0], row_index));
	int	pixel = *(unsigned int *)byte_ptr;
}

static int	get_texture_px(int x, int y, const t_data *img_data)
{
}

static int	bc_clip(int coordinate, int max_size)
{
	if (coordinate < 0)
		return (0);
	if (coordinate > max_size)
		return (max_size - 1);
}


/**
 * @brief this function returns the next pixel row.
 * 
 * @param row_index 
 * @param position 
 * @param texture_size 
 * @return t_px_row 
 */
static t_px_row	next_row(
							int row_index,
							t_2d_point position,
							const int texture_size
						)
{
	const t_int_2d_point c0
			= ft_get_new_int_2dpt(
				bc_clip(position.x - 1, texture_size),
				bc_clip(row_index, texture_size)
			);
	const t_int_2d_point c1
			= ft_get_new_int_2dpt(
				bc_clip(position.x, texture_size),
				bc_clip(row_index, texture_size)
			);
	const t_int_2d_point c2
			= ft_get_new_int_2dpt(
				bc_clip(position.x + 1, texture_size),
				bc_clip(row_index, texture_size)
			);
	const t_int_2d_point c3
			= ft_get_new_int_2dpt(
				bc_clip(position.x + 2, texture_size),
				bc_clip(row_index, texture_size)
			);
	return ((t_px_row){c0, c1, c2, c3});
}











