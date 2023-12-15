
#include "fdf.h"

void set_view_data(ptrs *data, double around_y_angle, double around_z_angle, double around_x_angle)
{
	data->view.rad_angle_around_x = DEGR_TO_RAD(around_x_angle);
    data->view.rad_angle_around_y = DEGR_TO_RAD(around_y_angle);
	data->view.rad_angle_around_z = DEGR_TO_RAD(around_z_angle);
	data->view.rad_90dgr = DEGR_TO_RAD(90);
}

void set_Dxy(ptrs *data, int i, int j)
{
	data->map.coords[i][j].Dxy[0] = data->map.coords[i][j].world_xyz[0] * cos(data->view.rad_angle_around_z);
	data->map.coords[i][j].Dxy[0] += data->map.coords[i][j].world_xyz[1] * sin(data->view.rad_angle_around_z);

	data->map.coords[i][j].Dxy[1] = data->map.coords[i][j].world_xyz[0] * -sin(data->view.rad_angle_around_z);
	data->map.coords[i][j].Dxy[1] += data->map.coords[i][j].world_xyz[1] * cos(data->view.rad_angle_around_z);

	// data->map.coords[i][j].Dxy[1] += -data->map.coords[i][j].world_xyz[2] * sin(data->view.rad_angle_around_y);
	// data->map.coords[i][j].Dxy[1] += data->map.coords[i][j].world_xyz[1] * sin(data->view.rad_angle_around_y);
	// p->Dxy[1] += -p->world_xyz[2] * sin(data->view.rad_angle_around_y);
	// p->Dxy[1] += p->world_xyz[1] * sin(data->view.rad_angle_around_y);
	// - data->view.rad_angle_around_z
	// data->map.coords[i][j].Dxy[1] += data->map.coords[i][j].xyz[0] * sin(data->view.rad_angle_around_y);
	// data->map.coords[i][j].Dxy[1] -= data->map.coords[i][j].xyz[1] * sin(data->view.rad_angle_around_y);

	//printf("\ni j = %d %d,  xyz = (%d,%d,%d) Dxy = (%d,%d)\n", i, j, data->map.coords[i][j].xyz[0], 
	//	data->map.coords[i][j].xyz[1], data->map.coords[i][j].xyz[2], data->map.coords[i][j].Dxy[0]
	//	, data->map.coords[i][j].Dxy[1]); 
}
void build_Wxyz_project_Dxy(ptrs *data)
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
			offset_model_coord(data, &data->map.coords[i][j]);
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
	build_Wxyz_project_Dxy(data);
	draw_map(data);
	//draw_2d_projection(data);
}

int check_img_bounds(ptrs *data, int Dx, int Dy)
{
	int Dx_offset;
	int Dy_offset;
	//printf("hoi 1\n");
	Dx_offset = data->map.world_pos_Dxy[0];
	Dy_offset = data->map.world_pos_Dxy[1];
	if((Dx + Dx_offset >= 0 && Dy + Dy_offset >= 0) && (Dx + Dx_offset <= WIDTH && Dy + Dy_offset <= HEIGHT))
		return (0);
	//printf("put wel\n");
	return (1);
}

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
	new_color.r = (int)(((double)ori->r * ((double)1 - percentage)) + (double)s->r * percentage);
	new_color.g = (int)(((double)ori->g * ((double)1 - percentage)) + (double)s->g * percentage);
	new_color.b = (int)(((double)ori->b * ((double)1 - percentage)) + (double)s->b * percentage);
	new_color.a = (int)(((double)ori->a * ((double)1 - percentage)) + (double)s->a * percentage);
	color = ft_pixel_rgba(new_color.r, new_color.g, new_color.b, new_color.a);
	// printf("\ninterpolated at %f%%\nold rgba: %d, %d, %d, %d\nnew rgba: %d, %d, %d, %d\n", percentage * 100, ori->r, ori->g, ori->b, ori->b, new_color.r, new_color.g, new_color.b, new_color.a);
	// printf("point A %x to B %x, interpolated result: %x\n\n", ori->color, s->color, color);
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

void	draw_line(ptrs *data, point *f, point *s)
{
	init_draw_data(data, f, s);

	calc_line_len(data, *f, *s);
	//int len = (int)D_vector_len(delta);
	int count;
	data->dr_data.draw_color = (int)white;
	count = 0;
	//printf("deltax = %d y = %d\n", delta.Dxy[0], delta.Dxy[1]);
	while (data->dr_data.cur.Dxy[0] != (*s).Dxy[0] || data->dr_data.cur.Dxy[1] != (*s).Dxy[1])
	{
		//print*f("hoi 1\n");
		if(data->dr_data.cur.color != (*s).color)
			data->dr_data.draw_color = interpolate(data, f, s, count);
		else
			data->dr_data.draw_color = data->dr_data.cur.color;
		//fdf_put_pixel(data, data->dr_data.cur.Dxy[0], data->dr_data.cur.Dxy[0], 1);
		if(check_img_bounds(data, data->dr_data.cur.Dxy[0], data->dr_data.cur.Dxy[1]) == 0)
			mlx_put_pixel(data->img, data->dr_data.cur.Dxy[0]
				+ data->map.world_pos_Dxy[0], data->dr_data.cur.Dxy[1]
					+ data->map.world_pos_Dxy[1], data->dr_data.draw_color);
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

void set_axes_Dxy(ptrs *data, point *p)
{
	p->Dxy[0] = p->world_xyz[0] * cos(data->view.rad_angle_around_z);
	p->Dxy[0] += p->world_xyz[1] * sin(data->view.rad_angle_around_z);

	p->Dxy[1] = p->world_xyz[0] * -sin(data->view.rad_angle_around_z);
	p->Dxy[1] += p->world_xyz[1] * cos(data->view.rad_angle_around_z);
	basic_map_coloring(p);
	// p->Dxy[1] += -p->world_xyz[2] * sin(data->view.rad_angle_around_y);
	// p->Dxy[1] += p->world_xyz[1] * sin(data->view.rad_angle_around_y);
}

void draw_axes(ptrs *data)
{
	set_axes_Dxy(data, &data->map.world_axes_oxyz[0]);
	set_axes_Dxy(data, &data->map.world_axes_oxyz[1]);
	set_axes_Dxy(data, &data->map.world_axes_oxyz[2]);
	set_axes_Dxy(data, &data->map.world_axes_oxyz[3]);
	draw_line(data, &data->map.world_axes_oxyz[0], &data->map.world_axes_oxyz[1]);
	draw_line(data, &data->map.world_axes_oxyz[0], &data->map.world_axes_oxyz[2]);
	draw_line(data, &data->map.world_axes_oxyz[0], &data->map.world_axes_oxyz[3]);
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
				draw_line(data, origin, B);
			if (i < data->map.max_height - 1)
				draw_line(data, origin, C);
			// printf("rgba: %d, %d, %d, %d\n", (*origin).r, (*origin).g, (*origin).b, (*origin).a);
			// printf("rgba: %d, %d, %d, %d\n\n", (*C).r, (*C).g, (*C).b, (*C).a);
			//assign_vectors_len(data, i , j);
			j++;
		}
		j = 0;
		i++;
	}
}