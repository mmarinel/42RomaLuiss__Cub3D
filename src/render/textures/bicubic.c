/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bicubic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:58:07 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/27 20:16:35 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "textures.h"

static int	linear(int p0, int p1, float place);
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
	// (void)texture_size;
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

	(void)next_row;
	(void)linear;
	(void)row_0;
	(void)row_1;
	(void)row_2;
	(void)row_3;
	//*								NEAREST NEIGHBOUR
	return (
		get_texture_px( (t_int_2d_point){bcb_clip(roundf(mapped.x)), bcb_clip(roundf(mapped.y))}, texture_data).rgb
	);
	//*								BILINEAR
	// return (
	// 	linear(
	// 		linear(
	// 			get_texture_px(
	// 				ft_get_new_int_2dpt(
	// 					floor(mapped.x), floor(mapped.y)
	// 				),
	// 				texture_data
	// 			).rgb,
	// 			get_texture_px(
	// 				ft_get_new_int_2dpt(
	// 					bcb_clip(ceil(mapped.x)), floor(mapped.y)
	// 				),
	// 				texture_data
	// 			).rgb,
	// 			mapped.x - floor(mapped.x)
	// 		),
	// 		linear(
	// 			get_texture_px(
	// 				ft_get_new_int_2dpt(
	// 					floor(mapped.x), bcb_clip(ceil(mapped.y))
	// 				),
	// 				texture_data
	// 			).rgb,
	// 			get_texture_px(
	// 				ft_get_new_int_2dpt(
	// 					bcb_clip(ceil(mapped.x)), bcb_clip(ceil(mapped.y))
	// 				),
	// 				texture_data
	// 			).rgb,
	// 			mapped.x - floor(mapped.x)
	// 		),
	// 		mapped.y - floor(mapped.y)
	// 	)
	// );
	//*			BICUBIC
	// return (
	// 	cubic_interpolation(
	// 		(t_px_row){
	// 			(t_px){cubic_interpolation(row_0, mapped.x - floor(mapped.x))},
	// 			(t_px){cubic_interpolation(row_1, mapped.x - floor(mapped.x))},
	// 			(t_px){cubic_interpolation(row_2, mapped.x - floor(mapped.x))},
	// 			(t_px){cubic_interpolation(row_3, mapped.x - floor(mapped.x))},
	// 		},
	// 		mapped.y - floor(mapped.y)
	// 	)
	// );
}

// static int	linear(const t_data *texture_data, float mapped_x, int row)
// {
// 	return (
// 		(float)get_texture_px(
// 			(t_int_2d_point){floor(mapped_x), row},
// 			texture_data
// 		).rgb * ((float)1 - ft_flt_abs(mapped_x - floor(mapped_x)))
// 		+ (float)get_texture_px(
// 			(t_int_2d_point){ceil(mapped_x), row},
// 			texture_data
// 		).rgb * ((float)1 - ft_flt_abs(mapped_x - ceil(mapped_x)))
// 	);
// }

static int	linear(int p0, int p1, float place)
{
	return (
		(float)p0 * ((float)1 - ft_flt_abs(place - floor(place)))
		+ (float)p1 * ((float)1 - ft_flt_abs(place - ceil(place)))
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
			= ft_get_new_int_2dpt(bcb_clip(floor(mapped.x)), row);
	const t_int_2d_point p_row_of2_idx
			= ft_get_new_int_2dpt(bcb_clip(ceil(mapped.x)), row);
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
