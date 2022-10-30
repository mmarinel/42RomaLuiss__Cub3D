/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:09:08 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/30 12:17:52 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_scroll_initial(const char **str, int *sign);
static int	ft_take_number(const char *str, int *nb, int sign,
				int *check_overflow);
static int	ft_overflow_get_value(int sign, int *check_overflow);

int	ft_atoi(const char *str)
{
	int	sign;
	int	nb;
	int	check_overflow;

	if (NULL == str)
		return (0);
	else
	{
		sign = 1;
		nb = 0;
		if (*str == '\0')
			return (0);
		ft_scroll_initial(&str, &sign);
		if (!ft_memcmp(str, "2147483648", 10) && sign == -1)
			return (-2147483648);
		check_overflow = 0;
		ft_take_number(str, &nb, sign, &check_overflow);
		return (nb * sign);
	}
}

static int	ft_take_number(const char *str, int *nb, int sign,
				int *check_overflow)
{
	int	weight;
	int	prev;

	if (*str == '\0' || *str < '0' || *str > '9')
		return (1);
	weight = ft_take_number(str + 1, nb, sign, check_overflow);
	if (!(*check_overflow))
	{
		prev = *nb;
		*nb += (*str - 48) * weight;
		if (*nb < prev)
			*nb = ft_overflow_get_value(sign, check_overflow);
	}
	return (10 * weight);
}

void	ft_scroll_initial(const char **str, int *sign)
{
	while ((**str >= 9 && **str <= 13) || **str == 32)
		*str = *str + 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			*sign *= -1;
		*str = *str + 1;
	}
}

static int	ft_overflow_get_value(int sign, int *check_overflow)
{
	*check_overflow = 1;
	if (sign == -1)
		return (0);
	return (-1);
}
