
#include "fdf.h"


void set_view_data(ptrs *data, double around_y_angle, double around_z_angle)
{
    data->view.rad_angle_around_y = DEGR_TO_RAD(around_y_angle);
	data->view.rad_angle_around_z = DEGR_TO_RAD(around_z_angle);
	data->view.rad_90dgr = DEGR_TO_RAD(90);
}

void set_Dxy(ptrs *data, int i, int j)
{
	data->map.coords[i][j].Dxy[0] = data->map.coords[i][j].xyz[0] * sin(data->view.rad_angle_around_z);
	data->map.coords[i][j].Dxy[0] -= data->map.coords[i][j].xyz[1] * sin(data->view.rad_angle_around_z);

	data->map.coords[i][j].Dxy[1] = -data->map.coords[i][j].xyz[2] * sin(data->view.rad_angle_around_y);
	data->map.coords[i][j].Dxy[1] += data->map.coords[i][j].xyz[1] * sin(data->view.rad_90dgr - data->view.rad_angle_around_y);

	//data->map.coords[i][j].Dxy[1] += data->map.coords[i][j].xyz[0] * sin(data->view.rad_angle_around_z);
	//data->map.coords[i][j].Dxy[1] -= data->map.coords[i][j].xyz[1] * sin(data->view.rad_angle_around_z);

	printf("\ni j = %d %d,  xyz = (%d,%d,%d) Dxy = (%d,%d)\n", i, j, data->map.coords[i][j].xyz[0], 
		data->map.coords[i][j].xyz[1], data->map.coords[i][j].xyz[2], data->map.coords[i][j].Dxy[0]
		, data->map.coords[i][j].Dxy[1]); 
}
void project_2d(ptrs *data)
{
	int i;
	int j;
	double dgr_90_rad = DEGR_TO_RAD(90);
	i = 0;
	j = 0;
	while(i < data->map.max_height)
	{
		while(j < data->map.max_width)
		{
			set_Dxy(data, i, j);
			j++;
		}
		j = 0;
		i++;
	}

}
void make_draw_Dxy(ptrs *data, int color)
{

    //set points on right position
    //draw connecting points

	project_2d(data);
	draw_map(data, color);

	//draw_2d_projection(data);

}

int check_img_bounds(ptrs *data, int Dx, int Dy)
{
	int Dx_offset;
	int Dy_offset;
	//printf("hoi 1\n");
	Dx_offset = data->map.start_pos_x;
	Dy_offset = data->map.start_pos_y;
	if((Dx + Dx_offset >= 0 && Dy + Dy_offset >= 0) && (Dx + Dx_offset <= WIDTH && Dy + Dy_offset <= HEIGHT))
		return (0);
	//printf("put wel\n");
	return (1);
}

void	draw_line(ptrs *data, point f, point s, int color)
{
	point	delta;
	point	sign_dir;
	point	cur;
	int		error[2];

	delta.Dxy[0] = FT_ABS(s.Dxy[0] - f.Dxy[0]);
	delta.Dxy[1] = FT_ABS(s.Dxy[1] - f.Dxy[1]);
	sign_dir.Dxy[0] = f.Dxy[0] < s.Dxy[0] ? 1 : -1;
	sign_dir.Dxy[1] = f.Dxy[1] < s.Dxy[1] ? 1 : -1;
	error[0] = delta.Dxy[0] - delta.Dxy[1];
	cur = f;
	while (cur.Dxy[0] != s.Dxy[0] || cur.Dxy[1] != s.Dxy[1])
	{
			//printf("hoi 1\n");
		if(check_img_bounds(data, cur.Dxy[0], cur.Dxy[1]) == 0)
			mlx_put_pixel(data->img, cur.Dxy[0] + data->map.start_pos_x, cur.Dxy[1] + data->map.start_pos_y, color);
		if ((error[1] = error[0] * 2) > -delta.Dxy[1])
		{
			error[0] -= delta.Dxy[1];
			cur.Dxy[0] += sign_dir.Dxy[0];
		}
		if (error[1] < delta.Dxy[0])
		{
			error[0] += delta.Dxy[0];
			cur.Dxy[1] += sign_dir.Dxy[1];
		}
	}
}

void draw_map(ptrs *data, int color)
{
	point *B;
	point *C;
	point *origin;
	int j;
	int i;

	i = 0;
	j = 0;
	// printf("aaa nbr x %d \n", data->map.coords[0][2].Dxy[0]);
	// printf("aaa nbr y %d \n", data->map.coords[0][2].Dxy[1]);
	//draw_xy_projection(data);
	while (i < data->map.max_height)
	{
		while (j < data->map.max_width)
		{
			origin = (point *)&data->map.coords[i][j];
			if (j < data->map.max_width - 1)
				B = (point *)&data->map.coords[i][j + 1];
			if (i < data->map.max_height - 1)
				C = (point *)&data->map.coords[i + 1][j];
			if (j < data->map.max_width - 1)
				draw_line(data, *origin, *B, color);
			if (i < data->map.max_height - 1)
				draw_line(data, *origin, *C, color);
			//assign_vectors_len(data, i , j);
			j++;
		}
		j = 0;
		i++;
	}
}