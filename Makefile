# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: earendil <earendil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 19:06:19 by earendil          #+#    #+#              #
#    Updated: 2023/01/07 12:14:35 by earendil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES=\
./src/colors.h\
./src/game_types.h\
./src/macros.h\
./src/sys_includes.h\
./src/basic_types.h\
./src/X11_macros.h\
./src/utils/gnl/get_next_line_module.h\
./src/utils/libft/libft_module.h\
./src/utils/render/utils_render_module.h\
./src/utils/game/game_utils_module.h\
./src/utils/simple_printf/ft_printf_module.h\
./src/utils/utils_module.h\
./src/utils/math/uti_math_module.h\
./src/init/utils/init_utils_module.h\
./src/init/game_init_module.h\
./src/init/bonus/game_init_bon_module.h\
./src/hooks/in_game_loop/mouse/in_game_mouse_module.h\
./src/hooks/in_game_loop/loops/in_game_loops_module.h\
./src/hooks/in_game_loop/in_game_loop_module.h\
./src/hooks/in_game_loop/keys/utils/in_game_key_utils_module.h\
./src/hooks/in_game_loop/keys/in_game_keys_module.h\
./src/hooks/in_game_loop/keys/bonus/in_game_keys_bon_module.h\
./src/hooks/hooks_module.h\
./src/hooks/in_menus_loop/in_menu_loop_module.h\
./src/exit/exit_module.h\
./src/map_validation/utils/map_utils_module.h\
./src/map_validation/map_validation_module.h\
./src/map_validation/bonus/map_validation_bon_module.h\
./src/render/textures/textures_module.h\
./src/render/utils/uti_render_module.h\
./src/render/line_drawing/line_drawing_module.h\
./src/render/bonus_entities/rend_bon_module.h\
./src/render/render_module.h\
./src/raycast/utils/rc_utils_module.h\
./src/raycast/bonus/rc_bon_module.h\
./src/raycast/raycast_module.h\
./src/exit/exit.h\
./src/exit/exit_module.h\
./src/hooks/hooks.h\
./src/hooks/hooks_module.h\
./src/hooks/in_game_loop/in_game_loop.h\
./src/hooks/in_game_loop/in_game_loop_module.h\
./src/hooks/in_game_loop/keys/in_game_keys.h\
./src/hooks/in_game_loop/keys/in_game_keys_module.h\
./src/hooks/in_game_loop/keys/bonus/in_game_keys_bon_module.h\
./src/hooks/in_game_loop/keys/utils/in_game_key_utils.h\
./src/hooks/in_game_loop/keys/utils/in_game_key_utils_module.h\
./src/hooks/in_game_loop/loops/in_game_loops_module.h\
./src/hooks/in_game_loop/mouse/in_game_mouse_module.h\
./src/hooks/in_menus_loop/in_menu_loop_module.h\
./src/init/game_init.h\
./src/init/game_init_module.h\
./src/init/bonus/game_init_bon_module.h\
./src/init/utils/init_utils.h\
./src/init/utils/init_utils_module.h\
./src/map_validation/map_validation.h\
./src/map_validation/map_validation_module.h\
./src/map_validation/map_validation_types.h\
./src/map_validation/bonus/map_validation_bon_module.h\
./src/map_validation/utils/map_utils.h\
./src/map_validation/utils/map_utils_module.h\
./src/raycast/raycast.h\
./src/raycast/raycast_module.h\
./src/raycast/raycast_types.h\
./src/raycast/bonus/rc_bon_module.h\
./src/raycast/utils/rc_utils.h\
./src/raycast/utils/rc_utils_module.h\
./src/render/render.h\
./src/render/render_module.h\
./src/render/render_types.h\
./src/render/bonus_entities/rend_bon_module.h\
./src/render/line_drawing/line_drawing.h\
./src/render/line_drawing/line_drawing_module.h\
./src/render/line_drawing/line_drawing_types.h\
./src/render/textures/textures.h\
./src/render/textures/textures_module.h\
./src/render/utils/uti_render.h\
./src/render/utils/uti_render_module.h\
./src/utils/utils_module.h\
./src/utils/game/game_utils.h\
./src/utils/game/game_utils_module.h\
./src/utils/gnl/get_next_line.h\
./src/utils/gnl/get_next_line_module.h\
./src/utils/math/uti_math.h\
./src/utils/math/uti_math_module.h\
./src/utils/math/uti_math_types.h\
./src/utils/render/utils_render.h\
./src/utils/render/utils_render_module.h\
./src/utils/render/utils_render_types.h\
./src/utils/simple_printf/ft_printf.h\
./src/utils/simple_printf/ft_printf_module.h\

