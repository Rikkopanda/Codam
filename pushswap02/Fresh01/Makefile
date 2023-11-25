
SRCS = $(wildcard Libft/*.c) \
		commands/rotate.c \
		commands/reverserotate.c \
		commands/push.c \
		commands/swap.c \
		src/make_stack_a.c	\
		src/sorting.c \
		src/clear_stack.c \
		src/pushing_nodes.c \
		src/set_targets.c \
		src/general_tools.c \
		src/sorting_tools.c \
		src/sorting_init.c

OBJS = $(SRCS:.c=.o)

NAME = libft.a

SAN = -g -fsanitize=address

PUSHSWAP_SRC = pushswap.c

PUSHSWAP_EXE = pushswap

.PHONY: all clean fclean re bonu

all: $(NAME) $(PUSHSWAP_EXE) 

san: $(PUSHSWAP_SRC) $(NAME)
	cc $(PUSHSWAP_SRC) $(NAME) $(SAN) -o $(PUSHSWAP_EXE)

$(PUSHSWAP_EXE) : $(PUSHSWAP_SRC) $(NAME)
	cc $(PUSHSWAP_SRC)  $(NAME) -o $(PUSHSWAP_EXE)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): %.o: %.c 
		cc -c $< -o $@

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME) $(PUSHSWAP_EXE)

re:		fclean all
