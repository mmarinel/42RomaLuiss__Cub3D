# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 12:41:21 by mmarinel          #+#    #+#              #
#    Updated: 2022/01/21 10:44:15 by mmarinel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_MAND = ft_bzero.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_strlen.c \
ft_memcpy.c \
ft_memmove.c \
ft_memset.c \
ft_strlcat.c \
ft_strlcpy.c \
ft_strnstr.c \
ft_memchr.c \
ft_memcmp.c \
ft_toupper.c \
ft_tolower.c \
ft_strchr.c \
ft_strrchr.c \
ft_strnstr.c \
ft_strncmp.c \
ft_atoi.c \
ft_calloc.c \
ft_strdup.c

SRCS_MAND_2 = ft_substr.c \
ft_strjoin.c \
ft_strtrim.c \
ft_split.c \
ft_itoa.c \
ft_strmapi.c \
ft_striteri.c \
ft_putchar_fd.c \
ft_putstr_fd.c \
ft_putendl_fd.c \
ft_putnbr_fd.c

SRCS_BONUS = ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c

HEADERS = libft.h

CFLAGS = -Wall -Wextra -Werror

CC = gcc

OBJS_MAND = $(SRCS_MAND:.c=.o)

OBJS_MAND_2 = $(SRCS_MAND_2:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAME)

bonus: $(OBJS_BONUS) $(HEADERS)
	ar -rc $(NAME) $(OBJS_BONUS) && ranlib $(NAME)

$(NAME): $(OBJS_MAND) $(OBJS_MAND_2) $(HEADERS)
	ar -rc $(NAME) $(OBJS_MAND) $(OBJS_MAND_2) && ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS_MAND) $(OBJS_MAND_2) $(OBJS_BONUS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
