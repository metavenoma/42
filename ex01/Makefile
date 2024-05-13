NAME = hello_kitty
SRCS = sources/hello_kitty.cpp sources/Contact.cpp sources/PhoneBook.cpp
OBJ = $(SRCS:.cpp=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

C++ = c++
CPPFLAGS = -Wall -Wextra -Werror -g -std=c++98
RM = rm -rf

OBJ_PATH = objects/
INC = -I ./includes/

$(OBJ_PATH)%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(C++) $(CPPFLAGS) -c $< -o $@ $(INC)

all: $(NAME)
	@echo "Hello, Kitty!"

$(NAME): $(OBJS)
	@$(C++) $(CPPFLAGS) -o $(NAME) $(OBJS) $(INC)

clean:
	@$(RM) $(OBJ_PATH)
	@echo "Objects cleaned!"

fclean: clean
	@$(RM) $(NAME)
	@echo "Goodbye, Kitty!"

re: fclean all
