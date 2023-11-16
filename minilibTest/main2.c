
#include "game.h"

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		height;
	int		width;
}		t_win;

typedef struct s_img
{
	t_win	win;
	void	*img_ptr;
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		endian;
	int		line_len;
}		t_img;

t_win new_window(int w, int h, char *str)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	return ((t_win) {mlx_ptr, mlx_new_window(mlx_ptr, w, h, str), h, w});
}

t_img	new_img(int w, int h, t_win window)
{
	t_img	image;

	image.win = window;
	image.img_ptr = mlx_new_image(window.mlx_ptr, w, h);
	//wat doet deze???
	image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	image.w = w;
	image.h = h;
	return (image);
}

t_img	new_file_img(char * path, t_win window) {
	t_img image;

	image.win = window;
	image.img_ptr = mlx_xpm_file_to_image(window.mlx_ptr, path, &image.w, &image.h);
	if (!image.img_ptr)
		write(2, "File could not be read\n", 23);
	else
		image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			&(image.line_len), &(image.endian));
	return (image);
}


int main(void)
{
	t_win	mlx;
	void 	*mlx_win;
	t_img	img_base;
	t_img	img_bg;
	t_data	img_player;

	mlx = new_window(WIDTH, HEIGHT, "Game");
	//img_base = new_img(WIDTH, HEIGHT, mlx);

	init_image(&img_base, mlx.mlx_ptr);
	init_image(&img_bg, mlx.mlx_ptr);
	init_image(&img_player, mlx.mlx_ptr);

	img_bg = mlx_xpm_file_to_image(mlx.mlx_ptr, "pictures/sky3.xpm", &(ptrs.width), &(ptrs.height));
	img_bg = new_file_img("");
	put_img_to_img(img_base, img_bg, 0, 0);

	img_bg = new_file_img();
	put_img_to_img(img_base, img_bg, 0, 0);

}
