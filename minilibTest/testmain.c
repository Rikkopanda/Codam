#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mlx_linux/mlx.h"
#include <inttypes.h>

#define WIDTH 1000
#define HEIGHT 1000

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
}				t_data;

typedef struct	ptr_collection {
	t_data	*img_buffer_ptr;
	void	*mlx_ptr;
	void	*win_ptr;
}				ptrs;

int redraw_square(t_data	*img, int color);

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

/*	set color of pixel on desired loctation.
*/
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = (y * data->line_length + x * (data->bits_per_pixel / 8));
	dst = data->addr + offset;
	*(unsigned int*)dst = color;
}


int move_square(ptrs *data, long x_move, long y_move)
{
	redraw_square(data->img_buffer_ptr, black);
	data->img_buffer_ptr->x_pos_block += x_move;
	data->img_buffer_ptr->y_pos_block += y_move;
	//printf("move to right \t %d \n", data->img_buffer_ptr->x_pos_block);
	redraw_square(data->img_buffer_ptr, red);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_buffer_ptr->img, 0, 0);
	return (0);
}

int handle_input(int keysym, ptrs	*data)
{

    if (keysym == ON_ESCAPE)
    {
        printf("The %d key (ESC) has been pressed\n\n", keysym);
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        exit(1);
    }
	if (keysym == ON_KEYRIGHT)
		move_square(data, 50, 0);
	if (keysym == ON_KEYLEFT)
		move_square(data, -50, 0);
	if (keysym == ON_KEYDOWN)
		move_square(data, 0, -50);
	if (keysym == ON_KEYUP)
		move_square(data, 0, 50);
    printf("The %d key has been pressed\n\n", keysym);
    return (0);
}


int key_pressed(int keysym, ptrs	*data)
{
	if (keysym == ON_KEYRIGHT)
		move_square(data, 1, 0);
	if (keysym == ON_KEYLEFT)
		move_square(data, -1, 0);
	if (keysym == ON_KEYDOWN)
		move_square(data, 0, -1);
	if (keysym == ON_KEYUP)
		move_square(data, 0, 1);
    //printf("The %d key has been pressed\n\n", keysym);
    return (0);
}

//int	key_hook(int keycode, t_vars *vars)
//{
//	printf("Hello from key_hook!\n");
//	return (0);
//}

int draw_square(t_data	*img, int color)
{
	long height = img->y_pos_block + img->block_height;
	long width = img->x_pos_block + img->block_width;

	//printf("in func x pos = %lu, pos len %lu 5d\n", width, height);
	for (int32_t i = img->x_pos_block; i < width; ++i)
	{
		//rintf("in func p2\n");p
		for (int32_t y = img->y_pos_block; y < height; ++y)
		{
			printf("in draw funct i = %d y = %d \n", i, y);
			my_mlx_pixel_put(img, i, y, color);
		}
	}
	return (0);
}

int redraw_square(t_data	*img, int color)
{
	//erase_square(img);
	draw_square(img, color);
	return (0);
}

int main(void)
{
	void	*mlx;
	void 	*mlx_win;
	t_data	img;
	ptrs	ptrs;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Mooi Window");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	//img.bits_per_pixel = 3;
	ptrs.mlx_ptr = mlx;
	ptrs.win_ptr = mlx_win;
	ptrs.img_buffer_ptr = &img;
	img.x_pos_block = 50;
	img.y_pos_block = 50;

	img.block_width = img.x_pos_block + 100;
	img.block_height = img.y_pos_block + 100;

	draw_square(&img, red);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	//mlx_key_hook(mlx_win, handle_input, &ptrs);
	//mlx_mouse_hook(mlx_win, handle_input, &ptrs);
	mlx_hook(mlx_win, 2, 1L<<0, key_pressed, &ptrs);
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}
