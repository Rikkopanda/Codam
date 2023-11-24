// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "fdf.h"

static mlx_image_t* image;

// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
	for (int32_t i = 0; i < image->width; ++i)
	{
		for (int32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

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

void assign_relative_coord(ptrs *data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	data->map.coords[i][j].relative_xyz[0] = 0;
	data->map.coords[i][j].relative_xyz[1] = 0;
	data->map.coords[i][j].relative_xyz[2] = 0;
	data->map.coords[i][j].origin_point_i = 0;
	data->map.coords[i][j].origin_point_j = 0;
	while (i < data->map.max_height)
	{
		while (j < data->map.max_width)
		{
			point A;
			point B;
			point C;
			point D;

			A = data->map.coords[i][j];
			if(j != data->map.max_width - 1)
				B = data->map.coords[i][j + 1];
			if(i != data->map.max_height - 1)
				C = data->map.coords[i + 1][j];
			if(j != data->map.max_width - 1)
			{
				B.relative_xyz[0] = B.xyz[0] - A.xyz[0];
				B.relative_xyz[1] = B.xyz[1] - A.xyz[1];
				B.relative_xyz[2] = B.xyz[2] - A.xyz[2];
				B.origin_point_i = i;
				B.origin_point_j = j;
				// printf(" i j %d %d, origi i j %d %d\n", i, j, B.origin_point_i, B.origin_point_j);
				data->map.coords[i][j + 1] = B;
			}
			if(j == 0 && i != data->map.max_height - 1)
			{
				C.relative_xyz[0] = C.xyz[0] - A.xyz[0];
				C.relative_xyz[1] = C.xyz[1] - A.xyz[1];
				C.relative_xyz[2] = C.xyz[2] - A.xyz[2];
				C.origin_point_i = i;
				C.origin_point_j = j;
				data->map.coords[i + 1][j] = C;
			}
			// printf("\nxyz rel A %d %d %d i j = %d %d origi i j = %d %d\n", A.relative_xyz[0], A.relative_xyz[1], A.relative_xyz[2], i, j, A.origin_point_i, A.origin_point_j);
			// printf("xyz rel C %d %d %d  i j = %d %d\n", C.relative_xyz[0], C.relative_xyz[1], C.relative_xyz[2], i + 1, j);
			// printf("xyz rel B %d %d %d i j = %d %d\n", B.relative_xyz[0], B.relative_xyz[1], B.relative_xyz[2], i, j + 1);
			j++;
		}
		j = 0;
		i++;
	}
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

void offset_draw(map_data *map, int i, int j)
{
	map->coords[i][j].xyz[0] += map->start_pos_x;
	map->coords[i][j].xyz[1] += map->start_pos_y;
}

//void draw_xy_projection(ptrs *data)
//{
//	int i;
//	int j;

//	i = 0;
//	j = 0;

//	data->map.coords[i][j].draw_xy[0] = data->map.coords[i][j].draw_xy[0]            
//}

void init_R_around_Z(double R[3][3], char axis, double rad)
{
	(void)axis;
	R[0][0]  = rad;
	R[0][1]  = -rad;
	R[0][2]  = 0;
	R[1][0]  = rad;
	R[1][1]  = rad;
	R[1][2]  = 0;
	R[2][0]  = 0;
	R[2][1]  = 0;
	R[2][2]  = 1;
}

void init_R_around_Y(double R[3][3], char axis, double rad)
{
	(void)axis;
	R[0][0]  = rad;
	R[0][1]  = 0;
	R[0][2]  = rad;
	R[1][0]  = 0;
	R[1][1]  = 1;
	R[1][2]  = 0;
	R[2][0]  = 0;
	R[2][1]  = 0;
	R[2][2]  = 0;
}

void init_R_around_X(double R[3][3], char axis, double rad)
{
	(void)axis;
	R[0][0]  = 1;
	R[0][1]  = 0;
	R[0][2]  = 0;
	R[1][0]  = 0;
	R[1][1]  = 0;
	R[1][2]  = rad;
	R[2][0]  = 0;
	R[2][1]  = 0;
	R[2][2]  = rad;
}

//void init_result(double M[])
//{
	
//}

void translate_map(map_data *map, ptrs *data)
{
	int j;
	int i;
	int k;
	int l;
	int m;

	i = 0;
	j = 1;
	//double T[2] = {val_1, val_2};
	//double T2[2] = {val_2, val_1};
	//double T[3][3] = {val_1, val_2};
	//double T2[3][3] = {val_2, val_1};
	int result[3];
	printf("hello");
	k = 0;
	l = 0;
	m = 0;
	double R2[2][2] = {{0,-1},{1, 0}};
	double R[3][3];
	double R3[3][3];
	double R4[3][3];
	double comp[3][3];
	double comp2[3][3];
	init_R_around_Z(R, 'z', DEGR_TO_RAD(data->orientation.rad_angle_around_z));
	init_R_around_Y(R3, 'z', DEGR_TO_RAD(data->orientation.rad_angle_around_y));
	init_R_around_X(R4, 'z', DEGR_TO_RAD(45));
	compilation_matrix(comp, R, R3);
	compilation_matrix(comp2, comp, R4);
	//init_result(result);
	for (int i = 0; i < 3; ++i)
			result[i] = 0;
	//offset_draw(map, i, j);
	while (i < map->max_height)
	{
		while (j < map->max_width)
		{	
			//ffset_draw(map, i, j);
			//offset_draw(map, i + 1, j);
			//offset_draw(map, i, j + 1);
			while (l < 3)
			{
				while (m < 3)
				{			
					if(map->coords[i][j].origin_point_i < i)
						result[l] += map->coords[i][j].relative_xyz[m] * R[m][l];
					else
						result[l] += map->coords[i][j].relative_xyz[m] * R[m][l];
					m++;
				}
				m = 0;
				l++;
			}
			l = 0;
			while (l < 3)
			{
				if(j == 0)
					map->coords[i][j].xyz[l] = map->coords[i - 1][j].xyz[l] + result[l];
				else
					map->coords[i][j].xyz[l] = map->coords[i][j - 1].xyz[l] + result[l];
				l++;
			}
			l = 0;
			// printf("xy new %d %d origin i j = %d %d\n", result[0], result[1], map->coords[i][j].origin_point_i, map->coords[i][j].origin_point_j);
			// printf("absulote xy new %d %d\n", map->coords[i][j].xyz[0], map->coords[i][j].xyz[1]);
			j++;
			for (int i = 0; i < 3; ++i)
				result[i] = 0;
		}
		printf("\n\n");
		j = 0;
		i++;
	}
}

void new_start_Dxy(ptrs *data, int startpos_x, int startpos_y)
{
	data->map.start_pos_y += startpos_y;
	data->map.start_pos_x += startpos_x;
}

void keypressed(mlx_key_data_t key_data, void *data_ptrs)
{
	ptrs *data = (ptrs *)data_ptrs;

	static double t_const1 = 0;
	static double t_const2 = 0;
	printf("key pressed = %d \n", key_data.key);
	printf("value %f\n\n", data->view.rad_angle_around_z);
	int startpos_x;
	int startpos_y;
	startpos_x = 0;
	startpos_y = 0;
	if (key_data.key == ON_A)
		startpos_x = -10;
	else if(key_data.key == ON_W)
		startpos_y = -10;
	else if(key_data.key == ON_D)
		startpos_x = 10;
	else if(key_data.key == ON_S)
		startpos_y = 10;
	else if (key_data.key == ON_KEYRIGHT)
	{
		make_draw_Dxy(data, (int)black);
		//data->orientation.rad_angle_around_z += DEGR_TO_RAD(90);
		//data->orientation.rad_angle_around_y -= DEGR_TO_RAD(90);
		//data->view.rad_angle_around_y -= DEGR_TO_RAD(10);
		data->view.rad_angle_around_y -= DEGR_TO_RAD(10);
		printf("value %f\n\n", data->view.rad_angle_around_z);
		//printf("valu");
	}	
	else if (key_data.key == ON_KEYLEFT)
	{
		make_draw_Dxy(data, (int)black);
		//data->view.rad_angle_around_y -= DEGR_TO_RAD(10);
		data->view.rad_angle_around_y += DEGR_TO_RAD(10);
		//data->orientation.rad_angle_around_z -= DEGR_TO_RAD(90);
		//data->orientation.rad_angle_around_y += DEGR_TO_RAD(90);
		printf("value %f\n\n", data->view.rad_angle_around_z);
		//printf("valu");
	}
	else
		return ;
	make_draw_Dxy(data, (int)black);
	//if((key_data.key == ON_KEYRIGHT || (key_data.key == ON_KEYLEFT)))
	//	translate_map(&data->map, data);
	new_start_Dxy((ptrs *)data_ptrs, startpos_x, startpos_y);
	//set_view_data(data, 45, 45);
	make_draw_Dxy(data, (int)white);
	//printf("1 = %d  2 = %d\n", data->pos_x, data->pos_y);
	//mlx_image_to_window(data->mlx, data->img, data->pos_x, data->pos_y);
}

void free_map(ptrs *data_ptrs)
{
	int j;

	j = 0;
	while (j < data_ptrs->map.max_height)
		free(data_ptrs->map.coords[j++]);
	free(data_ptrs->map.coords);
}

void init_orientation(ptrs *data, double angle1, double angle2)
{
	data->orientation.rad_angle_around_z = angle1;
	data->orientation.rad_angle_around_y = angle2;
}

int32_t main(int32_t argc, char* argv[])
{
	ptrs data_ptrs;

	data_ptrs.map.start_pos_x = 120;
	data_ptrs.map.start_pos_y = 120;
	if(save_map(argv[1], &data_ptrs))
		return (1);
	// Gotta error check this stuff
	//printf("hoiaaaaa\n");
	data_ptrs.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	data_ptrs.img = mlx_new_image(data_ptrs.mlx, WIDTH, HEIGHT);
	data_ptrs.t_const1 = 1;
	data_ptrs.t_const2 = 0;
	data_ptrs.pos_x = 50;
	set_view_data(&data_ptrs, 45, 45);
	init_orientation(&data_ptrs, 0, 0);
	//printf("hois %i");
	// translate_map(&data_ptrs.map, data_ptrs.t_const1, data_ptrs.t_const2);
	make_draw_Dxy(&data_ptrs, (int)white);
	//draw_map(&data_ptrs, (int)white);
	mlx_key_hook(data_ptrs.mlx, keypressed, &data_ptrs);
	mlx_image_to_window(data_ptrs.mlx, data_ptrs.img, 50, 50);
	mlx_loop(data_ptrs.mlx);
	// // mlx_delete_image(mlx, img);
	mlx_terminate(data_ptrs.mlx);
	// free_map(&data_ptrs);
	return (EXIT_SUCCESS);
}
