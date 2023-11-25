
SRCS = $(wildcard Libft/*.c) \
		make_stack_a.c	\
		sorting.c \
		push.c \
		rotate.c \
		reverserotate.c \
		three_sort.c \
		tools.c \
		swap.c

OBJS = $(SRCS:.c=.o)

NAME = libft.a

SAN = -g -fsanitize=address

PUSHSWAP_SRC = pushswap.c

PUSHSWAP_EXE = pushswap

PRINTFILE = printbool.txt

PRINTBOOL := $(shell if [ -e $(PRINTFILE) ]; then cat $(PRINTFILE); -else echo 0; fi)

PRINTCOMMAND = -D PRINTBOOL=$(PRINTBOOL)

.PHONY: all clean fclean re bonu

store_printbool:
	echo $(PRINTBOOL) > $(PRINTFILE)

print:
	$(eval PRINTBOOL=0)
	$(MAKE) store_printbool
	echo $(PRINTBOOL)

all: $(NAME) $(PUSHSWAP_EXE) 

san: $(PUSHSWAP_SRC) $(NAME)
	cc $(PUSHSWAP_SRC) $(NAME) $(SAN) $(PRINTCOMMAND) -o $(PUSHSWAP_EXE)

$(PUSHSWAP_EXE) : $(PUSHSWAP_SRC) $(NAME)
	cc $(PUSHSWAP_SRC)  $(NAME) $(PRINTCOMMAND) -o $(PUSHSWAP_EXE)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): %.o: %.c 
		cc -c $< -o $@

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME) $(PUSHSWAP_EXE)

re:		fclean all
