
LIBFTA = libft/libft.a

PS_DIR = pushswap_src/

PS_SRCS = 	$(PS_DIR)make_stack_a.c	\
		$(PS_DIR)sorting.c \
		$(PS_DIR)pushswap.c \
		$(PS_DIR)clear_stack.c \
		$(PS_DIR)pushing_nodes.c \
		$(PS_DIR)sorting_init.c \
		$(PS_DIR)sorting_tools.c \
		$(PS_DIR)set_targets.c \
		$(PS_DIR)general_tools.c \
		$(PS_DIR)commands/push.c \
		$(PS_DIR)commands/rotate.c \
		$(PS_DIR)commands/swap.c \
		$(PS_DIR)commands/reverserotate.c
PS_OBJS = $(PS_SRCS:.c=.o)
PS_EXE = push_swap
PS_A = push_swap.a

CHKR_DIR = checker_src/
CHKR_SRCS = $(PS_DIR)
CHKR_OBJS = $(CHKR_SRCS:.c=.o)
CHKR_EXE = checker
CHKR_A = checker.a

.PHONY: all clean fclean re bonus

all: $(PS_EXE)

$(PS_EXE) : $(PS_OBJS) $(LIBFTA)
	cp $(LIBFTA) $(PS_A)
	ar rcs $(PS_A) $(PS_OBJS)
	cc $(PS_A) -o $(PS_EXE)

$(PS_OBJS): %.o: %.c 
		cc -c $< -o $@

debug: $(PS_OBJS) $(LIBFTA)
	cc -c $(PS_DIR)debug.c -o debug.o
	cp $(LIBFTA) $(PS_A)
	ar rcs $(PS_A) $(PS_OBJS) debug.o
	cc $(PS_A) -o $(PS_EXE)

$(CHKR_EXE) : $(CHKR_OBJS) $(LIBFTA)
	cp $(LIBFTA) $(CHKR_A)
	ar rcs $(CHKR_A) $(CHKR_OBJS)
	cc $(CHKR_A) -o $(CHKR_EXE)

# $(CHKR_OBJS): %.o: %.c 
# 		cc -c $< -o $@

$(LIBFTA) :
	make -C libft/

clean:
		rm -f $(PS_OBJS)

fclean:	clean
		rm -f $(PS_A) $(PS_EXE)
		make fclean -C libft/

re:		fclean all
