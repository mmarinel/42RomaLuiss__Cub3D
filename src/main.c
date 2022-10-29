/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:42:01 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/29 13:36:09 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "utils/libft/libft.h"

# include <stdio.h>
# include <unistd.h>

int main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;

	size_t	i = 0;
	char	**split = ft_multisplit(argv[1], " a\tava", 'a');

	exit(0);
	while (split[i]) {
		printf("argv[%zu]: %s\n", i, split[i]);
		i++;
	}
	return 0;
}
