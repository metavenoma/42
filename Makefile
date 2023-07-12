NAME = philosophers
SRCS = philosophers.c init.c utils.c exit.c
OBJ = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf

OBJ_PATH = objects/
SRCS_PATH = sources/

INC = -I ./includes

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

all: $(NAME)
	@echo "philosophers is ready!"

$(NAME): $(OBJS)
	@$(CC) -lpthread $(CFLAGS) $(OBJS) -o $(NAME) $(INC)

clean: 
	@$(RM) $(OBJ_PATH)
	@echo "objects cleaned!"

fclean:
	@$(RM) $(OBJ_PATH)
	@echo "philosophers cleaned!"

re: fclean all
