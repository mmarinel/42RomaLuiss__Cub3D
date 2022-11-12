/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fl_conditions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:24:48 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/12 10:29:23 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_fl.h"

float	t_fl_cmp(t_fl a, t_fl b)
{
	if (a.inf || b.neg_inf)
		return (1);
	if (b.inf || a.neg_inf)
		return (-1);
	return (a.val - b.val);
}
