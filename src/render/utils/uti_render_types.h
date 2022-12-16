/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uti_render_types.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:15:00 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/16 23:32:08 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTI_RENDER_TYPES_H
# define UTI_RENDER_TYPES_H

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