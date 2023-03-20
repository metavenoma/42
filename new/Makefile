CLIENT_NAME = client
CLIENT_SRCS = sources/client.c
CLIENT_OBJ = $(CLIENT_SRCS:.c=.o)
CLIENT_OBJS = $(addprefix $(OBJ_PATH), $(CLIENT_OBJ))

SERVER_NAME = server
SERVER_SRCS = sources/server.c
SERVER_OBJ = $(SERVER_SRCS:.c=.o)
SERVER_OBJS = $(addprefix $(OBJ_PATH), $(SOURCE_OBJ))

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
ARC = ar rcs

OBJS_PATH = objects/

INC = -I ./includes

SRC_PATH = sources/
SRCS = complex.c exit.c help.c init.c color.c
SRCS += keyboard.c main.c mouse.c render.c 
SRCS += utils.c fractal_sets/mandelbrot.c fractal_sets/julia.c
SRCS += fractal_sets/burning_ship.c fractal_sets/tricorn.c
SRCS += fractal_sets/celtic_mandelbrot.c fractal_sets/perpendicular_buffalo.c
SRCS += fractal_sets/perpendicular_mandelbrot.c fractal_sets/celtic_mandelbar.c
SRCS += fractal_sets/perpendicular_burning_ship.c
SRCS += fractal_sets/celtic_perpendicular.c

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)
	@mkdir $(OBJ_PATH)fractal_sets/

$(NAME): $(OBJS)
	@echo "Compiling Fract'ol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(INC) -lX11 -lXext -lm
	@echo "Fract'ol is ready"

clean:
	@echo "Cleaning the object files..."
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "Cleaning Fract'ol..."
	@$(RM) $(NAME)

re: fclean all
