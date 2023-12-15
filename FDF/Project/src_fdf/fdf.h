#ifndef FDF_H

# define FDF_H

# define HEIGHT			1500
# define WIDTH			1500

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 #include "../MLX42/include/MLX42/MLX42.h"
//#include "/usr/include/MLX42/include/MLX42/MLX42.h"
#include <math.h>
#include "fcntl.h"
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"
#include <time.h>
#include <stdio.h>
# include <string.h>

#define MAPS_PATH "maps/"

# define M_PI           3.14159265358979323846

# define FT_ABS(X) (((X) < 0) ? (-(X)) : (X))

# define SCALE(X, A) (X ? X * A : X)

# define DEGR_TO_RAD(X) (X ? (X * M_PI) / 180 : 0)

# define _USE_MATH_DEFINES

typedef struct coord {
	int world_xyz[3];
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
	int color;
	int r;
	int g;
	int b;
	int a;
} point ;

typedef struct m_data
{
	int max_width;
	int max_height;
	int world_pos_Dxy[2];
	int model_in_world_pos_xyz[3];
	bool rgba_in_map_1_or_0;
	int origin_i;
	int origin_j;
	point world_axes_oxyz[4];
	point **coords;
} map_data;

typedef struct v_data
{
	double rad_angle_around_x;
	double rad_angle_around_y;
	double rad_angle_around_z;
	double rad_90dgr;
	double zoom;
} view_data;

typedef struct o_data
{
	double rad_angle_around_y;
	double rad_angle_around_z;
	double rad_angle_around_x;
} orient_data;

typedef struct d_l_data
{
	int curr_line_steps;
	int		error[2];
	int		draw_color;
	point	delta;
	point	sign_dir;
	point	cur;

}	curr_line_draw_data;

typedef struct index{
	int i;
	int j;
	int n;

} i_data;

typedef struct a_p_data
{
	point A;
	point B;
	point C;
} acronym_points_data;

typedef struct data{

	mlx_image_t *img;
	mlx_t *mlx;
	map_data map;
	acronym_points_data ac_points;
	view_data view;
	orient_data orientation;
	curr_line_draw_data dr_data;
	int color;
	double t_const1;
	double t_const2;
	int pos_x;
	int pos_y;
} ptrs;



enum {
	ON_KEYDOWN = 264,
	ON_KEYUP = 265,
	ON_KEYRIGHT = 262,
	ON_KEYLEFT = 263,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	ON_ESCAPE = 65307,

	ON_Q = 81,
	ON_W = 87,
	ON_E = 69,
	ON_A = 65,
	ON_S = 83,
	ON_D = 68,
	ON_I = 73,
	ON_K = 75,
	ON_J = 74,
	ON_L = 76,
	ON_U = 85,
	ON_O = 79,
	ON_PLUS = 61,
	ON_MINUS = 45
};

enum hex_code{
	nada = 0x00000000,
	black = 0x000000FF,
	white = 0xFFFFFFFF,
	red = 0x00FF00FF,
	green = 0x0000FFFF,
	blue = 0x0000FFFF
};                

int save_map(char* argv, ptrs *data);
int get_points_width(char *str);
void free_char_arr(void **arr);

// build map
void assign_relative_coords(ptrs *data);
int map_intarr_xyz(map_data *map, char **total_arr, i_data *i);
int map_intarr_xyz_rgba(map_data *map, char **total_arr, i_data *i);
void init_points_acronym(ptrs *data, int i, int j);
int check_limit_c(ptrs *data, int i, int j, int sign);
int check_limit_b(ptrs *data, int i, int j, int sign);
int basic_map_coloring(point *cur_point);
void offset_model_coord(ptrs *data, point *p);

// parsing
int parse_color(char *str);

// hooks
void keypressed(mlx_key_data_t key_data, void *data_ptrs);

// draw Dxy
void set_view_data(ptrs *data, double around_y_angle, double around_z_angle, double around_x_angle);
void make_draw_Dxy(ptrs *data);
int check_img_bounds(ptrs *data, int Dx, int Dy);
void draw_map(ptrs *data);
void new_start_Dxy(ptrs *data, int startpos_x, int startpos_y);
void draw_axes(ptrs *data);

// transform
void translate_map(map_data *map, ptrs *data);

// matrix tools
void compilation_matrix(double comp[3][3], double R[3][3], double R3[3][3]);
double vector_len(map_data *map, int i, int j);
void translate_map(map_data *map, ptrs *data);
void print_matrix(double M[3][3], int cols, int rows);

// tools
void clear_img(mlx_image_t *img, int width, int height);
void init_rgbs(point *A);
int32_t ft_pixel_rgba(int32_t r, int32_t g, int32_t b, int32_t a);
int is_nul_or_eof(int c);
int	fdf_ischar(char str_chr, char check);

#endif
