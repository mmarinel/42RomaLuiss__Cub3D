/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:45:56 by earendil          #+#    #+#             */
/*   Updated: 2022/10/26 18:54:24 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define DEC_RADIX "0123456789"
# define HEXA_RADIX "0123456789abcdef"

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

//* user defined exposed functions
int		ft_printf(const char *format_string, ...);

//* printf cases
void	pf_case_str(char *str, int *count);
void	pf_case_int(int n, int *count);
void	pf_case_hexa(long long n, int *count);

//* printf writer
void	pf_write(const char *c, int *count);

#endif