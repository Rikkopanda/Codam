
#include "fdf.h"


void set_view_data(ptrs *data, double around_y_angle, double around_z_angle)
{
    data->view.view_angle_around_y = around_y_angle;
	data->view.view_angle_around_z = around_z_angle;
}

void make_draw_Dxy(ptrs *data)
{
	int j;
	int i;
    //set points on right position
    //draw connecting points
	i = 0;
	j = 0;
	// printf("aaa nbr x %d \n", map->coords[0][0].x);
	// printf("aaa nbr y %d \n", map->coords[0][0].y);
	//draw_xy_projection(data);
	while (i < data->map.max_height)
	{
		while (j < data->map.max_width)
		{
            data->map.coords.Dxy[1]
			j++;
		}
		j = 0;
		i++;
	}

}

static void	draw_Dxy(ptrs *data, point f, point s, int color)
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