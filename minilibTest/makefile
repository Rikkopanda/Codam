

SRCS = $(wildcard src/*.c) \
		$(wildcard libft/*.c)

OBJS = $(SRCS:.c=.o)

NAME = Game

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx_linux -lmlx_Linux -no-pie -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(OBJS): %.o: %.c
	$(CC)  -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm $(NAME) $(OBJS)

re: clean all
	