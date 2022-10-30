/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_nbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:24:27 by earendil          #+#    #+#             */
/*   Updated: 2022/10/28 08:50:53 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_nbr_base(long long num, const char *base, int base_num)
{
	if (num >= (long long) base_num)
		ft_put_nbr_base(num / base_num, base, base_num);
	ft_write(STDOUT_FILENO, &base[num % base_num]);
}
