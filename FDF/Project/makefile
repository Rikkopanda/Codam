
GNLSRCS = $(wildcard gnl/*.c)

GNLOBJS = $(GNLSRCS:.c=.o)

SRCDIR = src_fdf/

SRCS = $(SRCDIR)main.c  \
	$(SRCDIR)parsing_copy.c \
	$(SRCDIR)draw_view.c \
	$(SRCDIR)matrix_tools.c \
	$(SRCDIR)tools.c \
	$(SRCDIR)hooks.c \
	$(SRCDIR)build_map.c \
	$(SRCDIR)build_model.c \
	$(SRCDIR)transform_model.c

OBJS = $(SRCS:.c=.o)

NAME = fdf

NAME2 = fdf2

FLAGS = -g -fsanitize=address

FDF_H = $(SRCDIR)fdf.h

MLX42INCL = MLX42/include

LIBA = archives/libmlx42.a

LIBAHOME = /usr/include/MLX42/build/libmlx42.a

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(GNLOBJS) $(OBJS) $(FDF_H)
	make -C libft/
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
