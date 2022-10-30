/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:42:01 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/30 12:21:21 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "utils/libft/libft_module.h"

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "map_validation/gnl/get_next_line_module.h"

int main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;

	size_t	i = 0;
	// char	**split = ft_multisplit(argv[1], " V\tV", 'V');

	// exit(0);
	int		fd = open(argv[1], O_RDONLY);
	char	*line = get_next_line(fd);
	char	**split = ft_multisplit(line, " V\tV");
	// char	**split = ft_split(line, ' ');

	while (split[i]) {
		printf("split[%zu]: %s\n", i, split[i]);
		i++;
	}
	ft_splitclear(split);
	free(line);
	// char	**splittoo = ft_split("ciao pippo mario", ' ');
	// char	**splittaa = ft_split("salveAphilipASuper", 'A');
	// char	**splittii = ft_split("bonjour\vjesuis\vtriste", '\v');
	// // ft_splitprint(splittoo);
	// // ft_splitprint(splittaa);
	// char	**join = ft_splitjoin(splittii, ft_splitjoin(splittoo, splittaa, e_false, e_false), e_false, e_false);
	// // exit(0);
	// ft_splitprint(join);
	return 0;
}
//		*test	leaks --atExit -- ./cub3D "Ciao vincenzo, come stai?"