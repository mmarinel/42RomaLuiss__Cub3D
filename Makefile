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
./src/utils/game/game_utils_module.h\
./src/utils/gnl/get_next_line_module.h\
./src/utils/libft/libft_module.h\
./src/utils/libft/src/simple_printf/ft_printf_module.h\
./src/utils/map/map_utils_module.h\
./src/utils/utils_module.h\
./src/map_validation/map_validation.h\
./src/map_validation/map_validation_module.h\
./src/utils/utils_module.h\
./src/utils/game/game_utils.h\
./src/utils/game/game_utils_module.h\
./src/utils/gnl/get_next_line.h\
./src/utils/gnl/get_next_line_module.h\
./src/utils/map/map_utils.h\
./src/utils/map/map_utils_module.h\

SRC_NOPREFIX=\
./src/main.c\
./src/map_validation/map_attributes.c\
./src/map_validation/map_content.c\
./src/map_validation/map_read.c\
./src/map_validation/validate.c\
./src/utils/game/game_memory.c\
./src/utils/gnl/get_next_line.c\
./src/utils/gnl/get_next_line_utils.c\
./src/utils/map/atttrs_chars_conditions.c\
./src/utils/map/map_chars_conditions.c\
./src/utils/map/map_logic_conditions.c\
./src/utils/map/map_memory.c\

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

NAME = cub3D

all: $(NAME)

# bonus: .BUILD

$(NAME): $(OBJS) $(SRC_USR_LIBS)
	@$(MAKE) .DO_LIBS
	@echo "linking compiled objects and libraries..."
	$(CC) $(CFLAGS) $(READLINE_FLAGS) $(OBJS) $(LIBS_FLAGS) -o $(NAME)
	@printf "\033[1m\033[32m$(NAME) Compiled!\n"
	@echo "\033[0;37m"

#
#	this rule compiles sources in <path>.c and puts them in <obj_dir>/<path>.o
#
#
$(shell echo $(OBJS_DIR))/%.o: %.c $(INCLUDES)#		$(wildcard $(<D)/*.h)------this recompiles only for headers in the same folder!
	@mkdir -p '$(@D)'
	$(CC) -c $(CFLAGS) $< -o $@

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
	@for LIB in $(USR_LIBS); do \
		make -C $$LIB fclean; \
	done
