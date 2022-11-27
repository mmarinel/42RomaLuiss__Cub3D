/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:47:10 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/27 13:15:45 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include "texture_types.h"
# include "../../types.h"
# include "../../colors.h"
# include "../../utils/utils_module.h"

# include <math.h>

//*		cubic_interpolation
int	cubic_interpolation(t_px_row row, int x);

//*		textures manipulation
t_px	get_texture_px(t_int_2d_point coordinate, const t_data *texture_data);

//*		initialization
int		bcb_clipper(t_clip_opcode opcode, size_t size);
size_t	bcb_clip(int coordinate);

#endif