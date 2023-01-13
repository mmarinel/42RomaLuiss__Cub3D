/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:06:08 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/13 15:49:18 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_render.h"

int	ft_mlx_destroy_image(void *mlx_ptr, t_data *img_data)
{
	if (e_false == img_data->loaded)
		return (1);
	else
		return (mlx_destroy_image(mlx_ptr, img_data->img));
}