SRC_NOPREFIX=\
./src/main.c\
./src/exit/exit.c\
./src/exit/exit_utils.c\
./src/exit/textures_clean.c\
./src/hooks/keys_hook.c\
./src/hooks/loop_hook.c\
./src/hooks/win_focus_hooks.c\
./src/hooks/in_game_loop/in_game_loop.c\
./src/hooks/in_game_loop/keys/in_game_keys.c\
./src/hooks/in_game_loop/keys/movement_key.c\
./src/hooks/in_game_loop/keys/rotation_key.c\
./src/hooks/in_game_loop/keys/utils/player_movement.c\
./src/init/game_initialization.c\
./src/init/game/t_game_init.c\
./src/init/geometry/init_geometry.c\
./src/init/keys_init/keys_init.c\
./src/init/map_init/map_init.c\
./src/init/map_init/map_reset.c\
./src/init/menus_init/menus_init.c\
./src/init/mlx_init/mlx_init.c\
./src/init/textures/init_textures.c\
./src/init/textures/load_textures.c\
./src/init/utils/init_utils.c\
./src/map_validation/map_attributes.c\
./src/map_validation/map_content.c\
./src/map_validation/map_read.c\
./src/map_validation/validate.c\
./src/map_validation/utils/attrs.c\
./src/map_validation/utils/atttrs_chars_conditions.c\
./src/map_validation/utils/map_chars_tracking.c\
./src/map_validation/utils/map_logic_conditions.c\
./src/map_validation/utils/map_memory.c\
./src/map_validation/utils/t_tile_debug.c\
./src/map_validation/utils/t_tile_map_trim.c\
./src/raycast/raycast_algorithm.c\
./src/raycast/raycast.c\
./src/raycast/raycast_memory.c\
./src/raycast/raycast_movement.c\
./src/raycast/raycast_wall.c\
./src/raycast/utils/rc_calc.c\
./src/raycast/utils/rc_debug.c\
./src/raycast/utils/rc_initialization.c\
./src/raycast/utils/rc_set.c\
./src/raycast/utils/rc_walk.c\
./src/render/render.c\
./src/render/render_game.c\
./src/render/render_memory.c\
./src/render/background/background.c\
./src/render/line_drawing/bres_backup.c\
./src/render/line_drawing/bres_decision_var.c\
./src/render/line_drawing/bres_endpoints.c\
./src/render/line_drawing/bresenham.c\
./src/render/line_drawing/bres_logic.c\
./src/render/textures/nearest_neighbour.c\
./src/render/textures/wall.c\
./src/render/utils/render_clipping.c\
./src/utils/game/debug.c\
./src/utils/game/game_player.c\
./src/utils/game/keys_conditions.c\
./src/utils/game/map_chars_conditions.c\
./src/utils/game/map_utils.c\
./src/utils/gnl/get_next_line.c\
./src/utils/gnl/get_next_line_nonl.c\
./src/utils/gnl/get_next_line_utils.c\
./src/utils/math/flt_math.c\
./src/utils/math/geometry.c\
./src/utils/math/vec_cmp.c\
./src/utils/math/vec_debug.c\
./src/utils/math/vec_manip.c\
./src/utils/math/vec_memory.c\
./src/utils/math/vectorial_ops.c\
./src/utils/math/vec_to_vec_ops.c\
./src/utils/render/mlx_holder.c\
./src/utils/render/mlx_utils_imgs.c\
./src/utils/render/rgb.c\
./src/utils/render/squared_texture_clipper.c\
./src/utils/simple_printf/ft_printf.c\
./src/utils/simple_printf/printf_cases.c\
./src/utils/simple_printf/printf_utils.c\

