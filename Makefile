# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 23:54:38 by rverona-          #+#    #+#              #
#    Updated: 2022/09/03 01:17:30 by rverona-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- MakeFile -*-

NAME = libft.a
FLAGS = -Wall -Werror -Wextra
ARC = ar -rcs
RM = rm -f
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c
SRCS += ft_isascii.c ft_isprint.c ft_strlen.c
SRCS += ft_memset.c ft_bzero.c ft_toupper.c
SRCS += ft_tolower.c ft_strncmp.c
OBJS = 

all: $(NAME)

$(NAME): $(OBJS)
	$(ARC) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(PROGRAM)

re: fclean all
