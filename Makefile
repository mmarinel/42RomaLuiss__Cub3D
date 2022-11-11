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
./src/types.h\
./src/map_validation/map_validation_module.h\
./src/raycast/raycast_module.h\
./src/utils/fixed_point/fixed_point_module.h\
./src/utils/game/game_utils_module.h\
./src/utils/gnl/get_next_line_module.h\
./src/utils/libft/libft_module.h\
./src/utils/libft/src/simple_printf/ft_printf_module.h\
./src/utils/map/map_utils_module.h\
./src/utils/render/render_module.h\
./src/utils/types/types_module.h\
./src/utils/utils_module.h\
./src/map_validation/map_validation.h\
./src/map_validation/map_validation_module.h\
./src/raycast/ray_cast_types.h\
./src/raycast/raycast.h\
./src/raycast/raycast_module.h\
./src/utils/utils_module.h\
./src/utils/fixed_point/fixed_point.h\
./src/utils/fixed_point/fixed_point_module.h\
./src/utils/game/game_utils.h\
./src/utils/game/game_utils_module.h\
./src/utils/gnl/get_next_line.h\
./src/utils/gnl/get_next_line_module.h\
./src/utils/map/map_utils.h\
./src/utils/map/map_utils_module.h\
./src/utils/render/render.h\
./src/utils/render/render_module.h\
./src/utils/render/render_types.h\
./src/utils/types/t_types.h\
./src/utils/types/types_module.h\

SRC_NOPREFIX=\
./src/main.c\
./src/map_validation/map_attributes.c\
./src/map_validation/map_content.c\
./src/map_validation/map_read.c\
./src/map_validation/validate.c\
./src/raycast/raycast.c\
./src/utils/fixed_point/fx_arithm.c\
./src/utils/fixed_point/fx_conditions.c\
./src/utils/fixed_point/fx_conversions.c\
./src/utils/fixed_point/fx_utils.c\
./src/utils/fixed_point/t_fixed.c\
./src/utils/game/debug.c\
./src/utils/game/game_memory.c\
./src/utils/game/geometry.c\
./src/utils/game/math.c\
./src/utils/game/vector.c\
./src/utils/gnl/get_next_line.c\
./src/utils/gnl/get_next_line_utils.c\
./src/utils/map/atttrs_chars_conditions.c\
./src/utils/map/map_chars_conditions.c\
./src/utils/map/map_logic_conditions.c\
./src/utils/map/map_memory.c\
./src/utils/map/t_tile_debug.c\
./src/utils/map/t_tile_map_trim.c\
./src/utils/render/brightness.c\
./src/utils/render/mlx_utils_imgs.c\
./src/utils/render/render_conditions.c\
./src/utils/render/rgb.c\
./src/utils/types/t_dbl.c\

USR_LIBS=\
src/utils/libft\

SRC_USR_LIBS=$(shell find $(USR_LIBS) -name "*.c")

LIBS_FLAGS=-L./src/utils/libft -lft

CC = @gcc
CFLAGS = -Wall -Werror -Wextra
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
MLX_TARGET = libmlx.dylib

MLX_SRC_FLAGS = -Imlx
MLX_LINK_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

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
	@mv mlx/libmlx.dylib .

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
