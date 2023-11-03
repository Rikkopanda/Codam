
SRCS = $(wildcard Libft/*.c) \
		make_stack_a.c	\
		sorting.c \
		push.c \
		rotate.c

OBJS = $(SRCS:.c=.o)

NAME = libft.a

PUSHSWAP_SRC = pushswap.c

PUSHSWAP_EXE = pushswap

.PHONY: all clean fclean re bonus

all: $(NAME) $(PUSHSWAP_EXE) 

san: $(PUSHSWAP_SRC) $(NAME)
	cc $(PUSHSWAP_SRC) $(NAME) -o $(PUSHSWAP_EXE)

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
