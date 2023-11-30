
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

	data->map.coords[i][j].Dxy[1] = -data->map.coords[i][j].xyz[2] * sin(data->view.rad_angle_around_z);
	data->map.coords[i][j].Dxy[1] += data->map.coords[i][j].xyz[1] * sin(data->view.rad_90dgr - data->view.rad_angle_around_z);

	data->map.coords[i][j].Dxy[1] += data->map.coords[i][j].xyz[0] * sin(data->view.rad_angle_around_y);
	data->map.coords[i][j].Dxy[1] -= data->map.coords[i][j].xyz[1] * sin(data->view.rad_angle_around_y);

	//printf("\ni j = %d %d,  xyz = (%d,%d,%d) Dxy = (%d,%d)\n", i, j, data->map.coords[i][j].xyz[0], 
	//	data->map.coords[i][j].xyz[1], data->map.coords[i][j].xyz[2], data->map.coords[i][j].Dxy[0]
	//	, data->map.coords[i][j].Dxy[1]); 
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

void make_draw_Dxy(ptrs *data)
{
    //set points on right position
    //draw connecting points
	project_2d(data);
	draw_map(data);
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

//void fdf_put_pixel(ptrs *data, int x, int y,)

double D_vector_len(point delta)
{
	double len;

	len = sqrt(pow(delta.Dxy[0] , 2) + pow(delta.Dxy[1], 2));
	return (len);
}

int interpolate(ptrs *data, point	*ori, point	*s, int count)
{
	int color;
	point new_color;
	double percentage;

	percentage = (double)count / (double)data->dr_data.curr_line_steps;
	//new_color.r = ori->r + (ori->r - s->r) * percentage;
	//new_color.g = ori->g + (ori->g - s->g) * percentage;
	//new_color.b = ori->b + (ori->b - s->b) * percentage;
	//new_color.a = ori->a + (ori->a - s->a) * percentage;
	new_color.r = (ori->r * (1 - percentage)) + s->r * percentage;
	new_color.g = (ori->g * (1 - percentage)) + s->g * percentage;
	new_color.b = (ori->b * (1 - percentage)) + s->b * percentage;
	new_color.a = (ori->a * (1 - percentage)) + s->a * percentage;
	color = ft_pixel_rgba(new_color.r, new_color.g, new_color.b, new_color.a);
	//printf("interpolated at %f%% %d, %d, %d\n", percentage * 100, new_color.r, new_color.g, new_color.b);
	//printf("colors %x, %x, interpolated: %x\n", ori->color, s->color, color);
	return (color);
}


void calc_line_len(ptrs *data, point A_cnt, point B_cnt)
{
	data->dr_data.curr_line_steps = 0;

	while (A_cnt.Dxy[0] != B_cnt.Dxy[0] || A_cnt.Dxy[1] != B_cnt.Dxy[1])
	{
		if ((data->dr_data.error[1] = data->dr_data.error[0] * 2) > -data->dr_data.delta.Dxy[1])
		{
			data->dr_data.error[0] -= data->dr_data.delta.Dxy[1];
			A_cnt.Dxy[0] += data->dr_data.sign_dir.Dxy[0];
		}
		if (data->dr_data.error[1] < data->dr_data.delta.Dxy[0])
		{
			data->dr_data.error[0] += data->dr_data.delta.Dxy[0];
			A_cnt.Dxy[1] += data->dr_data.sign_dir.Dxy[1];
		}
		data->dr_data.curr_line_steps++;
		//printf("step %d \n", data->dr_data.curr_line_steps);
	}
}

void init_draw_data(ptrs *data, point *f, point *s)
{
	data->dr_data.delta.Dxy[0] = FT_ABS(s->Dxy[0] - f->Dxy[0]);
	data->dr_data.delta.Dxy[1] = FT_ABS(s->Dxy[1] - f->Dxy[1]);
	data->dr_data.sign_dir.Dxy[0] = f->Dxy[0] < s->Dxy[0] ? 1 : -1;
	data->dr_data.sign_dir.Dxy[1] = f->Dxy[1] < s->Dxy[1] ? 1 : -1;
	data->dr_data.error[0] = data->dr_data.delta.Dxy[0] - data->dr_data.delta.Dxy[1];
	data->dr_data.cur = *f;
	data->dr_data.draw_color = 0;
}


void fdf_put_pixel(ptrs *data,  int P_Dx, int P_Dy, int thickness)
{
	int cnt;

	cnt = 0;
	//printf("x %d\n", P_Dx + + data->map.start_pos_x);
	//while(cnt < thickness)
	//if(check_img_bounds(data, P_Dx, P_Dy) == 0)
	//	mlx_put_pixel(data->img, P_Dx
	//		 + data->map.start_pos_x, P_Dy
	//		 	 + data->map.start_pos_y, data->dr_data.draw_color);
}

void	draw_line(ptrs *data, point f, point s)
{
	init_draw_data(data, &f, &s);

	calc_line_len(data, f, s);
	//int len = (int)D_vector_len(delta);
	int count;
	data->dr_data.draw_color = (int)white;
	count = 0;
	//printf("deltax = %d y = %d\n", delta.Dxy[0], delta.Dxy[1]);
	while (data->dr_data.cur.Dxy[0] != s.Dxy[0] || data->dr_data.cur.Dxy[1] != s.Dxy[1])
	{
		//printf("hoi 1\n");
		if(data->dr_data.cur.color != s.color)
			data->dr_data.draw_color = interpolate(data, &f, &s, count);
		else
			data->dr_data.draw_color = data->dr_data.cur.color;
		//fdf_put_pixel(data, data->dr_data.cur.Dxy[0], data->dr_data.cur.Dxy[0], 1);
		if(check_img_bounds(data, data->dr_data.cur.Dxy[0], data->dr_data.cur.Dxy[1]) == 0)
			mlx_put_pixel(data->img, data->dr_data.cur.Dxy[0]
				+ data->map.start_pos_x, data->dr_data.cur.Dxy[1]
					+ data->map.start_pos_y, data->dr_data.draw_color);
		//printf("error[0] = %d [1] = %d\n", error[1], error[0]);
		if ((data->dr_data.error[1] = data->dr_data.error[0] * 2) > -data->dr_data.delta.Dxy[1])
		{
			data->dr_data.error[0] -= data->dr_data.delta.Dxy[1];
			data->dr_data.cur.Dxy[0] += data->dr_data.sign_dir.Dxy[0];
		}
		if (data->dr_data.error[1] < data->dr_data.delta.Dxy[0])
		{
			data->dr_data.error[0] += data->dr_data.delta.Dxy[0];
			data->dr_data.cur.Dxy[1] += data->dr_data.sign_dir.Dxy[1];
		}
		count++;
	}
	//printf("total count %d, D_len  \n", count);
}

void draw_map(ptrs *data)
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
				draw_line(data, *origin, *B);
			if (i < data->map.max_height - 1)
				draw_line(data, *origin, *C);
			//assign_vectors_len(data, i , j);
			j++;
		}
		j = 0;
		i++;
	}
}