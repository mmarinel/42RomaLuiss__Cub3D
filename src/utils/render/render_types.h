/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:15:00 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/08 18:13:06 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_UTILS_TYPES_H
# define RENDER_UTILS_TYPES_H

# include "../../types.h"
# include "render_types.h"

typedef enum e_mlx_win_holder
{
	e_MLX_HOLDER_GET_MAX_OFFSET,
	e_MLX_HOLDER_SET,
}	t_mlx_win_holder;

typedef enum e_clip_opcode
{
	e_TEXTURE_CLIPPER_INITIALIZE,
	e_TEXTURE_CLIPPER_GET,
}	t_clip_opcode;

#endif