
#include "game.h"

int move_square(ptrs *data, long x_move, long y_move)
{
	//redraw_square(data->img_buffer_ptr, black);
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_erase_ptr->img
	//		, data->x_pos_block, data->y_pos_block);
	//mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_backgr->img_ptr, 0, 0);

	data->x_pos_block += x_move;
	data->y_pos_block += y_move;
	//printf("move to right \t %d \n", data->img_buffer_ptr->x_pos_block);
	//redraw_square(data->img_buffer_ptr, red);
	put_img_to_img(*(data->img_base), *(data->img_backgr), 0, 0);
	put_img_to_img(*(data->img_base), *(data->img_ptr), data->x_pos_block, data->y_pos_block);
	if(x_move < 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_base->img_ptr
			, 0, 0);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_base->img_ptr
			, 0, 0);
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
	if (keysym == ON_ESCAPE)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_loop_end(data->mlx_ptr);
	}
	printf("The %d key has been pressed\n\n", keysym);
    return (0);
}