INCLUDES_BONUS=\
./src/colors.h\
./src/game_types.h\
./src/macros.h\
./src/sys_includes_bonus.h\
./src/sys_includes.h\
./src/basic_types.h\
./src/X11_macros.h\
./src/utils/gnl/get_next_line_module.h\
./src/utils/libft/libft_module.h\
./src/utils/render/utils_render_module.h\
./src/utils/game/game_utils_module.h\
./src/utils/simple_printf/ft_printf_module.h\
./src/utils/utils_module.h\
./src/utils/math/uti_math_module.h\
./src/init/utils/init_utils_module.h\
./src/init/game_init_module.h\
./src/init/bonus/game_init_bon_module.h\
./src/hooks/in_game_loop/mouse/in_game_mouse_module.h\
./src/hooks/in_game_loop/loops/in_game_loops_module.h\
./src/hooks/in_game_loop/in_game_loop_module.h\
./src/hooks/in_game_loop/keys/utils/in_game_key_utils_module.h\
./src/hooks/in_game_loop/keys/in_game_keys_module.h\
./src/hooks/in_game_loop/keys/bonus/in_game_keys_bon_module.h\
./src/hooks/hooks_module.h\
./src/hooks/in_menus_loop/in_menu_loop_module.h\
./src/exit/exit_module.h\
./src/map_validation/utils/map_utils_module.h\
./src/map_validation/map_validation_module.h\
./src/map_validation/bonus/map_validation_bon_module.h\
./src/render/textures/textures_module.h\
./src/render/utils/uti_render_module.h\
./src/render/line_drawing/line_drawing_module.h\
./src/render/bonus_entities/rend_bon_module.h\
./src/render/render_module.h\
./src/raycast/utils/rc_utils_module.h\
./src/raycast/bonus/rc_bon_module.h\
./src/raycast/raycast_module.h\
./src/exit/exit.h\
./src/exit/exit_module.h\
./src/hooks/hooks.h\
./src/hooks/hooks_module.h\
./src/hooks/in_game_loop/in_game_loop.h\
./src/hooks/in_game_loop/in_game_loop_module.h\
./src/hooks/in_game_loop/keys/in_game_keys.h\
./src/hooks/in_game_loop/keys/in_game_keys_module.h\
./src/hooks/in_game_loop/keys/bonus/in_game_keys_bon_module.h\
./src/hooks/in_game_loop/keys/bonus/in_game_keys_bonus.h\
./src/hooks/in_game_loop/keys/utils/in_game_key_utils.h\
./src/hooks/in_game_loop/keys/utils/in_game_key_utils_module.h\
./src/hooks/in_game_loop/loops/in_game_loops_bonus.h\
./src/hooks/in_game_loop/loops/in_game_loops_module.h\
./src/hooks/in_game_loop/mouse/in_game_mouse_bonus.h\
./src/hooks/in_game_loop/mouse/in_game_mouse_module.h\
./src/hooks/in_menus_loop/in_menu_loop_bonus.h\
./src/hooks/in_menus_loop/in_menu_loop_module.h\
./src/init/game_init.h\
./src/init/game_init_module.h\
./src/init/bonus/game_init_bon_module.h\
./src/init/bonus/game_init_bonus.h\
./src/init/utils/init_utils.h\
./src/init/utils/init_utils_module.h\
./src/map_validation/map_validation.h\
./src/map_validation/map_validation_module.h\
./src/map_validation/map_validation_types.h\
./src/map_validation/bonus/map_validation_bon_module.h\
./src/map_validation/bonus/map_validation_bonus.h\
./src/map_validation/utils/map_utils.h\
./src/map_validation/utils/map_utils_module.h\
./src/raycast/raycast.h\
./src/raycast/raycast_module.h\
./src/raycast/raycast_types.h\
./src/raycast/bonus/rc_bon_module.h\
./src/raycast/bonus/rc_bonus.h\
./src/raycast/utils/rc_utils.h\
./src/raycast/utils/rc_utils_module.h\
./src/render/render.h\
./src/render/render_module.h\
./src/render/render_types.h\
./src/render/bonus_entities/rend_bon_module.h\
./src/render/bonus_entities/rend_bonus.h\
./src/render/line_drawing/line_drawing.h\
./src/render/line_drawing/line_drawing_module.h\
./src/render/line_drawing/line_drawing_types.h\
./src/render/textures/textures.h\
./src/render/textures/textures_module.h\
./src/render/utils/uti_render.h\
./src/render/utils/uti_render_module.h\
./src/utils/utils_module.h\
./src/utils/game/game_utils.h\
./src/utils/game/game_utils_module.h\
./src/utils/gnl/get_next_line.h\
./src/utils/gnl/get_next_line_module.h\
./src/utils/math/uti_math.h\
./src/utils/math/uti_math_module.h\
./src/utils/math/uti_math_types.h\
./src/utils/render/utils_render.h\
./src/utils/render/utils_render_module.h\
./src/utils/render/utils_render_types.h\
./src/utils/simple_printf/ft_printf.h\
./src/utils/simple_printf/ft_printf_module.h\

