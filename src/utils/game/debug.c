/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazzari <alazzari@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 18:22:22 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/12 13:02:55 by alazzari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_utils.h"

void	ft_print_2d_point(const char *pt_name, t_2d_point pt)
{
	printf("pt %s (x, y) = (%.13lf, %.13lf)\n", pt_name, pt.x, pt.y);
}

void	ft_print_int_2d_point(const char *pt_name, t_int_2d_point pt)
{
	printf("pt %s (x, y) = (%d, %d)\n", pt_name, pt.x, pt.y);
}
