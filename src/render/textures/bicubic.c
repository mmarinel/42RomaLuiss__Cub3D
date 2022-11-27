/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bicubic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:58:07 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/27 13:10:56 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

static int				bicubic(const t_data *texture_data, t_2d_point mapped);
static t_px_row			next_row(
									int row,
									t_2d_point mapped,
									const t_data *texture_data
								);
// static t_px_row			new_px_row()
//*		end of static declaration

int	bicubic_interpolation(
		const t_data *texture_data,
		const int texture_size,
		t_2d_point mapped
	)
{
	bcb_clipper(e_BCB_CLIPPER_INITIALIZE, texture_size);
	return (bicubic(texture_data, mapped));
}

static int	bicubic(const t_data *texture_data, t_2d_point mapped)
{
	const t_px_row	row_0 = next_row(
		bcb_clip(floor(mapped.y - 1)),
		mapped, texture_data
	);
	const t_px_row	row_1 = next_row(
		bcb_clip(floor(mapped.y)),
		mapped, texture_data
	);
	const t_px_row	row_2 = next_row(
		bcb_clip(ceil(mapped.y)),
		mapped, texture_data
	);
	const t_px_row	row_3 = next_row(
		bcb_clip(ceil(mapped.y + 1)),
		mapped, texture_data
	);

	return (
		cubic_interpolation(
			(t_px_row){
				(t_px){cubic_interpolation(row_0, mapped.x - floor(mapped.x))},
				(t_px){cubic_interpolation(row_1, mapped.x - floor(mapped.x))},
				(t_px){cubic_interpolation(row_2, mapped.x - floor(mapped.x))},
				(t_px){cubic_interpolation(row_3, mapped.x - floor(mapped.x))},
			},
			mapped.y - floor(mapped.y)
		)
	);
}

/**
 * @brief this function returns the next pixel row.
 * 
 * @param row 
 * @param mapped 
 * @param texture_size 
 * @return t_px_row 
 */
static t_px_row	next_row(
							int row,
							t_2d_point mapped,
							const t_data *texture_data
						)
{
	const t_int_2d_point p_row_of0_idx
			= ft_get_new_int_2dpt(
				bcb_clip(floor(mapped.x - 1)),
				bcb_clip(row)
			);
	const t_int_2d_point p_row_of1_idx
			= ft_get_new_int_2dpt(floor(mapped.x), row);
	const t_int_2d_point p_row_of2_idx
			= ft_get_new_int_2dpt(ceil(mapped.x), row);
	const t_int_2d_point p_row_of3_idx
			= ft_get_new_int_2dpt(
				bcb_clip(ceil(mapped.x + 1)),
				bcb_clip(row)
			);

	return (
		(t_px_row){
			get_texture_px(p_row_of0_idx, texture_data),
			get_texture_px(p_row_of1_idx, texture_data),
			get_texture_px(p_row_of2_idx, texture_data),
			get_texture_px(p_row_of3_idx, texture_data)
		}
	);
}
