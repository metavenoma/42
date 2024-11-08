# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 09:46:31 by rverona-          #+#    #+#              #
#    Updated: 2024/04/30 09:46:32 by rverona-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ClapTrap
OBJ_PATH = objects/
INC = -I ./includes

SRC = sources/main.cpp sources/ClapTrap.cpp
OBJ = $(addprefix $(OBJ_PATH), $(SRC:.cpp=.o))

CPP = c++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

$(OBJ_PATH)%.o: %.cpp 
	@mkdir -p $(dir $@)
	$(CPP) $(CPPFLAGS) -c $< -o $@ $(INC)

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) $(INC) -o $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm $(NAME)

re: fclean all
