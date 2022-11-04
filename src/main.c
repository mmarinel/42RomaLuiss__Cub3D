/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:42:01 by mmarinel          #+#    #+#             */
/*   Updated: 2022/11/04 09:26:35 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// # include "utils/libft/libft_module.h"

# include "colors.h"
# include "types.h"
# include "utils/utils_module.h"
# include "map_validation/map_validation_module.h"
// # include "utils/gnl/get_next_line_module.h"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int main(int argc, char const *argv[])
{
	(void) argc;
	(void) argv;

	t_game			game;

	ft_game_init(&game);
	if (is_valid_map(argv[1], &game.map_handle))
	{
		printf( GREEN "map is ok\n" RESET );
		printf(
			"\n\
			no_texture: %s\n\
			so_texture: %s\n\
			we_texture: %s\n\
			ea_texture: %s\n\
			f_color.red: %d, f_color.green: %d, f_color.blue: %d f_color.alpha: %lf\n\
			c_color.red: %d, c_color.green: %d, c_color.blue: %d f_color.alpha: %lf\n\
			",
			game.map_handle.no_texture, game.map_handle.so_texture, game.map_handle.we_texture, game.map_handle.ea_texture,
			game.map_handle.f_color.red, game.map_handle.f_color.green, game.map_handle.f_color.blue, game.map_handle.f_color.alpha,
			game.map_handle.c_color.red, game.map_handle.c_color.green, game.map_handle.c_color.blue, game.map_handle.c_color.alpha
		);
	}
	else
		printf( RED "map not ok\n" RESET );
	ft_free_map(&game.map_handle.map, game.map_handle.rows);
	free(game.map_handle.no_texture);
	free(game.map_handle.so_texture);
	free(game.map_handle.we_texture);
	free(game.map_handle.ea_texture);

	ft_printf(YELLOW "\n\n.......leaks program output......\n\n" RESET);
	return 0;
}
//		*test	leaks --atExit -- ./cub3D "Ciao vincenzo, come stai?"