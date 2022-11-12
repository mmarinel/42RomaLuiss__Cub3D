/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_fl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:28:27 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/12 10:43:41 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "t_fl.h"

t_fl	t_fl_new(float val)
{
	t_fl	fl_new;

	fl_new.val = val;
	fl_new.inf = e_false;
	fl_new.neg_inf = e_false;
	return (fl_new);
}

void	ft_print_t_fl(t_fl var)
{
	if (var.inf)
		printf("<inf> ");
	else if (var.neg_inf)
		printf("<neg_inf> ");
	else
		printf("%lf ", var.val);
}

t_fl	t_fl_abs(t_fl fl)
{
	t_fl	abs;

	if (fl.inf || fl.neg_inf)
	{
		abs.inf = e_true;
		abs.neg_inf = e_false;
		abs.val = 0;
	}
	else
	{
		abs.val = ft_flt_abs(fl.val);
		abs.inf = e_false;
		abs.neg_inf = e_false;
	}
	return (abs);
}
