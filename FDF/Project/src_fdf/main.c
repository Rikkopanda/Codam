// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "fdf.h"

static mlx_image_t* image;

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

void write_error()
{
	printf("map error\n");
}

int end_of_line(char c)
{
	if(c == '\n' || c == EOF)
		return (1);
	return (0);
}

double vector_len(map_data *map, int i, int j)
{
	double len_xyA_point;
	double len_Az_point;

	len_xyA_point = sqrt(pow(map->coords[i][j].xyz[0], 2) + pow(map->coords[i][j].xyz[1], 2));
	len_Az_point = sqrt(pow(len_xyA_point, 2) + pow(map->coords[i][j].xyz[2], 2));
	return (len_Az_point);
}

void assign_vectors_len(ptrs *data, int i, int j)
{
	if (j < data->map.max_width - 1)
		data->map.coords[i][j].vector_right_len = vector_len(&data->map, i, j + 1);
	if (i < data->map.max_height - 1)
		data->map.coords[i][j].vector_down_len = vector_len(&data->map, i + 1, j);
	//printf("len vector right %f, down %f\t relat.height = %d\ti j = %d %d\n\n", map->coords[i][j].vector_right_len, map->coords[i][j].vector_down_len, map->coords[i][j].relative_xyz[2], i , j);
}

void new_start_Dxy(ptrs *data, int startpos_x, int startpos_y)
{
	data->map.world_pos_Dxy[0] += startpos_y;
	data->map.world_pos_Dxy[1] += startpos_x;
}

void free_map(ptrs *data_ptrs)
{
	int j;

	j = 0;
	while (j < data_ptrs->map.max_height)
		free(data_ptrs->map.coords[j++]);
	free(data_ptrs->map.coords);
}

void init_orientation(ptrs *data, double Theta1, double Theta2, double Theta3)
{
	data->orientation.rad_angle_around_x = DEGR_TO_RAD(Theta1);
	data->orientation.rad_angle_around_y = DEGR_TO_RAD(Theta2);
	data->orientation.rad_angle_around_z = DEGR_TO_RAD(Theta3);
}

void init_view_zoom(ptrs *data, double zoom)
{
	data->view.zoom = zoom;
}

void init_model_start(ptrs *data, int xyz[3])
{
	data->map.model_in_world_pos_xyz[0] = xyz[0];
	data->map.model_in_world_pos_xyz[1] = xyz[1];
	data->map.model_in_world_pos_xyz[2] = xyz[2];
}

int32_t main(int32_t argc, char* argv[])
{
	ptrs data_ptrs;

	data_ptrs.map.world_pos_Dxy[0] = 150;
	data_ptrs.map.world_pos_Dxy[1] = 150;
	if(save_map(argv[1], &data_ptrs))
		return (1);
	data_ptrs.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	data_ptrs.img = mlx_new_image(data_ptrs.mlx, WIDTH, HEIGHT);
	set_view_data(&data_ptrs, 0, 0, 45);
	init_view_zoom(&data_ptrs, 1);
	init_orientation(&data_ptrs, 45, 45, 0);
	init_model_start(&data_ptrs, (int[3]){150, 150, 0});
	translate_map(&data_ptrs.map, &data_ptrs);
	make_draw_Dxy(&data_ptrs);
	//draw_axes(&data_ptrs);
	mlx_key_hook(data_ptrs.mlx, keypressed, &data_ptrs);
	mlx_image_to_window(data_ptrs.mlx, data_ptrs.img, 50, 50);
	mlx_loop(data_ptrs.mlx);
	mlx_terminate(data_ptrs.mlx);
	free_map(&data_ptrs);
	return (EXIT_SUCCESS);
}
	// printf("value before %f\n\n", data_ptrs.orientation.rad_angle_around_x);