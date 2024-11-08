NAME = fract-ol
CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf

MLX_PATH = /usr/local/lib/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)

INC = -I ./includes

SRC_PATH = sources/
SRCS = fractol.c

OBJ_PATH = objects/
OBJ = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	@echo "Compiling Fract'ol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(INC) -lX11 -lXext -lm
	@echo "Fract'ol is ready!"

clean:
	@echo "Cleaning the object files..."
	@$(RM) $(OBJ_PATH)

fclean: clean
	@echo "Cleaning Fract'ol..."
	@$(RM) $(NAME)

re: fclean all
