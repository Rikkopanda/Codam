
#include "fdf.h"


int fill_strarr(char *next_line, char **total_arr, int fd, map_data *map )
{
	int i;

	i = 0;
	while (next_line)
	{
		next_line = get_next_line(fd);
		// printf(" hoi1c1 %s\n", next_line);
        // if (next_line <= 0)
        //     return (free_char_arr((void **)total_arr), free(next_line), 1);
		total_arr[i] = next_line;
		if (next_line == NULL)	
			break;
		map->max_width = get_points_width(next_line);
		i++;
	}
	printf(" hoi1c3 i = %d\n", i);
	if (i == 0)
		return (free_char_arr((void **)total_arr), free(next_line), 1);
	map->max_height = i;
	
	printf(" hoi1c4 \n");
	free(next_line);
	printf(" hoi1c5 \n");
	return (0);
}

int map_strarr(char* argv, map_data *map, char ***total_arr)
{
	int fd;
	char *next_line;
	int i;

	fd = open(argv, O_RDONLY);
	if(fd <= 0)
		return (1);
	printf(" hoi1a ");
	i = 0;
	*total_arr = malloc(sizeof(char *) * 100);//how to free??
    if (total_arr <= 0)
        return (close(fd), free_char_arr(*(void ***)total_arr), 1);
	next_line = (char *)1;
	printf(" hoi1c ");
	if (fill_strarr(next_line, *total_arr, fd, map) == 1)
		return (close(fd), 1);
	close(fd);
	printf(" hoi1d \n");
	return (0);
}

typedef struct index{
	int i;
	int n;
	int x;

} i_data;

int map_intarr(map_data *map, char **total_arr, i_data i)
{
	i.i = 0;
	i.n = 0;
	i.x = 0;
	while (i < map->max_height)
	{

		while (total_arr[i][n])
		{
			if (ft_isdigit(total_arr[i][n]))
			{
				map->coords[i][x].xyz[2] = SCALE(ft_atoi(&total_arr[i][n]), 40);
				map->coords[i][x].xyz[1] = SCALE(x, 40);
				map->coords[i][x].xyz[0] = SCALE(i, 40);
				x++;
				while (ft_isdigit(total_arr[i][n]))
					n++;
			}
			else
				n++;
		}
		x = 0;
		n = 0;
		i++;
	}
}
// printf(" nbr x %d \n", map->coords[i][x - 1].xyz[0]);
// printf(" nbr y %d \n", map->coords[i][x - 1].xyz[1]);
// printf("hoi4a\n");

int alloc_intarr(map_data *map)
{
	int j;

	j = 0;
	map->coords = malloc(sizeof(point *) * map->max_height);
	if(map->coords <= 0)
		return (1);
	while (j < map->max_height)
	{
		map->coords[j++] = malloc(sizeof(point) * map->max_width);
		if(map->coords[j - 1] <= 0)
			return (free_char_arr((void **)map->coords), 1);// nog correct doen
	}
	return (0);
}

int save_map(char* argv, map_data *map)
{
	int i;

	i = 0;
	// printf("\n w %d \n", map->max_width);
	// printf("\n h %d \n", i);
	char **total_arr;
	printf("hoi1\n");
	if(map_strarr(argv, map, &total_arr) == 1)
		return (1);
	printf("hoi2\n");
	// return (0);
	printf("hoi4 %s \t %s\n", total_arr[0], total_arr[1]);

	printf("hoi3\n");
	alloc_intarr(map);
	map_intarr(map, total_arr);

	printf("hoi8\n");
	free_char_arr((void **)total_arr);
	
	printf("hoiZ\n");
	assign_relative_coord(map);
	return (0);
}
// i = 0;
// while(next_line[i] != '\n' && next_line[i] != EOF)
// {
// 	if(!(next_line[i] == ' ' || ft_isdigit(next_line[i])))
// 		return(free_char_arr(next_line), write_error, NULL);
// 	i++;
// }

int get_points_width(char *str)
{
	int i;
	int points;

	points = 0;
	i = 0;
	if(!str)
		return (0);
	while(str[i])
	{
		if(ft_isdigit(str[i]))
		{
			while(ft_isdigit(str[i]))
				i++;
				// printf("hello");
			points++;
			if (!str[i])
				return (points);
		}
		// else if(!(str[i] == ' '))
		// 	return(free(str), write_error, -1);
		i++;
	}
	return (points);
}

void free_char_arr(void **arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}