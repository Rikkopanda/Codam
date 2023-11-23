


typedef struct m_data{
	int **int_arr;
	double xyz_model[3][3]; 
	double xyz_world[3][3];
	double xy_draw[3][3];

} map_data;


typedef struct v_data
{
	double view_angle_around_y;
	double view_angle_around_z;

} view_data;

typedef struct orientate
{
	int move_x;
	int move_y;
	int move_z;

	//doulbe rotate_....;

} orientation_data;


typedef struct all
{
	view_data view;
	map_data map;
	orientation_data orientation;

} all_data;

void init_view_data(all_data *data)
{
	data->view_angle_around_y= 0;
	data->view_angle_around_x= 0;
}

void make_points_from_origin()
{

	int i;
	int j;

	i = origin.i;
	i = origin.j;

	//while[i] < width
	//	while[j] < height
			define_relative_xyz(points[][]);
			define_abslute_xyz(points[][]);
}

make_model_xyz(&map, int_arr)
{
	choose_origin();

	make_points_from_origin();
}


int main()
{
	all_data data;

	str_arr = makestr_arr(argv);

	data.map.int_arr = makeint_arr(str_arr);

	make_model_xyz(&map, int_arr);

	init_orientation(data.orientation);
	//set moves to 0 aswell as rotations or scales

	make_world_xyz(&map, data.orientation);
	// origin of model_xyz = origin of world_xyz + MOVE
	// rotation happens of the points relative-coordinates starting-
	// -from the chosen point. (begin with origin-point for test)

	init_view_data(&data);
	// sets angles_around to 0
	// origin of draw_data_xy is xy of world_xyz origin

	make_drawing_xy(&map, &data);
	// project world_xyz onto draw_xy dependant on perspective view(angles)
	//
	// in the draw_xy all the POINTS are projected in perspective view
	// after this lines are drawn from points to each other(adjecent ones ofcouse)

	draw_draw_xy_on_img(&map, &data);

	mlx_img_to_window(mlx, img);

	mlx_hook(transform_)

	mlx_loop(mlx);
}