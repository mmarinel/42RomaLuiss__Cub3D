/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:22:22 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/10 12:43:22 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

void	ft_print_2d_point(const char* pt_name, t_2d_point pt)
{
	printf("pt %s (x, y) = (%.13lf, %.13lf)", pt_name, pt.x.val, pt.y.val);
}
