

// void assign_relative_coord(ptrs *data)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = 0;
// 	data->map.coords[i][j].relative_xyz[0] = 0;
// 	data->map.coords[i][j].relative_xyz[1] = 0;
// 	data->map.coords[i][j].relative_xyz[2] = 0;
// 	data->map.coords[i][j].origin_point_i = 0;
// 	data->map.coords[i][j].origin_point_j = 0;
// 	while (i < data->map.max_height)
// 	{
// 		while (j < data->map.max_width)
// 		{
// 			point A;
// 			point B;
// 			point C;
// 			point D;

// 			A = data->map.coords[i][j];
// 			if(j != data->map.max_width - 1)
// 				B = data->map.coords[i][j + 1];
// 			if(i != data->map.max_height - 1)
// 				C = data->map.coords[i + 1][j];
// 			if(j != data->map.max_width - 1)
// 			{
// 				B.relative_xyz[0] = B.xyz[0] - A.xyz[0];
// 				B.relative_xyz[1] = B.xyz[1] - A.xyz[1];
// 				B.relative_xyz[2] = B.xyz[2] - A.xyz[2];
// 				B.origin_point_i = i;
// 				B.origin_point_j = j;
// 				// printf(" i j %d %d, origi i j %d %d\n", i, j, B.origin_point_i, B.origin_point_j);
// 				data->map.coords[i][j + 1] = B;
// 			}
// 			if(j == 0 && i != data->map.max_height - 1)
// 			{
// 				C.relative_xyz[0] = C.xyz[0] - A.xyz[0];
// 				C.relative_xyz[1] = C.xyz[1] - A.xyz[1];
// 				C.relative_xyz[2] = C.xyz[2] - A.xyz[2];
// 				C.origin_point_i = i;
// 				C.origin_point_j = j;
// 				data->map.coords[i + 1][j] = C;
// 			}
// 			// printf("\nxyz rel A %d %d %d i j = %d %d origi i j = %d %d\n", A.relative_xyz[0], A.relative_xyz[1], A.relative_xyz[2], i, j, A.origin_point_i, A.origin_point_j);
// 			// printf("xyz rel C %d %d %d  i j = %d %d\n", C.relative_xyz[0], C.relative_xyz[1], C.relative_xyz[2], i + 1, j);
// 			// printf("xyz rel B %d %d %d i j = %d %d\n", B.relative_xyz[0], B.relative_xyz[1], B.relative_xyz[2], i, j + 1);
// 			j++;
// 		}
// 		j = 0;
// 		i++;
// 	}
// }