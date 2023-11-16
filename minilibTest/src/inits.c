
#include "game.h"

void init_image(t_data	*image, void	*mlx)
{
	image->img = mlx_new_image(mlx, 100, 100);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel
		, &image->line_length, &image->endian);
	image->x_pos_block = 50;
	image->y_pos_block = 50;
	image->block_height = 50;
	image->block_width = 50;
}

int draw_square(t_data	*img)
{
	for (int32_t i = 0; i < 100; ++i)
	{
		for (int32_t y = 0; y < 100; ++y)
		{
			my_mlx_pixel_put(img, i, y, img->color);
		}
	}
	return (0);
}

void init_data(ptrs	*data, void	*mlx, void 	*mlx_win)
{
	(void)mlx;
	(void)mlx_win;
	data->key_pressed = 0;
}
