#ifndef FDF_H

# define FDF_H

# define HEIGHT			500
# define WIDTH			500

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "MLX42/include/MLX42/MLX42.h"
#include <math.h>
#include "fcntl.h"
#include "libft/libft.h"
#include "gnl/get_next_line.h"

# include <string.h>

# define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))

# define SCALE(X, A) (X ? X * A : X)

typedef struct coord {
	int xyz[3];
	int absolute_xyz[3];
	int relative_xyz[3];
	bool origin_xyz[3];
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

	point **coords;
} map_data;

typedef struct data{

	mlx_image_t *img;
	mlx_t *mlx;
	map_data map;
	int color;
	double t_const1;
	double t_const2;
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
	ON_ESCAPE = 65307
};

enum hex_code{
	black = 0x00000000,
	white = 0xFFFFFFFF,
	red = 0x00FF0000,
	green = 0x0000FF00,
	blue = 0x0000FFFF
};                

int save_map(char* argv, map_data *map);
int get_points_width(char *str);
void free_char_arr(void **arr);

void assign_relative_coord(map_data *map);

#endif
