
GNLSRCS = $(wildcard gnl/*.c)

GNLOBJS = $(GNLSRCS:.c=.o)

SRCS = main.c  \
	parsing.c \
	draw_view.c \
	matrix_tools.c \

OBJS = $(SRCS:.c=.o)

NAME = fdf

NAME2 = fdf2

FLAGS = -g -fsanitize=address

FDF_H = fdf.h

MLX42INCL = MLX42/include

LIBA = libmlx42.a

LIBAHOME = /usr/include/MLX42/build/libmlx42.a

LIBFT = libft/libft.a

all:

$(NAME): $(GNLOBJS) $(OBJS) $(FDF_H)
	cc $(GNLOBJS) $(OBJS) $(FLAGS) $(LIBA) $(LIBFT) -I$(MLX42INCL) -ldl -lglfw -pthread -lm -o $(NAME)

$(NAME2): $(GNLOBJS) $(OBJS) $(FDF_H)
	cc $(GNLOBJS) $(OBJS) $(FLAGS) $(LIBAHOME) $(LIBFT) -Iinclude -ldl -lglfw -pthread -lm -o $(NAME2)

$(GNLOBJS): %.o: %.c
		cc $(FLAGS) -c $< -o $@

$(OBJS): %.o: %.c
		cc $(FLAGS) -c $< -o $@

clean:
	rm $(GNLOBJS) $(OBJS)

re:
	make clean
	make all
