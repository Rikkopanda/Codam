
GNLSRCS = $(wildcard gnl/*.c)

GNLOBJS = $(GNLSRCS:.c=.o)

SRCS = main.c  \
	parsing.c

OBJS = $(SRCS:.c=.o)

NAME = fdf

FDF_H = fdf.h

LIBA = libmlx42.a

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(GNLOBJS) $(OBJS) $(FDF_H)
	gcc $(GNLOBJS) $(OBJS) $(LIBA) $(LIBFT) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)

$(GNLOBJS): %.o: %.c
		cc $(FLAGS) -c $< -o $@

$(OBJS): %.o: %.c
		cc $(FLAGS) -c $< -o $@

clean:
	rm $(GNLOBJS)

re:
	make clean
	make all
