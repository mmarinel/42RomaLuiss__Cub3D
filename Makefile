# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    header.txt                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: earendil <earendil@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 19:06:19 by earendil          #+#    #+#              #
#    Updated: 2022/10/25 19:06:21 by earendil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES=\
./src/colors.h\
./src/game_types.h\
./src/includes.h\
./src/macros.h\
./src/sys_includes_bonus.h\
./src/sys_includes.h\
./src/types.h\
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
./src/init/bonus/game_init_bonus_module.h\
./src/hooks/in_game_loop/mouse/in_game_mouse_module.h\
./src/hooks/in_game_loop/loops/in_game_loops_module.h\
./src/hooks/in_game_loop/in_game_loop_module.h\
./src/hooks/in_game_loop/keys/utils/in_game_key_utils_module.h\
./src/hooks/in_game_loop/keys/in_game_keys_module.h\
./src/hooks/in_game_loop/keys/bonus/in_game_keys_bonus_module.h\
./src/hooks/hooks_module.h\
./src/hooks/in_menus_loop/in_menu_loop_module.h\
./src/exit/exit_module.h\
./src/map_validation/utils/map_utils_module.h\
./src/map_validation/map_validation_module.h\
./src/map_validation/bonus/map_validation_bonus_module.h\
./src/render/textures/textures_module.h\
./src/render/utils/uti_render_module.h\
./src/render/line_drawing/line_drawing_module.h\
./src/render/bonus_entities/rend_bonus_module.h\
./src/render/render_module.h\
./src/raycast/utils/rc_utils_module.h\
./src/raycast/bonus/rc_bonus_module.h\
./src/raycast/raycast_module.h\
./src/exit/exit.h\
./src/exit/exit_module.h\
./src/hooks/hooks.h\
./src/hooks/hooks_module.h\
./src/hooks/in_game_loop/in_game_loop.h\
./src/hooks/in_game_loop/in_game_loop_module.h\
./src/hooks/in_game_loop/keys/in_game_keys.h\
./src/hooks/in_game_loop/keys/in_game_keys_module.h\
./src/hooks/in_game_loop/keys/bonus/in_game_keys_bonus.h\
./src/hooks/in_game_loop/keys/bonus/in_game_keys_bonus_module.h\
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
./src/init/bonus/game_init_bonus.h\
./src/init/bonus/game_init_bonus_module.h\
./src/init/utils/init_utils.h\
./src/init/utils/init_utils_module.h\
./src/map_validation/map_validation.h\
./src/map_validation/map_validation_module.h\
./src/map_validation/map_validation_types.h\
./src/map_validation/bonus/map_validation_bonus.h\
./src/map_validation/bonus/map_validation_bonus_module.h\
./src/map_validation/utils/map_utils.h\
./src/map_validation/utils/map_utils_module.h\
./src/raycast/raycast.h\
./src/raycast/raycast_module.h\
./src/raycast/raycast_types.h\
./src/raycast/bonus/rc_bonus.h\
./src/raycast/bonus/rc_bonus_module.h\
./src/raycast/utils/rc_utils.h\
./src/raycast/utils/rc_utils_module.h\
./src/render/render.h\
./src/render/render_module.h\
./src/render/render_types.h\
./src/render/bonus_entities/rend_bonus.h\
./src/render/bonus_entities/rend_bonus_module.h\
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
./src/exit/sun_textures_bonus.c\
./src/exit/textures_clean_bonus.c\
./src/exit/textures_clean.c\
./src/hooks/in_end_loop_bonus.c\
./src/hooks/keys_hook.c\
./src/hooks/loop_hook.c\
./src/hooks/mouse_click_hook.c\
./src/hooks/win_focus_hooks.c\
./src/hooks/in_game_loop/in_game_loop.c\
./src/hooks/in_game_loop/keys/in_game_keys.c\
./src/hooks/in_game_loop/keys/movement_key.c\
./src/hooks/in_game_loop/keys/rotation_key_bonus.c\
./src/hooks/in_game_loop/keys/bonus/E_key_bonus.c\
./src/hooks/in_game_loop/keys/bonus/in_game_shift_key.c\
./src/hooks/in_game_loop/keys/bonus/SPACE_key_bonus.c\
./src/hooks/in_game_loop/keys/utils/player_movement.c\
./src/hooks/in_game_loop/loops/doors_bonus.c\
./src/hooks/in_game_loop/loops/enemies_bonus.c\
./src/hooks/in_game_loop/loops/in_game_loops_handler.c\
./src/hooks/in_game_loop/loops/items_bonus.c\
./src/hooks/in_game_loop/loops/player_bonus.c\
./src/hooks/in_game_loop/loops/west_angle_bonus.c\
./src/hooks/in_game_loop/mouse/in_game_mouse.c\
./src/hooks/in_menus_loop/in_menu_keys.c\
./src/hooks/in_menus_loop/in_menu_loop_bonus.c\
./src/hooks/in_menus_loop/in_menu_mouse.c\
./src/hooks/in_menus_loop/keys/in_menu_enter.c\
./src/hooks/in_menus_loop/keys/in_menu_move.c\
./src/init/game_initialization_bonus.c\
./src/init/game_initialization.c\
./src/init/bonus/menu_textures_bonus.c\
./src/init/bonus/scan_doors.c\
./src/init/bonus/scan_enemies.c\
./src/init/bonus/scan_items.c\
./src/init/bonus/sun_textures_bonus.c\
./src/init/bonus/textures_bonus.c\
./src/init/game/t_game_init.c\
./src/init/geometry/init_geometry.c\
./src/init/keys_init/keys_init.c\
./src/init/map_init/map_init.c\
./src/init/menus_init/menus_init.c\
./src/init/mlx_init/mlx_init.c\
./src/init/textures/init_textures.c\
./src/init/textures/load_textures.c\
./src/init/utils/init_utils.c\
./src/map_validation/map_attributes.c\
./src/map_validation/map_content.c\
./src/map_validation/map_read.c\
./src/map_validation/map_reset.c\
./src/map_validation/validate.c\
./src/map_validation/utils/attrs.c\
./src/map_validation/utils/atttrs_chars_conditions.c\
./src/map_validation/utils/map_chars_conditions.c\
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
./src/raycast/bonus/rc_bon_memory.c\
./src/raycast/bonus/rc_doors_bonus.c\
./src/raycast/bonus/rc_enemies_bonus.c\
./src/raycast/bonus/rc_items_bonus.c\
./src/raycast/utils/rc_calc.c\
./src/raycast/utils/rc_debug.c\
./src/raycast/utils/rc_initialization.c\
./src/raycast/utils/rc_set.c\
./src/raycast/utils/rc_walk.c\
./src/render/render.c\
./src/render/render_end.c\
./src/render/render_game.c\
./src/render/render_memory.c\
./src/render/render_menu.c\
./src/render/attack/attack_bonus.c\
./src/render/background/background_bonus.c\
./src/render/background/background.c\
./src/render/background/sun_bonus.c\
./src/render/bonus_entities/doors/doors_bonus.c\
./src/render/bonus_entities/enemies/enemies_bonus.c\
./src/render/bonus_entities/entities/entities_bonuc.c\
./src/render/bonus_entities/entities/rend_ent_callbacks_bonus.c\
./src/render/bonus_entities/entities/rend_ent_mem_bonus.c\
./src/render/bonus_entities/items/items_bonus.c\
./src/render/hud/hud.c\
./src/render/hud/minimap_background.c\
./src/render/hud/minimap_border.c\
./src/render/hud/minimap.c\
./src/render/hud/minimap_map.c\
./src/render/hud/minimap_rays.c\
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
./src/render/utils/minimap_utils.c\
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
./src/utils/game/map_chars_conditions_bonus.c\
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

