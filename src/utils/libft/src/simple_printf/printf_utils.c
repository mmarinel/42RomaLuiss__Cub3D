/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:45:34 by earendil          #+#    #+#             */
/*   Updated: 2022/11/04 11:14:56 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_write(const char *c, int *count)
{
	write(STDOUT_FILENO, c, sizeof(char));
	*count = *count + 1;
}

void	pf_put_nbr_base(long long num, const char *base,
			int base_num, int *count)
{
	if (num >= (long long) base_num)
		pf_put_nbr_base(num / base_num, base, base_num, count);
	pf_write(&base[num % base_num], count);
}

unsigned long long	pf_abs(long long nbr)
{
	if (nbr < 0)
		return (nbr * -1);
	return (nbr);
}
