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
./src/includes.h\
./src/macros.h\
./src/sys_includes.h\
./src/types.h\
./src/X11_macros.h\
./src/utils/gnl/get_next_line_module.h\
./src/utils/libft/src/simple_printf/ft_printf_module.h\
./src/utils/libft/libft_module.h\
./src/utils/game/game_utils_module.h\
./src/utils/utils_module.h\
./src/utils/math/uti_math_module.h\
./src/init/game_init_module.h\
./src/map_validation/utils/map_utils_module.h\
./src/map_validation/map_validation_module.h\
./src/render/textures/textures_module.h\
./src/render/utils/uti_render_module.h\
./src/render/line_drawing/line_drawing_module.h\
./src/render/enemies/rend_enem_module.h\
./src/render/render_module.h\
./src/raycast/raycast_module.h\
./src/init/game_init.h\
./src/init/game_init_module.h\
./src/map_validation/map_validation.h\
./src/map_validation/map_validation_module.h\
./src/map_validation/map_validation_types.h\
./src/map_validation/utils/map_utils.h\
./src/map_validation/utils/map_utils_module.h\
./src/raycast/raycast.h\
./src/raycast/raycast_module.h\
./src/raycast/raycast_types.h\
./src/render/render.h\
./src/render/render_module.h\
./src/render/render_types.h\
./src/render/enemies/rend_enem.h\
./src/render/enemies/rend_enem_module.h\
./src/render/line_drawing/line_drawing.h\
./src/render/line_drawing/line_drawing_module.h\
./src/render/line_drawing/line_drawing_types.h\
./src/render/textures/textures.h\
./src/render/textures/textures_module.h\
./src/render/textures/texture_types.h\
./src/render/utils/uti_render.h\
./src/render/utils/uti_render_module.h\
./src/render/utils/uti_render_types.h\
./src/utils/utils_module.h\
./src/utils/game/game_utils.h\
./src/utils/game/game_utils_module.h\
./src/utils/gnl/get_next_line.h\
./src/utils/gnl/get_next_line_module.h\
./src/utils/math/uti_math.h\
./src/utils/math/uti_math_module.h\
./src/utils/math/uti_math_types.h\

SRC_NOPREFIX=\
./src/main.c\
./src/init/game_initialization.c\
./src/map_validation/map_attributes.c\
./src/map_validation/map_content.c\
./src/map_validation/map_read.c\
./src/map_validation/validate.c\
./src/map_validation/utils/atttrs_chars_conditions.c\
./src/map_validation/utils/map_chars_conditions.c\
./src/map_validation/utils/map_logic_conditions.c\
./src/map_validation/utils/map_memory.c\
./src/map_validation/utils/t_tile_debug.c\
./src/map_validation/utils/t_tile_map_trim.c\
./src/raycast/raycast.c\
./src/raycast/rc_debug.c\
./src/raycast/rc_initialization.c\
./src/raycast/rc_set.c\
./src/render/render.c\
./src/render/enemies/rend_enem_mem.c\
./src/render/line_drawing/bres_backup.c\
./src/render/line_drawing/bres_decision_var.c\
./src/render/line_drawing/bres_endpoints.c\
./src/render/line_drawing/bresenham.c\
./src/render/line_drawing/bres_logic.c\
./src/render/textures/bcb_clip.c\
./src/render/textures/bicubic.c\
./src/render/textures/cubic_interpolation.c\
./src/render/textures/texture_manip.c\
./src/render/textures/texture_types_ops.c\
./src/render/utils/brightness.c\
./src/render/utils/mlx_holder.c\
./src/render/utils/mlx_utils_imgs.c\
./src/render/utils/render_conditions.c\
./src/render/utils/rgb.c\
./src/utils/game/debug.c\
./src/utils/game/game_enemies.c\
./src/utils/game/game_memory.c\
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

USR_LIBS=\
src/utils/libft\

SRC_USR_LIBS=$(shell find $(USR_LIBS) -name "*.c")

LIBS_FLAGS=-L./src/utils/libft -lft

CC = @gcc
CFLAGS = -Wall -Werror -Wextra -I/usr/include -Imlx_linux -O3 -g -fsanitize=address
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