USR_LIBS=\
src/utils/libft\

SRC_USR_LIBS=$(shell find $(USR_LIBS) -name "*.c")

LIBS_FLAGS=-L./src/utils/libft -lft

CC = @gcc
CFLAGS = -Wall -Werror -Wextra -I/usr/include -Imlx_linux -O3 -g -fsanitize=address -DBONUS=1
# CFLAGS = -Wall -Werror -Wextra -I/usr/include -Imlx_linux -O3 -DBONUS=1
MLX_FLAGS = TODO

RMF = /bin/rm -rf

OBJS_DIR = bin
OBJS_NOPREFIX = ${SRC_NOPREFIX:%.c=%.o}
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_NOPREFIX))

# A library is tracked with its path and its build target
# which can be the same used by its Makefile or a .dylib
# file we need to import in our project directory root.
# in the first case, both us and its Makefile will attempt to delete the file,
# so -rf is used in order to keep double deletions silent.
MLX_LIB_DIR = mlx
# MLX_TARGET = libmlx.dylib

MLX_SRC_FLAGS = -Imlx
MLX_LINK_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

SYS_LIBS+=\
$(MLX_LIB_DIR)\

SYS_TARGETS+=\
$(MLX_TARGET)\

NAME = cub3D

all: $(NAME)

# bonus: .BUILD

$(NAME): $(OBJS) $(SRC_USR_LIBS) $(SYS_TARGETS)
	@$(MAKE) .DO_LIBS
	@echo "linking compiled objects and libraries..."
	$(CC) $(OBJS) $(CFLAGS) $(MLX_LINK_FLAGS) $(LIBS_FLAGS) -lm -o $(NAME)
	@printf "\033[1m\033[32m$(NAME) Compiled!\n"
	@echo "\033[0;37m"

#
#	this rule compiles sources in <path>.c and puts them in <obj_dir>/<path>.o
#
#
$(shell echo $(OBJS_DIR))/%.o: %.c $(INCLUDES)#		$(wildcard $(<D)/*.h)------this recompiles only for headers in the same folder!
	@mkdir -p '$(@D)'
	$(CC) -c $(CFLAGS) $(MLX_SRC_FLAGS) $< -o $@

$(MLX_TARGET):
	@make -C mlx
# @mv mlx/libmlx.dylib .

clean:
	@printf "removing Object files...\n"
	@$(MAKE) .DESTROY_LIBS
	@$(RMF) $(OBJS) $(OBJS_DIR)
	@printf "\033[0;35mObject files removed!\n"
	@echo "\033[0;37m"

fclean: clean
	@printf "removing program executable...\n"
	@$(RMF) $(NAME)
	@printf "\033[0;35mExecutable removed!\n"
	@echo "\033[0;37m"

re: fclean all

.BUILD:
	@printf "\033[1m\033[33mMaking Project...\033[0m\n"
	@$(MAKE) $(NAME)

.DO_LIBS:
	@echo "making user static libraries..."
	@for LIB in $(USR_LIBS); do \
		LIB_NAME=$$( echo $$LIB | awk -F "/" '{print $$NF}' ); \
		echo "lib is "$$LIB; \
		echo "lib is "$$LIB_NAME; \
		make -C $$LIB | sed "s/all/$$LIB_NAME/g"; \
	done
#touch /dev/null; \

.DESTROY_LIBS:
	@for LIB in $(USR_LIBS) $(SYS_LIBS); do \
		make -s -C $$LIB fclean; \
	done; \
	for TARGET in $(SYS_TARGETS); do \
		rm -rf $$TARGET; \
	done
