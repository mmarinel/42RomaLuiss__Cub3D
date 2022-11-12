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
./src/libft.h\
./libft_module.h\
./src/simple_printf/ft_printf_module.h\
./src/simple_printf/ft_printf.h\
./src/simple_printf/ft_printf_module.h\

SRC_NOPREFIX=\
./src/ft_atoi.c\
./src/ft_bzero.c\
./src/ft_calloc.c\
./src/ft_dbl_abs.c\
./src/ft_flt_abs.c\
./src/ft_free.c\
./src/ft_int_abs.c\
./src/ft_isalnum.c\
./src/ft_isalpha.c\
./src/ft_isascii.c\
./src/ft_isdigit.c\
./src/ft_isdigit_string.c\
./src/ft_isprint.c\
./src/ft_isspace.c\
./src/ft_itoa.c\
./src/ft_lstadd_back.c\
./src/ft_lstadd_front.c\
./src/ft_lstclear.c\
./src/ft_lstdelone.c\
./src/ft_lstiter.c\
./src/ft_lstlast.c\
./src/ft_lstmap.c\
./src/ft_lstnew.c\
./src/ft_lstsize.c\
./src/ft_memchr.c\
./src/ft_memcmp.c\
./src/ft_memcpy.c\
./src/ft_memmove.c\
./src/ft_memset.c\
./src/ft_multisplit.c\
./src/ft_put_nbr_base.c\
./src/ft_putchar_fd.c\
./src/ft_putendl_fd.c\
./src/ft_putnbr_fd.c\
./src/ft_putstr_fd.c\
./src/ft_split.c\
./src/ft_split_join.c\
./src/ft_split_merge.c\
./src/ft_splitclear.c\
./src/ft_splitcpy.c\
./src/ft_splitinit.c\
./src/ft_splitlen.c\
./src/ft_splitprint.c\
./src/ft_str_isempty.c\
./src/ft_str_member.c\
./src/ft_strchr.c\
./src/ft_strcmp.c\
./src/ft_strcpy.c\
./src/ft_strdup.c\
./src/ft_string_new.c\
./src/ft_striteri.c\
./src/ft_strjoin.c\
./src/ft_strlcat.c\
./src/ft_strlcpy.c\
./src/ft_strlen.c\
./src/ft_strmapi.c\
./src/ft_strncmp.c\
./src/ft_strnstr.c\
./src/ft_strrchr.c\
./src/ft_strtrim.c\
./src/ft_substr.c\
./src/ft_tolower.c\
./src/ft_toupper.c\
./src/ft_write.c\
./src/int_max.c\
./src/is_file_type.c\
./src/simple_printf/ft_printf.c\
./src/simple_printf/printf_cases.c\
./src/simple_printf/printf_utils.c\

USR_LIBS=\

SRC_USR_LIBS=$(shell find $(USR_LIBS) -name "*.c")

LIBS_FLAGS=

CC = @gcc
CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = bin
OBJS = $(addprefix $(OBJS_DIR)/, $(SRC_NOPREFIX:%.c=%.o))

RMF = @/bin/rm -rf

NAME = libft.a

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
	ar -rc $(NAME) $(OBJS) && ranlib $(NAME)

#
#	this rule compiles sources in <path>.c and puts them in <obj_dir>/<path>.o
#
#
$(shell echo $(OBJS_DIR))/%.o: %.c $(INCLUDES)#		$(wildcard $(<D)/*.h)------this recompiles only for headers in the same folder!
	@mkdir -p '$(@D)'
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	$(RMF) $(OBJS) $(OBJS_DIR)

fclean: clean
	$(RMF) $(NAME)

re: fclean all

.PHONY: all clean fclean re
