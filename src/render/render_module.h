/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_module.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 09:31:58 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/16 23:30:35 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_MODULE_H
# define RENDER_MODULE_H

# include "render_types.h"
# include "line_drawing/line_drawing_module.h"
# include "textures/textures_module.h"

void	render_next_frame(t_game *g);

#endif