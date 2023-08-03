#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct	val_sq
{
	int	col;
	int	row;
	int	size;
};

struct	to_us_chars
{
	int		rows;
	int		cols;
	char	empty;
	char	obst;
	char	fill;
};

int	ft_strlen(char *str);
int		logic(char **str_arr, char *c);
int	malloc_char_struct(char **str_arr, struct to_us_chars *chars);
int	test_cells(char **str_arr, struct val_sq *curr_sq, 
	struct val_sq *biggest_sq,  struct to_us_chars *chars);
void	max_valid_u(char **str_arr, struct val_sq *curr_sq, struct to_us_chars *chars);
int	fill_chars(char *c, char **str_arr, struct to_us_chars *chars);

int	get_filesize(char *filename)
{
	char buffer[256];
	int total_bytes;
	int bytes;
	int fd;

	total_bytes = 0;
	bytes = 1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	while (bytes > 0)
	{
		bytes = read(fd, buffer, 256);//doesnt it read the same chars over?
		if (bytes > 0)
			total_bytes += bytes;
		if (bytes == -1)
		{
			close(fd);
			return (-1);
		}
	}
	if (close(fd) == -1)
		return (-1);
	return (total_bytes);
}

int	read_file(char *filename, int	filesize, char *complete_file)
{
	int fd;
	int i;

	i = 0;
	while (i <= filesize)
	{
		complete_file[i] = '\0';//mallocated string garbage set to \0
		i++;
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (read(fd, complete_file, filesize) == -1)// checking if readable
		return (-1);
	if (close(fd) == -1)
		return (-1);
	return (0);
}

int	not_printable(char c)
{
	if (' ' < c && c < '~')
		return (0);
	return (1);
}

int	valid_lines(char *complete_file, int filesize, int first_line_len, int rows)
{
	int	line_length;
	int	curr_line;
	int	i;

	i = -1;
	while (++i <= first_line_len) // move pointer over first line, decrease filesize the same way
	{
		complete_file++;// starting point of str moves
		filesize--;//for calculation, bytes/rows = cols
	}
	i = 0;
	line_length = (filesize - (rows - 1)) / rows; // (filessize - '\n') devided by rows = expected length of each line
	while (rows > 0)
	{
		curr_line = line_length;
		while (curr_line > 0)
		{
			if (complete_file[i] == '\n')//curr line has to hit 0 before complete_file[i] hits '\n' 
				return (-1);
			curr_line--;
			i++;// i should be on '\n' if file is correct
		}
		if (complete_file[i] != '\n' && rows != 1)
			return (-1);
		i++;//on '\n' , so skip over it to get to new line start[i]
		rows--;
	}
	return (0);

}

int	valid_files(char *complete_file, int filesize, struct to_us_chars *chars)
{
	int first_line_len;
	int i;

	first_line_len = 0;
	while (complete_file[first_line_len] != '\n' && complete_file[first_line_len])// if \n and if 0
		first_line_len++;// getting lenght of firstline
	i = 0;
	chars->rows = 0;
	while (i < (first_line_len - 3))// reading up to only numbers	eg. 9.xo
	{
		if ('0' <= complete_file[i] && complete_file[i] <= '9')
			chars->rows = chars->rows * 10 + (complete_file[i] - '0');
		else
			return (-1);
		i++;
	}
	chars->empty = complete_file[first_line_len - 3];
	chars->obst = complete_file[first_line_len - 2];
	chars->fill = complete_file[first_line_len - 1];
	if (chars->empty == chars->obst || chars->obst == chars->fill || chars->fill == chars->empty)
		return (-1);
	if (not_printable(chars->empty) || not_printable(chars->obst) || not_printable(chars->fill)
		|| chars->rows <= 0 || filesize <= (first_line_len + 1) || 
		valid_lines(complete_file, filesize, first_line_len, chars->rows))
		return (-1);
	return (0);
}

int	ft_strncpy(char *dest, char *src, unsigned int n, struct to_us_chars *chars)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\n' && i < n && src[i] != '\0')
	{
		if (src[i] != chars->empty && src[i] != chars->obst)
			return (-1);
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (0);
}

int	file_to_str_arr(char **str_arr, char *complete_file, struct to_us_chars *chars, int filesize)
{
	int	i;
	int	line_length;
	int	curr_row;

	(void)str_arr;
	i = 0;
	while (*complete_file != '\n')// going to the starting point of grid
	{
		complete_file++;
		filesize--;
	}
	complete_file++;
	line_length = (filesize - (chars->rows -1)) / chars->rows;// take into account line breaks -1(last line)
	curr_row = 0;
	while (curr_row < chars->rows)
	{
		str_arr[curr_row] = malloc(line_length * sizeof(char*));
		if (!str_arr)
			return (-1);
		if (ft_strncpy(str_arr[curr_row], &complete_file[curr_row * line_length + curr_row], line_length, chars) == -1)
			return (-1);//e.g. str[0],	&complete_file[0 * 27 + 0] starting [0]
						//e.g. str[1],	&complete_file[1 * 27 + 1] starting [28]
						//e.g. str[2],	&complete_file[2 * 27 + 2] starting [56]
		curr_row++;
	}
	return (0);
}

void falloc(char **str_arr, char *complete_file)
{
	int	i;

	i = 0;
	while (str_arr[i + 1])
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
	free(complete_file);
}

int	parse_and_make_grid(char *filename, struct to_us_chars *chars)
{
	int		filesize;
	char	*complete_file;
	char	**str_arr;

	filesize = get_filesize(filename);// reads file and returns total bytes
	if (filesize == -1)
		return (-1);
	complete_file = malloc(filesize + 1); // filesize + 1 for \0
	if (!complete_file)
		return (-1);
	if (read_file(filename, filesize, complete_file) == -1)//emptying garbage and reading if there are bytes agains
		return (-1);
	if (valid_files(complete_file, filesize, chars) == -1)//checks if format is correct, chars, rows. Also if lines are equal len
		return (-1);
	str_arr = malloc(chars->rows * sizeof(char*));//pointers to strings
	if (!str_arr)
		return (-1);
	if (file_to_str_arr(str_arr, complete_file, chars, filesize) == -1)//filling strings with filegrid
		return (-1);
	str_arr[chars->rows] = NULL;
	if (malloc_char_struct(str_arr, chars) == -1)//the 'logic'
		return (-1);
	falloc(str_arr, complete_file);
	return (0);
}

int main(int argc, char *argv[])
{	
	int	return_value;
	int i;
	struct to_us_chars	*chars;

	i = 1;
	(void)argc;
	chars = malloc(sizeof(struct to_us_chars));
	if (!chars)
		return (-1);
	while(argv[i])
	{
		return_value = parse_and_make_grid(argv[i], chars);
		if((return_value) == -1)
		{
			write(1, "map error\n", 10);
		}
		i++;
	}
	free(chars);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	malloc_char_struct(char **str_arr, struct to_us_chars *chars)//declaring and allocating square structs
{
	struct val_sq		*curr_sq;
	struct val_sq		*biggest_sq;

	curr_sq = malloc(sizeof(struct val_sq));
	biggest_sq = malloc(sizeof(struct val_sq));
	if (!curr_sq || !biggest_sq)
		return (1);
	chars->cols = ft_strlen(str_arr[0]);//put len into characteristic of grid
	biggest_sq->col = 0;
	biggest_sq->row = 0;
	biggest_sq->size = 0;
	curr_sq->col = 0;
	curr_sq->row = 0;
	curr_sq->size = 0;//starting values
	return (test_cells(str_arr, curr_sq, biggest_sq, chars));
}

int	print_buffer(char **str_arr, struct to_us_chars *chars)
{
	int	row;

	row = 0;
	while (row < chars->rows)
	{
		write (1, str_arr[row], chars->cols);
		write (1, "\n", 1);
		row++;
	}
	return (0);
}

int	draw_buffer(char **str_arr, struct val_sq *biggest_sq, 
	struct to_us_chars *chars)
{
	int	row;
	int	col;

	col = 0;
	row = 0;
	while (row <= biggest_sq->size)
	{
		if (col <= biggest_sq->size)
		{
			str_arr[biggest_sq->row + row][biggest_sq->col + col] = chars->fill;
			col++;
		}
		else
		{
			col = 0;
			row++;
		}
	}
	free(biggest_sq);
	return (print_buffer(str_arr, chars));
}

void	buffer_biggest(struct val_sq *curr_sq, struct val_sq *biggest_sq)
{
	biggest_sq->col = curr_sq->col;
	biggest_sq->row = curr_sq->row;
	biggest_sq->size = curr_sq->size;
}

int	test_cells(char **str_arr, struct val_sq *curr_sq,
	struct val_sq *biggest_sq, struct to_us_chars *chars)
{
	int				i;

	i = 0;
	while (i < (chars->rows * chars->cols))//i to try each position in grid
	{
		curr_sq->size = 0;
		max_valid_u(str_arr, curr_sq, chars); //= chars->size voor grootst mogelijke in die i
		if (curr_sq->size > biggest_sq->size) //bigger than last biggest
			buffer_biggest(curr_sq, biggest_sq); //replace biggest
		curr_sq->col++;
		if (curr_sq->col >= chars->cols)
		{
			curr_sq->col = 0;
			curr_sq->row++;
		}
		i++;
	}
	free(curr_sq);
	return (draw_buffer(str_arr, biggest_sq, chars));
}

int	check_left(char **str_arr, struct val_sq *curr_sq, 
	struct to_us_chars *chars)
{
	int	i;

	i = 0;
	while (i <= curr_sq->size)
	{
		if (str_arr[curr_sq->row + i][curr_sq->col] == chars->obst)
			return (0);
		i++;
	}
	return (1);
}

int	check_bottom(char **str_arr, struct val_sq *curr_sq, 
	struct to_us_chars *chars)
{
	int	i;

	i = 0;
	while (i <= curr_sq->size)
	{
		if (str_arr[curr_sq->row + curr_sq->size]
			[curr_sq->col + i] == chars->obst)
			return (0);
		i++;
	}
	return (1);
}

int	check_right(char **str_arr, struct val_sq *curr_sq, 
	struct to_us_chars *chars)
{
	int	i;

	i = 0;
	while (i <= curr_sq->size)
	{
		if (str_arr[curr_sq->row + i][curr_sq->col + curr_sq->size] 
			== chars->obst)
			return (0);
		i++;
	}
	return (1);
}

void	max_valid_u(char **str_arr, struct val_sq *curr_sq, 
	struct to_us_chars *chars)
{
	while ((curr_sq->col + curr_sq->size) < chars->cols && 
		(curr_sq->row + curr_sq->size) < chars->rows)// checking if its trying to makes squares out of grid
	{
		if (check_left(str_arr, curr_sq, chars) && // check if hits obstacle, index from start row up to size
			check_bottom(str_arr, curr_sq, chars) && 
			check_right(str_arr, curr_sq, chars))
			curr_sq->size++;//if it doesnt hit, try a bigger size square
		else
		{
			curr_sq->size--;//if the bigger size does hit. previous was the biggest solution for this index
			return ;
		}
	}
	curr_sq->size--;// if it hits the edge of map
}
