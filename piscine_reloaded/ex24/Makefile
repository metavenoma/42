# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rverona- <rverona-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/27 17:16:04 by rverona-          #+#    #+#              #
#    Updated: 2022/08/27 22:03:21 by rverona-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- MakeFile -*-

PROGRAM = libft.a
INC_DIR = ./includes/
SRC_DIR = ./srcs/
FLAGS = -Wall -Wextra -Werror 
FLAGS += -I $(INC_DIR)
ARC = ar -rcs
RM = rm -f
SRCS = $(SRC_DIR)ft_putchar.c $(SRC_DIR)ft_swap.c $(SRC_DIR)ft_putstr.c
SRCS += $(SRC_DIR)ft_strlen.c $(SRC_DIR)ft_strcmp.c
OBJS = ${SRCS:.c=.o}

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(ARC) $(PROGRAM) $(OBJS) 

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(PROGRAM)

re: fclean all
