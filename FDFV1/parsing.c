
#include "fdf.h"


int fill_strarr(char *next_line, char **total_arr, int fd, map_data *map )
{
	int i;

	i = 0;
	while (next_line)
	{
		next_line = get_next_line(fd);
		total_arr[i] = next_line;
		if (next_line == NULL)	
			break;
		map->max_width = get_points_width(next_line);
		i++;
	}
	if (i == 0)
		return (free_char_arr((void **)total_arr), free(next_line), 1);
	map->max_height = i;
	free(next_line);
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
	i = 0;
	*total_arr = malloc(sizeof(char *) * 200000);//how to free??
    if (total_arr <= 0)
        return (close(fd), free_char_arr(*(void ***)total_arr), 1);
	next_line = (char *)1;
	if (fill_strarr(next_line, *total_arr, fd, map) == 1)
		return (close(fd), 1);
	close(fd);
	return (0);
}

typedef struct index{
	int i;
	int j;
	int n;

} i_data;

int	fdf_ischar(char str_chr, char check)
{
	if (str_chr == check)
		return (1);
	return (0);
}

int parse_color(char *str)
{
	char *color_str;
	uint32_t color;

	color_str = ft_substr(str, 0, 8);
	color = ft_uint_atoi_base(color_str, "0123456789abcdef");
	printf("\n----%d----%s-----\n", color, color_str);
	free(color_str);
	color_str = 0;
	return (color);
}

int is_nul_or_eof(int c)
{
	if (c == EOF || c == '\0')
		return (1);
	return (0);
}

int map_intarr(map_data *map, char **total_arr, i_data *i)
{
	while (i->i < map->max_height)
	{
		while (total_arr[i->i][i->n])
		{
			if (ft_isdigit(total_arr[i->i][i->n]) || total_arr[i->i][i->n] == '-')//error handle still
			{
				map->coords[i->i][i->j].xyz[2] = SCALE(ft_atoi(&total_arr[i->i][i->n]), 100);
				map->coords[i->i][i->j].xyz[1] = SCALE(i->i, 100);
				map->coords[i->i][i->j].xyz[0] = SCALE(i->j, 100);
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
	//printf("hoi4a\n");
	return (0);
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

void init_indexes(i_data *i)
{
	i->i = 0;
	i->n = 0;
	i->j = 0;
}

int save_map(char* argv, ptrs *data)
{
	int i;
	i_data indexes;
	i = 0;

	char **total_arr;
	if(map_strarr(argv, &data->map, &total_arr) == 1)
		return (1);
	alloc_intarr(&data->map);
	init_indexes(&indexes);
	map_intarr(&data->map, total_arr, &indexes);
	free_char_arr((void **)total_arr);
	assign_relative_coord(data);
	return (0);
}
// printf("\n w %d \n", map->max_width);
// printf("\n h %d \n", i);
//printf("hoi4 %s \t %s\n", total_arr[0], total_arr[1]);
//printf("hoi3\n");
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
			if(str[i] == ',')
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