/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_cases.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:26:30 by earendil          #+#    #+#             */
/*   Updated: 2022/11/04 11:14:29 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_case_int(int n, int *count)
{
	if (n < 0)
		pf_write("-", count);
	pf_put_nbr_base(pf_abs(n), DEC_RADIX, 10, count);
}

void	pf_case_hexa(long long n, int *count)
{
	pf_put_nbr_base(n, HEXA_RADIX, 16, count);
}

void	pf_case_str(char *str, int *count)
{
	size_t	i;

	if (!str)
		str = "(null)";
	i = 0;
	while (str[i])
		pf_write(str + i++, count);
}
