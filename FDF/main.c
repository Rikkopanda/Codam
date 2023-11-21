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
#define _USE_MATH_DEFINES
# define M_PI           3.14159265358979323846



void put_line(mlx_image_t *image_ptr, point A, point B, unsigned int color)
{
	int x_len = B.xyz[0] - A.xyz[0];
	int y_len = B.xyz[1] - A.xyz[1];
	double angle = ((180/M_PI) * atan(x_len / y_len));
	double i_angle;
	// 
	printf("angle %f \n", (angle));

	//make delta x en y


	for(int x = A.xyz[0]; x < B.xyz[0]; x++)
	{
		for(int y = A.xyz[1]; y < B.xyz[1]; y++)
		{
			x_len = x - A.xyz[0];
			y_len = y - A.xyz[1];
			if(x_len && y_len)
				i_angle = ((180/M_PI) * atan(x_len / y_len));
			// printf("angle %d \n", i_angle);
			if(angle == i_angle)
			{
				printf("angle %f \n", i_angle);
				mlx_put_pixel(image_ptr, x, y, color);
			}
		}
	}
}


static void	draw_line(mlx_image_t *fdf, point f, point s, int color)
{
	point	delta;
	point	sign_dir;
	point	cur;
	int		error[2];

	delta.xyz[0] = FT_ABS(s.xyz[0] - f.xyz[0]);
	delta.xyz[1] = FT_ABS(s.xyz[1] - f.xyz[1]);
	sign_dir.xyz[0] = f.xyz[0] < s.xyz[0] ? 1 : -1;
	sign_dir.xyz[1] = f.xyz[1] < s.xyz[1] ? 1 : -1;
	error[0] = delta.xyz[0] - delta.xyz[1];
	cur = f;
	while (cur.xyz[0] != s.xyz[0] || cur.xyz[1] != s.xyz[1])
	{
		if((cur.xyz[0] >= 0 && cur.xyz[1] >= 0) && (cur.xyz[0] <= WIDTH && cur.xyz[1] <= HEIGHT))
			mlx_put_pixel(fdf, cur.xyz[0], cur.xyz[1], color);
		if ((error[1] = error[0] * 2) > -delta.xyz[1])
		{
			error[0] -= delta.xyz[1];
			cur.xyz[0] += sign_dir.xyz[0];
		}
		if (error[1] < delta.xyz[0])
		{
			error[0] += delta.xyz[0];
			cur.xyz[1] += sign_dir.xyz[1];
		}
	}
}

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

