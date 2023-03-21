# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 23:54:38 by rverona-          #+#    #+#              #
#    Updated: 2023/03/20 16:34:09 by rverona-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- MakeFile -*-

NAME = libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
ARC = ar -rcs
RM = rm -rf

INC = libft.h

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c
SRCS += ft_isascii.c ft_isprint.c ft_strlen.c
SRCS += ft_memset.c ft_bzero.c ft_toupper.c
SRCS += ft_tolower.c ft_strncmp.c ft_strchr.c
SRCS += ft_memcpy.c ft_memmove.c ft_strrchr.c
SRCS += ft_memchr.c ft_memcmp.c	ft_strnstr.c
SRCS += ft_atoi.c ft_strlcpy.c ft_strlcat.c
SRCS += ft_calloc.c ft_strdup.c ft_substr.c
SRCS += ft_strjoin.c ft_itoa.c ft_strtrim.c
SRCS += ft_split.c ft_strmapi.c ft_striteri.c
SRCS += ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c
SRCS += ft_putnbr_fd.c ft_printf.c printf_utils/printchar.c
SRCS += printf_utils/printhex.c printf_utils/printnbr.c
SRCS += printf_utils/printptr.c printf_utils/printstr.c
SRCS += printf_utils/printunsigned.c get_next_line.c

OBJ_PATH = objects/
LIBFT_OBJ = $(SRCS:.c=.o)
LIBFT_OBJS = $(addprefix $(OBJ_PATH), $(LIBFT_OBJ))

$(OBJ_PATH)%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC)

all: $(NAME)

$(LIBFT_OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)printf_utils/

$(NAME): $(LIBFT_OBJS)
	@$(ARC) $(NAME) $(LIBFT_OBJS) libft.h

clean:
	@$(RM) $(OBJ_PATH)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
