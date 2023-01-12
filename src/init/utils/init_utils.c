/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:25:28 by earendil          #+#    #+#             */
/*   Updated: 2023/01/12 12:02:30 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init_utils.h"

size_t	open_texture(
	const char *path, t_data *texture_data,
	t_game *game_ref, t_bool *err_flag
	)
{
	texture_data->img = mlx_xpm_file_to_image(
			game_ref->screen_handle.mlx,
			(char *)path,
			&texture_data->width, &texture_data->height
			);
	if (texture_data->img)
			texture_data->addr = mlx_get_data_addr(
				texture_data->img,
				&texture_data->bits_per_pixel,
				&texture_data->line_length, &texture_data->endian
				);
	if (NULL == texture_data->img
		|| NULL == texture_data->addr
	)
		*err_flag = e_true;
	if (!texture_data->img || !texture_data->addr)
		printf(RED "NULL\n" RESET);
	else
		printf(GREEN "OK\n" RESET);
	printf(YELLOW "texture path:%sT\n" RESET, path);
	return (texture_data->width);
}

size_t	open_squared_texture(
	const char *path, t_data *texture_data,
	t_game *game_ref, t_bool *err_flag
	)
{
	texture_data->img = mlx_xpm_file_to_image(
			game_ref->screen_handle.mlx,
			(char *)path,
			&texture_data->width, &texture_data->height
			);
	if (texture_data->img)
		texture_data->addr = mlx_get_data_addr(
				texture_data->img,
				&texture_data->bits_per_pixel,
				&texture_data->line_length, &texture_data->endian
				);
	if (NULL == texture_data->img
		|| NULL == texture_data->addr
		|| texture_data->width != texture_data->height
	)
		*err_flag = e_true;
	if (!texture_data->img || !texture_data->addr)
		printf(RED "NULL\n" RESET);
	else
		printf(GREEN "OK\n" RESET);
	printf(YELLOW "texture path:%sT\n" RESET, path);
	return (texture_data->width);
}
