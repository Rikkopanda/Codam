
#ifndef GAME_H
# define GAME_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../mlx_linux/mlx.h"
//#include "GNL/get_next_line.h"
#include <inttypes.h>
#include "utils.h"

#define WIDTH 1200
#define HEIGHT 675
 
enum {
	ON_KEYDOWN = 65362,
	ON_KEYUP = 65364,
	ON_KEYRIGHT = 65363,
	ON_KEYLEFT = 65361,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	ON_ESCAPE = 65307
};

enum hex_code{
	black = 0x00000000,
	white = 0xFFFFFFFF,
	red = 0x00FF0000,
	green = 0x0000FF00,
};                                                                                            

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		y_pos_block;
	int		x_pos_block;
	int		block_width;
	int		block_height;
	int		color;
}				t_data;

typedef struct	ptr_collection {
	t_img	*img_ptr;
	t_img	*img2_ptr;
	t_img	*img_base;
	t_img	*img_backgr;
	int		y_pos_block;
	int		x_pos_block;
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
	int		key_pressed;
}				ptrs;

//------

void init_image(t_data	*image, void	*mlx);
int draw_square(t_data	*img);
void init_data(ptrs	*data, void	*mlx, void 	*mlx_win);

//------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

//------

int move_square(ptrs *data, long x_move, long y_move);

//------

int handle_input(int keysym, ptrs	*data);
int key_pressed(int keysym, ptrs	*data);


#endif