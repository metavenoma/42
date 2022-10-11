# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rverona- <rverona-@student.42.org.br>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 23:54:38 by rverona-          #+#    #+#              #
#    Updated: 2022/10/06 22:38:50 by rverona-         ###   ########.fr        #
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
SRCS += ft_tolower.c ft_strncmp.c ft_strchr.c
SRCS += ft_memcpy.c ft_memmove.c ft_strrchr.c
SRCS += ft_memchr.c ft_memcmp.c	ft_strnstr.c
SRCS += ft_atoi.c ft_strlcpy.c ft_strlcat.c
SRCS += ft_calloc.c ft_strdup.c ft_substr.c
SRCS += ft_strjoin.c ft_itoa.c 
OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	$(ARC) $(NAME) $(OBJS) libft.h

bonus:

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
