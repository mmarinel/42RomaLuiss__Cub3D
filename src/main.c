/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:42:01 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/31 11:58:09 by mmarinel         ###   ########.fr       */
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
	{
		printf( GREEN "map is ok" RESET );
		printf(
			"\n\
			no_texture: %s\n\
			so_texture: %s\n\
			we_texture: %s\n\
			ea_texture: %s\n\
			f_color.red: %d, f_color.green: %d, f_color.blue: %d f_color.alpha: %lf\n\
			c_color.red: %d, c_color.green: %d, c_color.blue: %d f_color.alpha: %lf\n\
			",
			map_handle.no_texture, map_handle.so_texture, map_handle.we_texture, map_handle.ea_texture,
			map_handle.f_color.red, map_handle.f_color.green, map_handle.f_color.blue, map_handle.f_color.alpha,
			map_handle.c_color.red, map_handle.c_color.green, map_handle.c_color.blue, map_handle.c_color.alpha
		);
	}
	else
		printf( RED "map not ok" RESET );
	free(map_handle.no_texture);
	free(map_handle.so_texture);
	free(map_handle.we_texture);
	free(map_handle.ea_texture);
	return 0;
}
//		*test	leaks --atExit -- ./cub3D "Ciao vincenzo, come stai?"