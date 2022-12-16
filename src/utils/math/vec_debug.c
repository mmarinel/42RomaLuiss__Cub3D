/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_debug.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:50:59 by earendil          #+#    #+#             */
/*   Updated: 2022/12/16 22:51:12 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uti_math.h"

void	t_2d_point_print(const t_2d_point *pt, const char *msg)
{
	printf(YELLOW"%s: (x=%lfm y=%lf)\n" RESET, msg, pt->x, pt->y);
}
