NAME = megaphone
SRCS = megaphone.cpp
OBJ = $(SRCS:.cpp=.o)
OBJS = $(addprefix %(OBJ_PATH), %(OBJ))

C++ = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

$(OBJ_PATH)%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(C++) $(CPPFLAGS) -c $< -o $@ $(INC)

all: $(NAME)
	@echo "Megaphone is ready!"

$(NAME): $(OBJ)
	@$(C++) $(CPPFLAGS) -o $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)
	@echo "Objects cleaned!"

fclean: clean
	@$(RM) $(NAME)
	@echo "Program cleaned!"

re: fclean all
