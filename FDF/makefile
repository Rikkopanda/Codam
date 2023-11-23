
GNLSRCS = $(wildcard gnl/*.c)

GNLOBJS = $(GNLSRCS:.c=.o)

SRCS = main.c  \
	parsing.c

OBJS = $(SRCS:.c=.o)

NAME = fdf

FDF_H = fdf.h

MLX42INCL = MLX42/include

LIBA = MLX42/build/libmlx42.a

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(GNLOBJS) $(FDF_H)
	cc $(GNLOBJS) $(OBJS) $(LIBA) $(LIBFT) -I$(MLX42INCL) -ldl -lglfw -pthread -lm -o $(NAME)

$(GNLOBJS): %.o: %.c
		cc $(FLAGS) -c $< -o $@

$(OBJS): %.o: %.c
		cc $(FLAGS) -c $< -o $@

clean:
	rm $(GNLOBJS) $(OBJS)

re:
	make clean
	make all
