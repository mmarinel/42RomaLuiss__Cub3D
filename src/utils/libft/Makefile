# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 19:06:19 by earendil          #+#    #+#              #
#    Updated: 2022/10/28 09:43:27 by mmarinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES=\
./libft.h\

SRC_NOPREFIX=\
ft_atoi.c\
ft_bzero.c\
ft_calloc.c\
ft_isalnum.c\
ft_isalpha.c\
ft_isascii.c\
ft_isdigit.c\
ft_isprint.c\
ft_itoa.c\
ft_lstadd_back.c\
ft_lstadd_front.c\
ft_lstclear.c\
ft_lstdelone.c\
ft_lstiter.c\
ft_lstlast.c\
ft_lstmap.c\
ft_lstnew.c\
ft_lstsize.c\
ft_memchr.c\
ft_memcmp.c\
ft_memcpy.c\
ft_memmove.c\
ft_memset.c\
ft_putchar_fd.c\
ft_putendl_fd.c\
ft_putnbr_fd.c\
ft_putstr_fd.c\
ft_split.c\
ft_strchr.c\
ft_strdup.c\
ft_striteri.c\
ft_strjoin.c\
ft_strlcat.c\
ft_strlcpy.c\
ft_strlen.c\
ft_strmapi.c\
ft_strncmp.c\
ft_strnstr.c\
ft_strrchr.c\
ft_strtrim.c\
ft_substr.c\
ft_tolower.c\
ft_toupper.c\

CC = @gcc
CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = bin
OBJS = $(addprefix $(OBJS_DIR)/, $(SRC_NOPREFIX:.c=.o))

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
	$(RMF) $(OBJS)

fclean: clean
	$(RMF) $(NAME)

re: fclean all

.PHONY: all clean fclean re
