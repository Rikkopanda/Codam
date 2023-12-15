
#include "fdf.h"

void assign_left_or_right(ptrs *data, int i, int j, int sign)
{
	data->ac_points.A = data->map.coords[i][j];
	if(sign == 1)
	{
		if(j < data->map.max_width - sign)
			data->ac_points.B = data->map.coords[i][j + sign];
	}
	else
	{
		if(j > 0)
			data->ac_points.B = data->map.coords[i][j + sign];
	}
	if(check_limit_b(data, i, j, sign))
	{
		data->ac_points.B.relative_xyz[0] = data->ac_points.B.xyz[0] - data->ac_points.A.xyz[0];
		data->ac_points.B.relative_xyz[1] = data->ac_points.B.xyz[1] - data->ac_points.A.xyz[1];
		data->ac_points.B.relative_xyz[2] = data->ac_points.B.xyz[2] - data->ac_points.A.xyz[2];
		data->ac_points.B.origin_point_i = i;
		data->ac_points.B.origin_point_j = j;
		// printf(" i j %d %d, origi i j %d %d\n", i, j, B.origin_point_i, B.origin_point_j);
		data->map.coords[i][j + sign] = data->ac_points.B;
	}
}

int check_limit_c(ptrs *data, int i, int j, int sign)
{
	if(sign == 1)
	{
		if(j == data->map.origin_j && i < data->map.max_height - 1)
			return (1);
	}
	else
	{
		if (j == data->map.origin_j && i > 0)
			return (1);
	}
	return (0);
}

int check_limit_b(ptrs *data, int i, int j, int sign)
{
	if(sign == 1)
	{
		if(j < data->map.max_width - 1)
			return (1);
	}
	else
	{
		if (j > 0)
			return (1);
	}
	return (0);
}

void build_left_right(ptrs *data, int i, int j, int sign)
{
	j = data->map.origin_j;
	while(j < data->map.max_width)
	{
		assign_left_or_right(data, i, j, 1);
		j++;
	}
	j = data->map.origin_j;
	while(j >= 0)
	{
		assign_left_or_right(data, i, j, -1);
		j--;
	}
}

void init_origin_point(ptrs *data)
{
    int i;
    int j;

    i = data->map.origin_i;
    j = data->map.origin_j;
    data->map.coords[i][j].relative_xyz[0] = 0;
	data->map.coords[i][j].relative_xyz[1] = 0;
	data->map.coords[i][j].relative_xyz[2] = 0;
	data->map.coords[i][j].origin_point_i = i;
	data->map.coords[i][j].origin_point_j = j;
}

void assign_forwards_backwards(ptrs *data, int i, int j, int sign)
{
	data->ac_points.A.a = 4;
	printf("%d tezt index %d %d\n", data->ac_points.C.a, i, j);
	// data->ac_points.A = data->map.coords[i][j];
	// point A;
	// point C;
	// A = data->map.coords[i][j]
	if(sign == 1)
	{
		if(i < data->map.max_height - 1)
			data->ac_points.C = data->map.coords[i + sign][j];
	}
	else
	{
		if(j > 0)
			data->ac_points.C = data->map.coords[i + sign][j];
	}
	data->ac_points.A = data->map.coords[i][j];
	if(check_limit_c(data, i, j, sign))
	{
		data->ac_points.C.relative_xyz[0] = data->ac_points.C.xyz[0] - data->ac_points.A.xyz[0];
		data->ac_points.C.relative_xyz[1] = data->ac_points.C.xyz[1] - data->ac_points.A.xyz[1];
		data->ac_points.C.relative_xyz[2] = data->ac_points.C.xyz[2] - data->ac_points.A.xyz[2];
		data->ac_points.C.origin_point_i = i;
		data->ac_points.C.origin_point_j = j;
		data->map.coords[i + sign][j] = data->ac_points.C;
	}
}

void assign_relative_coords(ptrs *data)
{
    int i;
    int j;

    // data->map.origin_i = data->map.max_height / 2;
    // data->map.origin_j = data->map.max_width / 2;
	data->map.origin_i = 0;
    data->map.origin_j = 0;
    init_origin_point(data);
	i = data->map.origin_i;
	// data->ac_points.A.a = 4;
	// data->ac_points.A.a = 4;
	// printf("%d tezt\n", data->ac_points.A.a);
	while(i < data->map.max_height)
	{
		build_left_right(data, i, j, 1);
		assign_forwards_backwards(data, i, data->map.origin_j, 1);
		i++;
	}
	i = data->map.origin_i;
	while(i > 0)
	{
		build_left_right(data, i, j, -1);
		assign_forwards_backwards(data, i, data->map.origin_j, -1);
		i--;
	}
	i = 0;
	j = 0;
	printf("xyz relative\n");
	while(i < data->map.max_height)
	{
		while(j < data->map.max_width)
		{
			printf("%d %d %d \t\t", data->map.coords[i][j].relative_xyz[0],
									data->map.coords[i][j].relative_xyz[1],
									data->map.coords[i][j].relative_xyz[2]);
			j++;
		}
		i++;
		j = 0;
		printf("\n");
	}
	printf("\n\n");
}