void assign_relative_coord(map_data *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	map->coords[i][j].relative_xyz[0] = 0;
	map->coords[i][j].relative_xyz[1] = 0;
	map->coords[i][j].relative_xyz[2] = 0;
	map->coords[i][j].origin_point_i = 0;
	map->coords[i][j].origin_point_j = 0;
	while (i < map->max_height)
	{
		while (j < map->max_width)
		{
			point A;
			point B;
			point C;
			point D;

			A = map->coords[i][j];
			if(j != map->max_width - 1)
				B = map->coords[i][j + 1];
			if(i != map->max_height - 1)
				C = map->coords[i + 1][j];
			if(j != map->max_width - 1)
			{
				B.relative_xyz[0] = B.xyz[0] - A.xyz[0];
				B.relative_xyz[1] = B.xyz[1] - A.xyz[1];
				B.relative_xyz[2] = B.xyz[2] - A.xyz[2];
				B.origin_point_i = i;
				B.origin_point_j = j;
				// printf(" i j %d %d, origi i j %d %d\n", i, j, B.origin_point_i, B.origin_point_j);
				map->coords[i][j + 1] = B;
			}
			if(j == 0 && i != map->max_height - 1)
			{
				C.relative_xyz[0] = C.xyz[0] - A.xyz[0];
				C.relative_xyz[1] = C.xyz[1] - A.xyz[1];
				C.relative_xyz[2] = C.xyz[2] - A.xyz[2];
				C.origin_point_i = i;
				C.origin_point_j = j;
				map->coords[i + 1][j] = C;
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

void draw_map(mlx_image_t* img, map_data *map, int color)
{
	point B;
	point C;
	point origin;
	int j;
	int i;

	i = 0;
	j = 0;
	// printf("aaa nbr x %d \n", map->coords[0][0].x);
	// printf("aaa nbr y %d \n", map->coords[0][0].y);
	while (i < map->max_height)
	{
		while (j < map->max_width)
		{
			origin = (point){map->coords[i][j].xyz[0], map->coords[i][j].xyz[1], map->coords[i][j].xyz[2]};
			if (j < map->max_width - 1)
				B = (point){map->coords[i][j + 1].xyz[0], map->coords[i][j + 1].xyz[1], map->coords[i][j + 1].xyz[2]};
			if (i < map->max_height - 1)
				C = (point){map->coords[i + 1][j].xyz[0], map->coords[i + 1][j].xyz[1], map->coords[i + 1][j].xyz[2]};
			if (j < map->max_width - 1)
				draw_line(img, origin, B, color);
			if (i < map->max_height - 1)
				draw_line(img, origin, C, color);
			j++;
		}
		j = 0;
		i++;
	}
}

void translate_map(map_data *map, double val_1, double val_2)
{
	int j;
	int i;

	i = 0;
	j = 1;
	double T[2] = {val_1, val_2};
	double T2[2] = {val_2, val_1};
	int a;
	int b;
	printf("hello");
	a = 0;
	b = 0;
	int result[2] = {0, 0};

	while (i < map->max_height)
	{
		while (j < map->max_width)
		{
			while (a < 2)
			{
				while (b < 2)
				{
					if(map->coords[i][j].origin_point_i < i)
						result[a] += map->coords[i][j].relative_xyz[b] * T2[a];
					else
						result[a] += map->coords[i][j].relative_xyz[b] * T[a];
					b++;
				}
				b = 0;
				a++;
			}
			a = 0;
			while (a < 2)
			{
				if(j == 0)
					map->coords[i][j].xyz[a] = map->coords[i - 1][j].xyz[a] + result[a];
				else
					map->coords[i][j].xyz[a] = map->coords[i][j - 1].xyz[a] + result[a];
				a++;
			}
			a = 0;
			// printf("xy new %d %d origin i j = %d %d\n", result[0], result[1], map->coords[i][j].origin_point_i, map->coords[i][j].origin_point_j);
			// printf("absulote xy new %d %d\n", map->coords[i][j].xyz[0], map->coords[i][j].xyz[1]);
			j++;
			result[0] = 0;
			result[1] = 0;
		}
		printf("\n\n");
		j = 0;
		i++;
	}
}

void keypressed(mlx_key_data_t key_data, void *data_ptrs)
{
	ptrs data = *(ptrs *)data_ptrs;

	static double t_const1 = 1;
	static double t_const2 = 0;

	if (key_data.key == ON_KEYRIGHT)
	{
		t_const2 += 0.05;
		t_const1 -= 0.05;
	}	
	else if (key_data.key == ON_KEYLEFT)
	{
		t_const2 -= 0.05;
		t_const1 += 0.05;
	}
	else
		return ;
	draw_map(data.img, &data.map, (int)black);
	translate_map(&data.map, t_const1, t_const2);
	printf("key pressed = %d now 1 = %f  2 = %f\n", key_data.key, t_const1, t_const2);
	draw_map(data.img, &data.map, (int)blue);
	mlx_image_to_window(data.mlx, data.img, 50, 50);
}

void free_map(ptrs *data_ptrs)
{
	int j;

	j = 0;
	while (j < data_ptrs->map.max_height)
		free(data_ptrs->map.coords[j++]);
	free(data_ptrs->map.coords);
}

int32_t main(int32_t argc, char* argv[])
{
	ptrs data_ptrs;

	if(save_map(argv[1], &data_ptrs.map))
		return (1);
	// Gotta error check this stuff
	printf("hoiaaaaa\n");
	data_ptrs.mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	data_ptrs.img = mlx_new_image(data_ptrs.mlx, WIDTH, HEIGHT);
	data_ptrs.t_const1 = 1;
	data_ptrs.t_const2 = 0;
	// translate_map(&data_ptrs.map, data_ptrs.t_const1, data_ptrs.t_const2);
	draw_map(data_ptrs.img, &data_ptrs.map, (int)blue);
	mlx_key_hook(data_ptrs.mlx, keypressed, &data_ptrs);
	mlx_image_to_window(data_ptrs.mlx, data_ptrs.img, 50, 50);
	mlx_loop(data_ptrs.mlx);
	// // mlx_delete_image(mlx, img);
	// mlx_terminate(data_ptrs.mlx);
	// free_map(&data_ptrs);
	return (EXIT_SUCCESS);
}