SRC_NOPREFIX_BONUS=\
./src/main.c\
./src/exit/exit.c\
./src/exit/exit_utils.c\
./src/exit/sun_textures_bonus.c\
./src/exit/textures_clean_bonus.c\
./src/exit/textures_clean.c\
./src/hooks/keys_hook.c\
./src/hooks/loop_hook.c\
./src/hooks/mouse_click_hook_bonus.c\
./src/hooks/win_focus_hooks.c\
./src/hooks/in_game_loop/in_game_loop.c\
./src/hooks/in_game_loop/keys/in_game_keys.c\
./src/hooks/in_game_loop/keys/movement_key.c\
./src/hooks/in_game_loop/keys/rotation_key.c\
./src/hooks/in_game_loop/keys/bonus/E_key_bonus.c\
./src/hooks/in_game_loop/keys/bonus/in_game_shift_key_bonus.c\
./src/hooks/in_game_loop/keys/bonus/SPACE_key_bonus.c\
./src/hooks/in_game_loop/keys/utils/player_movement.c\
./src/hooks/in_game_loop/loops/doors_bonus.c\
./src/hooks/in_game_loop/loops/enemies_bonus.c\
./src/hooks/in_game_loop/loops/in_game_loops_handler_bonus.c\
./src/hooks/in_game_loop/loops/items_bonus.c\
./src/hooks/in_game_loop/loops/player_bonus.c\
./src/hooks/in_game_loop/loops/west_angle_bonus.c\
./src/hooks/in_game_loop/mouse/in_game_mouse_bonus.c\
./src/hooks/in_menus_loop/in_menu_keys_bonus.c\
./src/hooks/in_menus_loop/in_menu_loop_bonus.c\
./src/hooks/in_menus_loop/in_menu_mouse_bonus.c\
./src/hooks/in_menus_loop/keys/in_menu_enter_bonus.c\
./src/hooks/in_menus_loop/keys/in_menu_move_bonus.c\
./src/init/game_initialization.c\
./src/init/bonus/menu_textures_bonus.c\
./src/init/bonus/scan_doors_bonus.c\
./src/init/bonus/scan_enemies_bonus.c\
./src/init/bonus/scan_items_bonus.c\
./src/init/bonus/set_rand_bonus.c\
./src/init/bonus/sun_textures_bonus.c\
./src/init/bonus/textures_bonus.c\
./src/init/game/t_game_init.c\
./src/init/geometry/init_geometry.c\
./src/init/keys_init/keys_init.c\
./src/init/map_init/map_init.c\
./src/init/map_init/map_reset.c\
./src/init/menus_init/menus_init.c\
./src/init/mlx_init/mlx_init.c\
./src/init/textures/init_textures.c\
./src/init/textures/load_textures.c\
./src/init/utils/init_utils.c\
./src/map_validation/map_attributes.c\
./src/map_validation/map_content.c\
./src/map_validation/map_read.c\
./src/map_validation/validate.c\
./src/map_validation/bonus/is_entity_map_char_bonus.c\
./src/map_validation/utils/attrs.c\
./src/map_validation/utils/atttrs_chars_conditions.c\
./src/map_validation/utils/map_chars_tracking.c\
./src/map_validation/utils/map_logic_conditions.c\
./src/map_validation/utils/map_memory.c\
./src/map_validation/utils/t_tile_debug.c\
./src/map_validation/utils/t_tile_map_trim.c\
./src/raycast/raycast_algorithm.c\
./src/raycast/raycast.c\
./src/raycast/raycast_memory.c\
./src/raycast/raycast_movement.c\
./src/raycast/raycast_wall.c\
./src/raycast/bonus/rc_doors_bonus.c\
./src/raycast/bonus/rc_enemies_bonus.c\
./src/raycast/bonus/rc_items_bonus.c\
./src/raycast/bonus/rc_memory_bonus.c\
./src/raycast/utils/rc_calc.c\
./src/raycast/utils/rc_debug.c\
./src/raycast/utils/rc_initialization.c\
./src/raycast/utils/rc_set.c\
./src/raycast/utils/rc_walk.c\
./src/render/render.c\
./src/render/render_game.c\
./src/render/render_memory.c\
./src/render/render_menu_bonus.c\
./src/render/attack/attack_bonus.c\
./src/render/background/background_bonus.c\
./src/render/background/background.c\
./src/render/background/sun_bonus.c\
./src/render/bonus_entities/doors/doors_bonus.c\
./src/render/bonus_entities/enemies/enemies_bonus.c\
./src/render/bonus_entities/entities/entities_bonus.c\
./src/render/bonus_entities/entities/rend_ent_callbacks_bonus.c\
./src/render/bonus_entities/entities/rend_ent_mem_bonus.c\
./src/render/bonus_entities/items/items_bonus.c\
./src/render/hud/hud_bonus.c\
./src/render/hud/minimap_background_bonus.c\
./src/render/hud/minimap_bonus.c\
./src/render/hud/minimap_border_bonus.c\
./src/render/hud/minimap_map_bonus.c\
./src/render/hud/minimap_rays_bonus.c\
./src/render/line_drawing/bres_backup.c\
./src/render/line_drawing/bres_decision_var.c\
./src/render/line_drawing/bres_endpoints.c\
./src/render/line_drawing/bresenham.c\
./src/render/line_drawing/bres_logic.c\
./src/render/textures/door_bonus.c\
./src/render/textures/enemies_bonus.c\
./src/render/textures/items_bonus.c\
./src/render/textures/nearest_neighbour.c\
./src/render/textures/wall.c\
./src/render/utils/minimap_utils_bonus.c\
./src/render/utils/render_clipping.c\
./src/utils/game/debug.c\
./src/utils/game/game_doors_bonus.c\
./src/utils/game/game_doors_callbacks_bonus.c\
./src/utils/game/game_enemies_bonus.c\
./src/utils/game/game_enemies_conds_bonus.c\
./src/utils/game/game_enemies_lst_callbacks_bonus.c\
./src/utils/game/game_items_bonus.c\
./src/utils/game/game_items_conds_bonus.c\
./src/utils/game/game_items_lst_callbacks_bonus.c\
./src/utils/game/game_memory_bonus.c\
./src/utils/game/game_player.c\
./src/utils/game/game_sun_bonus.c\
./src/utils/game/keys_conditions.c\
./src/utils/game/map_chars_conditions_bonus.c\
./src/utils/game/map_chars_conditions.c\
./src/utils/game/map_utils.c\
./src/utils/game/menu_utils_bonus.c\
./src/utils/gnl/get_next_line.c\
./src/utils/gnl/get_next_line_nonl.c\
./src/utils/gnl/get_next_line_utils.c\
./src/utils/math/flt_math.c\
./src/utils/math/geometry.c\
./src/utils/math/vec_cmp.c\
./src/utils/math/vec_debug.c\
./src/utils/math/vec_manip.c\
./src/utils/math/vec_memory.c\
./src/utils/math/vectorial_ops.c\
./src/utils/math/vec_to_vec_ops.c\
./src/utils/render/mlx_holder.c\
./src/utils/render/mlx_utils_imgs.c\
./src/utils/render/rgb.c\
./src/utils/render/squared_texture_clipper.c\
./src/utils/simple_printf/ft_printf.c\
./src/utils/simple_printf/printf_cases.c\
./src/utils/simple_printf/printf_utils.c\

