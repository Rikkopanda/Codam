#ifndef FDF_H

# define FDF_H

# define HEIGHT			500
# define WIDTH			500

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// #include "MLX42/include/MLX42/MLX42.h"
#include "/usr/include/MLX42/include/MLX42/MLX42.h"
#include <math.h>
#include "fcntl.h"
#include "libft/libft.h"
#include "gnl/get_next_line.h"

# include <string.h>

# define M_PI           3.14159265358979323846

# define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))

# define SCALE(X, A) (X ? X * A : X)

# define DEGR_TO_RAD(X) (X ? (X * M_PI) / 180 : 0)

# define _USE_MATH_DEFINES

typedef struct coord {
	int xyz[3];
	int Dxy[2];
	int relative_xyz[3];
	bool origin_xyz[3];
	double vector_down_len;
	double vector_right_len;
	int origin_point_i;
	int origin_point_j;
	int **left_point_i;
	int **right_point_i;
	int **down_point_i;
	int **up_point_i;
} point ;

typedef struct m_data
{
	int max_width;
	int max_height;
	int start_pos_x;
	int start_pos_y;
	point **coords;
} map_data;

typedef struct v_data
{
	double view_angle_around_y;
	double view_angle_around_z;

} view_data;

typedef struct data{

	mlx_image_t *img;
	mlx_t *mlx;
	map_data map;
	view_data view;
	int color;
	double t_const1;
	double t_const2;
	int pos_x;
	int pos_y;
} ptrs;



enum {
	ON_KEYDOWN = 65362,
	ON_KEYUP = 65364,
	ON_KEYRIGHT = 263,
	ON_KEYLEFT = 262,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	ON_ESCAPE = 65307,
	ON_A = 65,
	ON_W = 87,
	ON_D = 68,
	ON_S = 83
};

enum hex_code{
	black = 0x00000000,
	white = 0xFFFFFFFF,
	red = 0x00FF0000,
	green = 0x0000FF00,
	blue = 0x0000FFFF
};                

int save_map(char* argv, ptrs *data);
int get_points_width(char *str);
void free_char_arr(void **arr);

void assign_relative_coord(ptrs *data);

#endif
