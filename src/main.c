/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:42:01 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/31 10:08:24 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # include "utils/libft/libft_module.h"

# include "colors.h"
# include "types.h"
# include "map_validation/map_validation_module.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "utils/gnl/get_next_line_module.h"

int main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;

	t_map_holder	map_handle;

	map_handle.no_texture = NULL;
	map_handle.so_texture = NULL;
	map_handle.we_texture = NULL;
	map_handle.ea_texture = NULL;
	map_handle.c_color.alpha = -1;
	map_handle.f_color.alpha = -1;

	// int		fd = open(argv[1], O_RDONLY);
	if (is_valid_map(argv[1], &map_handle))
		printf( GREEN "map is ok" RESET );
	else
		printf( RED "map not ok" RESET );
	free(map_handle.no_texture);
	free(map_handle.so_texture);
	free(map_handle.we_texture);
	free(map_handle.ea_texture);
	return 0;
}
//		*test	leaks --atExit -- ./cub3D "Ciao vincenzo, come stai?"