NAME=cub3D

SRC_USR_LIBS=$(shell find $(USR_LIBS) -name "*.c")
USRLIBS_FLAGS=-L./src/utils/libft -lft

MLX_SRC_FLAGS = -Imlx
MLX_LINK_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

RMF = /bin/rm -rf
CC = @gcc
CFLAGS = -Wall -Werror -Wextra -I/usr/include -Imlx_linux -O3 -g -fsanitize=address


CUB_OBJS_DIR = bin
CUB_OBJS_NOPREFIX = ${SRC_NOPREFIX:%.c=%.o}
CUB_OBJS_NOPREFIX_BONUS = ${SRC_NOPREFIX_BONUS:%.c=%.o}
CUB_OBJS_MAND = $(addprefix $(CUB_OBJS_DIR)/, $(CUB_OBJS_NOPREFIX))
CUB_OBJS_BONUS = $(addprefix $(CUB_OBJS_DIR)/, $(CUB_OBJS_NOPREFIX_BONUS))


all:
	@if [ $(shell find bin/ -name "*_bonus.o" 2>/dev/null | wc -l) -gt "0" ]; then \
		make --silent bonus; \
	else \
		make --silent mandatory; \
	fi;

mandatory:
	@printf "\033[1;33mMaking Mandatory part\n"
	@echo "\033[0;37m"
	@$(MAKE) --silent BONUS_FLAG="-DBONUS=0" "OBJS_CUB=$(CUB_OBJS_MAND)" $(NAME)
	@printf "\033[0;33mMandatory part done\n"
	@echo "\033[0;37m"

