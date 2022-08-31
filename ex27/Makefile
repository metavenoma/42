# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rverona- <rverona-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/31 22:11:41 by rverona-          #+#    #+#              #
#    Updated: 2022/08/31 22:16:19 by rverona-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- MakeFile -*-

NAME = ft_display_file
SRC = ft_display_file.c

all : $(NAME)

$(NAME) :
	gcc -Wall -Werror -Wextra $(SRC) -o $(NAME)

clean :
	rm -f *.o
fclean : clean
	rm -f $(NAME)
re: fclean all
