/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earendil <earendil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 15:42:01 by mmarinel          #+#    #+#             */
/*   Updated: 2023/01/07 12:20:35 by earendil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/sys_includes.h"

# include "includes/macros.h"
# include "includes/colors.h"

# include "includes/basic_types.h"
# include "includes/game_types.h"

# include "init/game_init_module.h"
# include "hooks/hooks_module.h"
# include "exit/exit_module.h"

# include "utils/utils_module.h"

static void	set_hooks(void *mlx, void *window, t_game *game);
//*		end of static declarations

//TODO isolare in un file apposito (in ogni sorgente .h (non module) dei bonus includi gli header illegali)
int main(int argc, char const *argv[])
{
	t_game	game;

	t_game_init(&game);
	if (2 == argc
		&& ft_game_init(argv[1], &game, SCREEN_WIDTH, SCREEN_HEIGHT))
	{
		ft_printf( BOLDGREEN "map is ok\n" RESET );
		set_hooks(game.screen_handle.mlx, game.screen_handle.window, &game);
		mlx_loop(game.screen_handle.mlx);
		return (0);
	}
	else
	{
		ft_printf( BOLDRED "map not ok or args error\n" RESET );
		clean_game(&game);
		return (1);
	}
}

static void	set_hooks(void *mlx, void *window, t_game *game)
{
	mlx_hook(window, KeyPress, KeyPressMask, key_press_hook, game);
	mlx_hook(window, KeyRelease, KeyReleaseMask, key_release_hook, game);
	mlx_hook(window, FocusOut, GenericEvent, leave_window, game);
	mlx_hook(window, FocusIn, GenericEvent, enter_window, game);
	mlx_hook(window, DestroyNotify, StructureNotifyMask, exit_game, game);
	if (BONUS)
		mlx_mouse_hook(window, mouse_click_hook, game);
	mlx_loop_hook(mlx, loop_hook, game);
}
