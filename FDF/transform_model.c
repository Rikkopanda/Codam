
# include "fdf.h"

void init_R_around_X(double R[3][3], char axis, double rad);
void init_R_around_Y(double R[3][3], char axis, double rad);
void init_R_around_Z(double R[3][3], char axis, double rad);
void zoom_matrix(double R[3][3], double zoom);
void init_result(double *M);

void translate_map(map_data *map, ptrs *data)
{
	int j;
	int i;
	int k;
	int l;
	int m;
	clock_t start_t, end_t;
	double total_t;

	start_t = clock();
	i = 0;
	j = 1;

	double result[3];
	k = 0;
	l = 0;
	m = 0;
	double R2[2][2] = {{0,-1},{1, 0}};
	double R[3][3];
	double R3[3][3];
	double R4[3][3];
	double comp[3][3];
	double comp2[3][3];
	double Z[3][3];
	double comp3[3][3];

	init_R_around_Z(R, 'z', data->orientation.rad_angle_around_z);
	init_R_around_Y(R3, 'z', data->orientation.rad_angle_around_y);
	init_R_around_X(R4, 'z', data->orientation.rad_angle_around_x);
	// printf("rad aroudnd x %f, R4 00 en 01 %f %f \n",data->orientation.rad_angle_around_x, R4[0][0], R4[0][1]);
	// print_matrix(R4, 3, 3);
	compilation_matrix(comp, R, R3);
	compilation_matrix(comp2, comp, R4);
	zoom_matrix(Z, data->view.zoom);
	compilation_matrix(comp3, comp2, Z);
	init_result(result);

	while (i < map->max_height)
	{
		while (j < map->max_width)
		{
			while (l < 3)
			{
				while (m < 3)
				{			
					if(map->coords[i][j].origin_point_i < i)
						result[l] += (double)map->coords[i][j].relative_xyz[m] * comp3[m][l];
					else
						result[l] += (double)map->coords[i][j].relative_xyz[m] * comp3[m][l];
					m++;
				}
				m = 0;
				l++;
			}
			l = 0;
			while (l < 3)
			{
				if(j == 0)
					map->coords[i][j].xyz[l] = map->coords[i - 1][j].xyz[l] + (int)result[l];
				else
					map->coords[i][j].xyz[l] = map->coords[i][j - 1].xyz[l] + (int)result[l];
				l++;
			}
			l = 0;
			// printf("xy new %f %f origin i j = %d %d\n", result[0], result[1], map->coords[i][j].origin_point_i, map->coords[i][j].origin_point_j);
			// printf("absulote xy new %d %d\n", map->coords[i][j].xyz[0], map->coords[i][j].xyz[1]);
			init_result(result);
			j++;

		}
	// 	printf("\n\n");
	// 		end_t = clock();
	// total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	// printf("Total time taken by CPU: %f\n", total_t  );
		j = 0;
		i++;
	}
}

void zoom_matrix(double R[3][3], double zoom)
{
	R[0][0]  = zoom;
	R[0][1]  = 0;
	R[0][2]  = 0;
	R[1][0]  = 0;
	R[1][1]  = zoom;
	R[1][2]  = 0;
	R[2][0]  = 0;
	R[2][1]  = 0;
	R[2][2]  = zoom;
}

void init_R_around_Z(double R[3][3], char axis, double rad)
{
	(void)axis;
	R[0][0]  = cos(rad);
	R[0][1]  = sin(-rad);
	R[0][2]  = 0;
	R[1][0]  = sin(rad);
	R[1][1]  = cos(rad);
	R[1][2]  = 0;
	R[2][0]  = 0;
	R[2][1]  = 0;
	R[2][2]  = 1;
}

void init_R_around_Y(double R[3][3], char axis, double rad)
{
	(void)axis;
	R[0][0]  = cos(rad);
	R[0][1]  = 0;
	R[0][2]  = sin(rad);
	R[1][0]  = 0;
	R[1][1]  = 1;
	R[1][2]  = 0;
	R[2][0]  = -sin(rad);
	R[2][1]  = 0;
	R[2][2]  = cos(rad);
}

void init_R_around_X(double R[3][3], char axis, double rad)
{
	(void)axis;
	R[0][0]  = 1;
	R[0][1]  = 0;
	R[0][2]  = 0;
	R[1][0]  = 0;
	R[1][1]  = cos(rad);
	R[1][2]  = -sin(rad);
	R[2][0]  = 0;
	R[2][1]  = sin(rad);
	R[2][2]  = cos(rad);
}

void init_result(double *M)
{
	for (int i = 0; i < 3; ++i)
		M[i] = 0;
}