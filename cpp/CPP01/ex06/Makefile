# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rverona- <rverona-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/30 09:45:53 by rverona-          #+#    #+#              #
#    Updated: 2024/04/30 09:45:54 by rverona-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = HarlFilter
SRCS = sources/main.cpp sources/HarlFilter.cpp
OBJ = $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98
RM = rm -rf

OBJ_PATH = objects/
INC = -I ./includes/

$(OBJ_PATH)%.o: %.cpp
	@mkdir -p $(dir $@)
	@c++ $(CPPFLAGS) -c $< -o $@ $(INC)

all: $(NAME)
	@echo "Program compiled."

$(NAME): $(OBJS)
	@c++ $(CPPFLAGS) -o $(NAME) $(OBJS) $(INC)

clean:
	@$(RM) $(OBJ_PATH)
	@echo "Objects cleaned."

fclean: clean
	@$(RM) $(NAME)
	@echo "Program cleaned."

re: fclean all
