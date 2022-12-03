NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -I
RM = rm -f
ARC = ar rcs
SRCS = ft_printf.c printchar.c printstr.c printptr.c
SRCS += printnbr.c printunsigned.c printhex.c 
OBJS = $(SRCS:.c=.o)
INCLUDE = include

all: $(NAME)

$(NAME): $(OBJS)
	@$(ARC) $(NAME) $(OBJS)

$(OBJS): $(SRCS) $(INCLUDE)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $(SRCS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

