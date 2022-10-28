# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 19:06:19 by earendil          #+#    #+#              #
#    Updated: 2022/10/28 10:48:39 by mmarinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES=\
./src/colors.h\
./src/types.h\
./src/map_validation/map_validation.h\
./src/map_validation/gnl/get_next_line.h\
./src/map_validation/gnl/get_next_line_module.h\
./src/utils/simple_printf/ft_printf.h\
./src/utils/simple_printf/ft_printf_module.h\

SRC_NOPREFIX=\
./src/main.c\
./src/map_validation/validate.c\
./src/map_validation/gnl/get_next_line.c\
./src/map_validation/gnl/get_next_line_utils.c\
./src/utils/simple_printf/ft_printf.c\
./src/utils/simple_printf/printf_cases.c\
./src/utils/simple_printf/printf_utils.c\

USR_LIBS=\
src/utils/libft\

SRC_USR_LIBS=$(shell find $(USR_LIBS) -name "*.c")

CC = @gcc
CFLAGS = -Wall -Werror -Wextra
MLX_FLAGS = TODO


OBJS_DIR = bin
OBJS_NOPREFIX = ${SRC_NOPREFIX:%.c=%.o}
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_NOPREFIX))

NAME = minishell

	# all: .BUILD

	# bonus: .BUILD

$(NAME): $(OBJS) $(SRC_USR_LIBS)
	@$(MAKE) .DO_LIBS
	$(CC) $(CFLAGS) $(READLINE_FLAGS) $(OBJS) $(USR_LIBS_AR) -o $(NAME)
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
	@/bin/rm -f $(OBJS)
	@printf "\033[0;35mObject files removed!\n"
	@echo "\033[0;37m"

fclean: clean
	@printf "removing program executable...\n"
	@/bin/rm -f $(NAME)
	@printf "\033[0;35mExecutable removed!\n"
	@echo "\033[0;37m"

re: fclean all

.BUILD:
	@printf "\033[1m\033[33mMaking Project...\033[0m\n"
	@$(MAKE) $(NAME)

.DO_LIBS:
	@for LIB in $(USR_LIBS); do \
		make -C $$LIB; \
	done

.DESTROY_LIBS:
	@for LIB in $(USR_LIBS); do \
		make -C $$LIB fclean; \
	done