CLIENT_NAME = client
CLIENT_SRCS = sources/client.c
CLIENT_OBJ = $(CLIENT_SRCS:.c=.o)
CLIENT_OBJS = $(addprefix $(OBJ_PATH), $(CLIENT_OBJ))

SERVER_NAME = server
SERVER_SRCS = sources/server.c
SERVER_OBJ = $(SERVER_SRCS:.c=.o)
SERVER_OBJS = $(addprefix $(OBJ_PATH), $(SERVER_OBJ))

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = libft/libft.a
RM = rm -rf

OBJ_PATH = objects/
SRCS_PATH = sources/

INC = -I ./includes

SRC_PATH = sources/

$(OBJ_PATH)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

all: libft $(CLIENT_NAME) $(SERVER_NAME)
	@echo "Minitalk is ready!"

$(SERVER_NAME): $(SERVER_OBJS)
	@$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER_NAME) $(LIB) $(INC)

$(CLIENT_NAME): $(CLIENT_OBJS)
	@$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT_NAME) $(LIB) $(INC)

libft: $(LIB)

$(LIB):
	@make -C libft --no-print-directory

libft_fclean:
	@make fclean -C libft --no-print-directory

clean:	libft_fclean
	@$(RM) $(OBJ_PATH)
	@echo "Objects cleaned!"

fclean: clean
	@$(RM) $(CLIENT_NAME)
	@$(RM) $(SERVER_NAME)
	@echo "Programs cleaned!"

re: fclean all
