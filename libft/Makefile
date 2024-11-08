# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 23:54:38 by rverona-          #+#    #+#              #
#    Updated: 2023/05/10 13:42:02 by rverona-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- MakeFile -*-

NAME = libft.a
CC = gcc
FLAGS = -Wall -Werror -Wextra
ARC = ar -rcs
RM = rm -rf

INC = libft.h

SRCS_DIR = libc_functions additional_functions ft_printf get_next_line ft_printf/printf_utils

SRCS = libc_functions/ft_isalpha.c libc_functions/ft_isdigit.c libc_functions/ft_isalnum.c
SRCS += libc_functions/ft_isascii.c libc_functions/ft_isprint.c libc_functions/ft_strlen.c
SRCS += libc_functions/ft_memset.c libc_functions/ft_bzero.c libc_functions/ft_toupper.c
SRCS += libc_functions/ft_tolower.c libc_functions/ft_strncmp.c libc_functions/ft_strchr.c
SRCS += libc_functions/ft_memcpy.c libc_functions/ft_memmove.c libc_functions/ft_strrchr.c
SRCS += libc_functions/ft_memchr.c libc_functions/ft_memcmp.c	libc_functions/ft_strnstr.c
SRCS += libc_functions/ft_atoi.c libc_functions/ft_strlcpy.c libc_functions/ft_strlcat.c
SRCS += libc_functions/ft_calloc.c libc_functions/ft_strdup.c 
SRCS += additional_functions/ft_substr.c additional_functions/ft_strjoin.c 
SRCS += additional_functions/ft_itoa.c additional_functions/ft_strtrim.c
SRCS += additional_functions/ft_split.c additional_functions/ft_strmapi.c 
SRCS += additional_functions/ft_striteri.c additional_functions/ft_putchar_fd.c 
SRCS += additional_functions/ft_putstr_fd.c additional_functions/ft_putendl_fd.c
SRCS += additional_functions/ft_putnbr_fd.c 
SRCS += ft_printf/ft_printf.c ft_printf/printf_utils/printchar.c 
SRCS += ft_printf/printf_utils/printhex.c ft_printf/printf_utils/printnbr.c
SRCS += ft_printf/printf_utils/printptr.c ft_printf/printf_utils/printstr.c
SRCS += ft_printf/printf_utils/printunsigned.c 
SRCS += get_next_line/get_next_line.c

OBJ_DIR = objects/
OBJ = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_DIR), $(OBJ))

all: $(NAME)

$(OBJS): $(OBJ_DIR)%.o: %.c 
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@ -I $(INC)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)libc_functions/
	@mkdir -p $(OBJ_DIR)additional_functions/
	@mkdir -p $(OBJ_DIR)get_next_line/
	@mkdir -p $(OBJ_DIR)ft_printf/
	@mkdir -p $(OBJ_DIR)ft_printf/printf_utils/

$(NAME): $(OBJS)
	@$(ARC) $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

VPATH = $(SRCS_DIR)

.PHONY: all clean fclean re