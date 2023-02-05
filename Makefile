NAME = fractol
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
ARC = ar rcs

MLX_PATH = minilibx-linux/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)

INC = -I ./includes

SRC_PATH = sources/
SRCS = complex.c exit.c help.c init.c color.c
SRCS += keyboard.c main.c mouse.c render.c 
SRCS += utils.c fractal_sets/mandelbrot.c fractal_sets/julia.c

OBJ_PATH = objects/
OBJ = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)fractal_sets/

$(MLX):
	@echo "Compiling MLX..."
	@make -sC $(MLX_PATH)

$(NAME): $(OBJS)
	@echo "Compiling Fract'ol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(INC) -lX11 -lXext -lm
	@echo "Fract'ol is ready"

clean:
	@echo "Cleaning the object files..."
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)

fclean: clean
	@echo "Cleaning Fract'ol..."
	@$(RM) $(NAME)

re: fclean all
