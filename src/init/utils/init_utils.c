/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:25:28 by earendil          #+#    #+#             */
/*   Updated: 2023/01/13 15:57:41 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_utils.h"

static void	load_image(
				const char *path, t_data *texture_data,
				t_game *game_ref
				);
//*		end of static declarations

size_t	open_texture(
	const char *path, t_data *texture_data,
	t_game *game_ref, t_bool *err_flag
	)
{
	load_image(path, texture_data, game_ref);
	if (NULL == texture_data->img
		|| NULL == texture_data->addr
	)
		*err_flag = e_true;
	return (texture_data->width);
}

size_t	open_squared_texture(
	const char *path, t_data *texture_data,
	t_game *game_ref, t_bool *err_flag
	)
{
	load_image(path, texture_data, game_ref);
	if (NULL == texture_data->img
		|| NULL == texture_data->addr
		|| texture_data->width != texture_data->height
	)
		*err_flag = e_true;
	return (texture_data->width);
}

static void	load_image(
	const char *path, t_data *texture_data,
	t_game *game_ref
	)
{
	texture_data->img = mlx_xpm_file_to_image(
			game_ref->screen_handle.mlx,
			(char *)path,
			&texture_data->width, &texture_data->height
			);
	if (texture_data->img)
	{
		texture_data->addr = mlx_get_data_addr(
				texture_data->img,
				&texture_data->bits_per_pixel,
				&texture_data->line_length, &texture_data->endian
				);
		texture_data->loaded = e_true;
	}
	else
		texture_data->loaded = e_false;
}