bonus:
	@printf "\033[1;36mMaking Bonus part\n"
	@echo "\033[0;37m"
	@$(MAKE) --silent BONUS_FLAG="-DBONUS=1" "OBJS_CUB=$(CUB_OBJS_BONUS)" $(NAME)
	@printf "\033[0;36mBonus part done\n"
	@echo "\033[0;37m"


$(NAME): $(OBJS_CUB) $(SRC_USR_LIBS)
	@echo "Objects Compiled..."
	@make -C src/utils/libft
	@echo "libft archive compiled...\n"
	@make --silent -C mlx_linux 2>/dev/null
	@echo "mlx compiled...\n"
	@echo "linking compiled objects and libraries..."
	$(CC) $(OBJS_CUB) $(CFLAGS) $(BONUS_FLAG) $(MLX_LINK_FLAGS) $(USRLIBS_FLAGS) -lm -o $(NAME)
	@printf "\033[1m\033[32m$(NAME) Compiled!\n"
	@echo "\033[0;37m"

#
#	this rule compiles sources in <path>.c and puts them in <obj_dir>/<path>.o
#
$(CUB_OBJS_DIR)/%.o: %.c $(INCLUDES_BONUS)
	@mkdir -p '$(@D)'
	$(CC) -c $(CFLAGS) $(BONUS_FLAG) $(MLX_SRC_FLAGS) $< -o $@

clean:
	@echo "destroying libft..."
	@$(MAKE) --silent -C src/utils/libft fclean
	@echo "destroying mlx..."
	@$(MAKE) --silent -C mlx_linux clean
	@printf "destroying Usr Object files...\n"
	@$(RMF) $(CUB_OBJS_DIR)
	@printf "\033[0;35mAll Object files destroyed!\n"
	@echo "\033[0;37m"

fclean: clean
	@printf "removing program executable...\n"
	@$(RMF) $(NAME)
	@printf "\033[0;35mExecutable removed!\n"
	@echo "\033[0;37m"

re: fclean all

reb: fclean bonus
