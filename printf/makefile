
SRCS = $(wildcard lib/*.c)

OBJS = $(SRCS:.c=.o)

NAME = fprints.a


$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	gcc $(FLAGS) -c $< -o $@