
#include "game.h"



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
	data->key_pressed = keysym;
	if (keysym == ON_KEYRIGHT)
		move_square(data, 10, 0);
	if (keysym == ON_KEYLEFT)
		move_square(data, -10, 0);
	if (keysym == ON_KEYDOWN)
		move_square(data, 0, -10);
	if (keysym == ON_KEYUP)
		move_square(data, 0, 10);
	printf("The %d key has been pressed\n\n", keysym);

    return (0);
}

int key_released(ptrs	*data)
{
	data->key_pressed = 0;
	printf("The %d keynow\n\n", data->key_pressed);
	return (0);
}
//int	key_hook(int keycode, t_vars *vars)
//{
//	printf("Hello from key_hook!\n");
//	return (0);
//}


//char **read_file(char *file_str)
//{
//	char *next_line;
//	int fd;
//	int fd2;
//	char total[150000];

//	fd2 = open("../pictures/monkey01.xpm", O_RDONLY);
//	next_line = (char *)1;
//	total[0] = '\0';
//	while(next_line != NULL)
//	{	
//		next_line = get_next_line(fd);
//		if(next_line != NULL)
//		{
//			putstr(next_line);
//			strcat(total, next_line);
//		}
//		free(next_line);
//	}
//}

int main(void)
{
	void	*mlx;
	void 	*mlx_win;
	t_data	img;
	t_data	img2;
	t_data	img_backgr;
	t_data	img_erase;
	ptrs	ptrs;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Mooi Window");
	init_image(&img, mlx);
	init_image(&img2, mlx);
	img.color = red;
	init_image(&img_erase, mlx);
	img_erase.color = black;
	//draw_square(&img_erase);
	//draw_square(&img);
	//char **xmp_data;

	ptrs.height = HEIGHT;
	ptrs.width = WIDTH;
	ptrs.mlx_ptr = mlx;
	ptrs.win_ptr = mlx_win;
	ptrs.img_ptr = &img;
	ptrs.img2_ptr = &img2;
	ptrs.img_erase_ptr = &img_erase;
	ptrs.x_pos_block = 50;
	ptrs.y_pos_block = 50;
	//img.bits_per_pixel = 8;
	//img_backgr.bits_per_pixel = 8;
	init_data(&ptrs, mlx, mlx_win);
	img_backgr.img = mlx_xpm_file_to_image(mlx, "pictures/sky3.xpm", &(ptrs.width), &(ptrs.height));
	img.img = mlx_xpm_file_to_image(mlx, "pictures/monkey01.xpm", &(ptrs.width), &(ptrs.height));
	img2.img = mlx_xpm_file_to_image(mlx, "pictures/monkey02left.xpm", &(ptrs.width), &(ptrs.height));
	ptrs.img_backgr = &img_backgr;
	mlx_put_image_to_window(mlx, mlx_win, img_backgr.img, 0, 0);
	mlx_put_image_to_window(mlx, mlx_win, img.img, ptrs.x_pos_block, ptrs.y_pos_block);

	//mlx_key_hook(mlx_win, handle_input, &ptrs);
	//mlx_mouse_hook(mlx_win, handle_input, &ptrs);
	mlx_hook(mlx_win, 2, 1L<<0, key_pressed, &ptrs);
	//mlx_hook(mlx_win, 3, 1L<<1, key_released, &ptrs);
	mlx_loop(mlx);
	return (EXIT_SUCCESS);
}
