/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:21:55 by mmarinel          #+#    #+#             */
/*   Updated: 2022/01/18 15:35:43 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int n);
static void	ft_putnbr_fd_rec(unsigned int n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	if (n == -2147483648)
	{
		ft_putnbr_fd(214748364, fd);
		ft_putnbr_fd(8, fd);
	}
	else
		ft_putnbr_fd_rec(ft_abs(n), fd);
}

static void	ft_putnbr_fd_rec(unsigned int n, int fd)
{
	char	digit;

	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	digit = (n % 10) + 48;
	write(fd, &digit, 1);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
