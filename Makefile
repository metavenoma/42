NAME = push_swap
SRCS = push_swap.c nodes.c push.c reverse_rotate.c
SRCS += stacks.c swap.c rotate.c terminate.c validate.c
SRCS += small_stack_sort.c radix_sort.c
OBJ = $(SRCS:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
LIB = libft/libft.a
RM = rm -rf

OBJ_PATH = objects/
SRCS_PATH = sources/

INC = -I ./includes

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

all: libft $(NAME)
	@echo "push_swap is ready!"

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB) $(INC)

libft: $(LIB)

$(LIB):
	@make -C libft --no-print-directory

libft_fclean:
	@make fclean -C libft --no-print-directory

clean:	libft_fclean
	@$(RM) $(OBJ_PATH)
	@echo "Objects cleaned!"

fclean: clean
	@$(RM) $(NAME)
	@echo "push_swap cleaned!"

re: fclean all
