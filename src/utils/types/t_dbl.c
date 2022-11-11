// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   t_dbl.c                                            :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2022/11/10 09:28:27 by mmarinel          #+#    #+#             */
// /*   Updated: 2022/11/11 11:15:32 by mmarinel         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "t_types.h"

// t_dbl	t_dbl_new(double val)
// {
// 	t_dbl	dbl_new;

// 	dbl_new.val = val;
// 	dbl_new.inf = e_false;
// 	dbl_new.neg_inf = e_false;
// 	return (dbl_new);
// }

// t_dbl	t_dbl_sum(t_dbl a, t_dbl b)
// {
// 	t_dbl	sum;

// 	if (a.inf || b.inf
// 		|| (a.val == __DBL_MAX__ && b.val > 0)
// 		|| (b.val == __DBL_MAX__ && a.val > 0)
// 	)
// 	{
// 		sum.inf = e_true;
// 		sum.val = 0;
// 		sum.inf = e_false;
// 		sum.neg_inf = e_false;
// 	}
// 	else
// 	{
// 		sum.val = a.val + b.val;
// 		if (a.neg_inf || b.neg_inf)
// 			sum.neg_inf = e_true;
// 	}
// 	return (sum);
// }

// t_dbl	t_dbl_diff(t_dbl a, t_dbl b)
// {
// 	t_dbl	diff;

// 	diff.val = a.val - b.val;
// 	if (a.inf || b.inf)
// 		diff.inf = e_true;
// 	if (a.neg_inf || b.neg_inf)
// 		diff.neg_inf = e_true;
// 	return (diff);
// }

// t_dbl	t_dbl_mult(t_dbl a, t_dbl b)
// {
// 	t_dbl	mult;

// 	if (a.inf || b.inf
// 		|| (a.val == __DBL_MAX__ && b.val > 0)
// 		|| (b.val == __DBL_MAX__ && a.val > 0)
// 	)
// 	{
// 		mult.inf = e_true;
// 		mult.val = 0;
// 		mult.inf = e_false;
// 		mult.neg_inf = e_false;
// 	}
// 	else
// 	{
// 		mult.val = a.val * b.val;
// 		if (a.inf || b.inf)
// 			mult.inf = e_true;
// 		if (a.neg_inf || b.neg_inf)
// 			mult.neg_inf = e_true;
// 	}
// 	return (mult);
// }

// t_dbl	t_dbl_div(t_dbl a, t_dbl b)
// {
// 	t_dbl	quotient;

// 	printf("tbl_div:\ta: %lf, b: %lf\n", a.val, b.val);
// 	if (t_dbl_equals(b.val, 0))
// 	{
// 		printf(RED "division by zero!\n" RESET);
// 			quotient.inf = e_true;
// 			quotient.neg_inf =  e_false;
// 			quotient.val = 0;
// 	// 	if(a.val < 0)
// 	// 	{
// 	// 		quotient.neg_inf = e_true;
// 	// 		quotient.inf = e_false;
// 	// 		quotient.val = -1;
// 	// 	}
// 	// 	else
// 	// 	{
			
// 	// 		quotient.inf = e_true;
// 	// 		quotient.neg_inf =  e_false;
// 	// 		quotient.val = 1;
// 	// 	}
// 	}
// 	else
// 	{
// 		printf(CYAN "division by non-zero %.24lf!\n" RESET, b.val);
// 		quotient.val = a.val / b.val;
// 		if (a.inf || b.inf)
// 			quotient.inf = e_true;
// 		if (a.neg_inf || b.neg_inf)
// 			quotient.neg_inf = e_true;
// 	}
// 	return (quotient);
// }

// double	t_dbl_cmp(t_dbl a, t_dbl b)
// {
// 	if (a.inf || b.neg_inf)
// 		return (1);
// 	if (b.inf || a.neg_inf)
// 		return (-1);
// 	return (a.val - b.val);
// }

// void	ft_print_t_dbl(t_dbl var)
// {
// 	if (var.inf)
// 		printf("<inf> ");
// 	else if (var.neg_inf)
// 		printf("<neg_inf> ");
// 	else
// 		printf("%lf ", var.val);
// }
