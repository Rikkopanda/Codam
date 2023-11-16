

SRCS = $(wildcard src/*.c) \
	 $(wildcard libft/*.c)

OBJS = $(SRCS:.c=.o)

NAME = Game

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -I../mlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJS): %.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm $(NAME) $(OBJS)

re: clean all
