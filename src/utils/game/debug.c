/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:22:22 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/06 19:12:58 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

void	ft_print_2d_point(const char* pt_name, t_2d_point pt)
{
	printf(YELLOW "pt %s (x, y) = (%.2lf, %.2lf)\n" RESET, pt_name, pt.x, pt.y);
}
