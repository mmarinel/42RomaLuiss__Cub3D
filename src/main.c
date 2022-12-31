/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:42:01 by mmarinel          #+#    #+#             */
/*   Updated: 2022/12/31 13:30:17 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "macros.h"
# include "colors.h"

# include "types.h"
# include "game_types.h"

# include "hooks/hooks_module.h"

# include "utils/utils_module.h"
# include "init/game_init_module.h"
# include "map_validation/map_validation_module.h"
# include "map_validation/utils/map_utils_module.h"
# include "raycast/raycast_module.h"
# include "exit/exit_module.h"
# include "render/render_module.h"

# include "map_validation/utils/map_utils_module.h"

//TODO isolare in un file apposito (in ogni sorgente .h (non module) dei bonus includi gli header illegali)
int main(int argc, char const *argv[])
{
	t_game	game;

	if (2 == argc
		&& ft_game_init(argv[1], &game, SCREEN_WIDTH, SCREEN_HEIGHT))
	{
		printf( GREEN "map is ok\n" RESET );
		mlx_hook(game.screen_handle.window, KeyPress, KeyPressMask, key_press_hook, &game);
		mlx_hook(game.screen_handle.window, KeyRelease, KeyReleaseMask, key_release_hook, &game);
		mlx_hook(game.screen_handle.window, FocusOut, GenericEvent, leave_window, &game);
		mlx_hook(game.screen_handle.window, FocusIn, GenericEvent, enter_window, &game);
		mlx_hook(game.screen_handle.window, DestroyNotify, StructureNotifyMask, exit_game, &game);
		// mlx_mouse_hook(game.screen_handle.window, mouse_hook, &game);
		// mlx_do_sync(game.screen_handle.mlx);
		render_next_frame(&game);
		mlx_loop_hook(game.screen_handle.mlx, loop_hook, &game);
		mlx_loop(game.screen_handle.mlx);
			
		ft_free_map(&game.map_handle.map, game.map_handle.rows);
		free(game.map_handle.no_texture);
		free(game.map_handle.so_texture);
		free(game.map_handle.we_texture);
		free(game.map_handle.ea_texture);
	}
	else
	{
		printf( RED "map not ok\n" RESET );
		return (1);
	}
	return 0;
}
