

MAIN_SRCS= pipex.c	\
		cmd1.c \
		gnl/get_next_line.c \
		gnl/get_next_line_utils.c

M_OBJS = $(MAIN_SRCS:.c=.o)

M_A = pipex.a

M_EXE = pipex

SUBPROGRAM1_SRCS = new_program.c

SP1_OBJS = $(SUBPROGRAM1_SRCS:.c=.o)

SP1_A = sp1.a

SP1_EXE = sp1_exe

LIBFTA = libft/libft.a

FLAGS = -Wall

all: $(M_EXE) $(SP1_EXE)

$(M_EXE): $(M_OBJS)
	make -C libft/
	cp $(LIBFTA) $(M_A)
	ar rcs $(M_A) $(M_OBJS)
	cc $(M_A) -o $(M_EXE)

$(M_OBJS): %.o: %.c
		cc -c $< -o $@

$(SP1_EXE): $(SP1_OBJS)
	make -C libft/
	cp $(LIBFTA) $(SP1_A)
	ar rcs $(SP1_A) $(SP1_OBJS)
	cc $(SP1_A) -o $(SP1_EXE)

$(SP1_OBJS): %.o: %.c
		cc -c $< -o $@

clean:
	rm $(SP1_OBJS) $(M_OBJS)
	rm $(SP1_EXE) $(M_EXE)

fclean:
	make clean
	make fclean -C libft/

re:
	make fclean
	make