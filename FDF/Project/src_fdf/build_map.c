
#include "fdf.h"

int map_intarr_xyz(map_data *map, char **total_arr, i_data *i)
{
	// printf("xyz\n");
	while (i->i < map->max_height)
	{
		while (total_arr[i->i][i->n])
		{
			if (ft_isdigit(total_arr[i->i][i->n]) || total_arr[i->i][i->n] == '-')//error handle still
			{
				// printf("helloooo1 i=%d j=%d\n", i->i, i->j);
				if(i->j == map->max_width)
					break ;
				map->coords[i->i][i->j].xyz[2] = SCALE(ft_atoi(&total_arr[i->i][i->n]), 10);
				map->coords[i->i][i->j].xyz[1] = SCALE(i->i, 10);
				map->coords[i->i][i->j].xyz[0] = SCALE(i->j, 10);
				// printf("%d %d %d \t", map->coords[i->i][i->j].xyz[0],
				// 	map->coords[i->i][i->j].xyz[1],
				// 	map->coords[i->i][i->j].xyz[2]);
				if(total_arr[i->i][i->n] == '-')
					i->n++;
				while(ft_isdigit(total_arr[i->i][i->n]))
					i->n++;
				basic_map_coloring(&map->coords[i->i][i->j]);
				i->j++;
			}
			else
				i->n++;
		}
		i->j = 0;
		i->n = 0;
		i->i++;
		// printf("\n");
	}
	// printf("\n\n");
	//printf("hoi4a\n");
	return (0);
}

int map_intarr_xyz_rgba(map_data *map, char **total_arr, i_data *i)
{
	while (i->i < map->max_height)
	{
		while (total_arr[i->i][i->n])
		{
			if (ft_isdigit(total_arr[i->i][i->n]) || total_arr[i->i][i->n] == '-')//error handle still
			{
				map->coords[i->i][i->j].xyz[2] = SCALE(ft_atoi(&total_arr[i->i][i->n]), 20);
				map->coords[i->i][i->j].xyz[1] = SCALE(i->i, 20);
				map->coords[i->i][i->j].xyz[0] = SCALE(i->j, 20);

				if(total_arr[i->i][i->n] == '-')
					i->n++;
				while(ft_isdigit(total_arr[i->i][i->n]))
					i->n++;
				i->n++;
				map->coords[i->i][i->j].color = parse_color(&total_arr[i->i][i->n + 2]);
				init_rgbs(&map->coords[i->i][i->j]);
				while (!fdf_ischar(total_arr[i->i][i->n], ' ') && !is_nul_or_eof(total_arr[i->i][i->n]))
					i->n++;
				i->j++;
			}
			else
				i->n++;
		}
		i->j = 0;
		i->n = 0;
		i->i++;

	}

	return (0);
}
// printf("xyz\n");
// printf("%d %d %d \t\t", map->coords[i->i][i->j].xyz[0],
// 	map->coords[i->i][i->j].xyz[1],
// 	map->coords[i->i][i->j].xyz[2]);
// printf("\n");
// printf("\n\n");