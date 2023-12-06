
#include "fdf.h"

int check_if_translate(mlx_key_data_t key_data)
{

    if(key_data.key == ON_Q
        || key_data.key == ON_W
        || key_data.key == ON_E
        || key_data.key == ON_A
        || key_data.key == ON_S
        || key_data.key == ON_D
        || key_data.key == ON_PLUS
        || key_data.key == ON_MINUS	
		)
        return (1);
    return (0);
}

void keypressed(mlx_key_data_t key_data, void *data_ptrs)
{
	ptrs *data = (ptrs *)data_ptrs;
		clock_t start_t, end_t;
	double total_t;


	start_t = clock();
	static double t_const1 = 0;
	static double t_const2 = 0;
	printf("key pressed = %d \n", key_data.key);
	//printf("value %f\n\n", data->view.rad_angle_around_z);
	int startpos_x;
	int startpos_y;
	startpos_x = 0;
	startpos_y = 0;
	if (key_data.key == ON_KEYLEFT)
		data->map.model_in_world_pos_xyz[1] -= 10;
	else if(key_data.key == ON_KEYUP)
		data->map.model_in_world_pos_xyz[0] += 10;
	else if(key_data.key == ON_KEYRIGHT)
		data->map.model_in_world_pos_xyz[1] += 10;
	else if(key_data.key == ON_KEYDOWN)
		data->map.model_in_world_pos_xyz[0] -= 10;
	else if (key_data.key == ON_D)
		data->orientation.rad_angle_around_x += DEGR_TO_RAD(20);
	else if (key_data.key == ON_A)
		data->orientation.rad_angle_around_x -= DEGR_TO_RAD(20);
	else if (key_data.key == ON_Q)
		data->orientation.rad_angle_around_y += DEGR_TO_RAD(20);
	else if (key_data.key == ON_E)
		data->orientation.rad_angle_around_y -= DEGR_TO_RAD(20);
	else if (key_data.key == ON_W)
		data->orientation.rad_angle_around_z += DEGR_TO_RAD(20);
	else if (key_data.key == ON_S)
		data->orientation.rad_angle_around_z -= DEGR_TO_RAD(20);
	else if (key_data.key == ON_I)
		data->view.rad_angle_around_y -= DEGR_TO_RAD(10);
	else if (key_data.key == ON_K)
		data->view.rad_angle_around_y += DEGR_TO_RAD(10);
	else if (key_data.key == ON_J)
		data->view.rad_angle_around_z -= DEGR_TO_RAD(10);
	else if (key_data.key == ON_L)
		data->view.rad_angle_around_z += DEGR_TO_RAD(10);
	else if (key_data.key == ON_U)
		data->view.rad_angle_around_x -= DEGR_TO_RAD(10);
	else if (key_data.key == ON_O)
		data->view.rad_angle_around_x += DEGR_TO_RAD(10);
	else if (key_data.key == ON_PLUS)
		data->view.zoom += 0.05;
	else if (key_data.key == ON_MINUS)
		data->view.zoom -= 0.05;
	else
		return ;
	clear_img(data->img, WIDTH, HEIGHT);
	if(check_if_translate(key_data))
		translate_map(&data->map, data);
	new_start_Dxy((ptrs *)data_ptrs, startpos_x, startpos_y);
	make_draw_Dxy(data);
	draw_axes(data);
	end_t = clock();
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	// printf("Total time taken by CPU: %f\n", total_t  );
}
// data->view.rad_angle_around_x += DEGR_TO_RAD(10);
// printf("\n\nvalue after %f\n\n", data->orientation.rad_angle_around_x);