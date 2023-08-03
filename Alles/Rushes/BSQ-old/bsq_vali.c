#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int	ft_strlen(char *str);

void falloc(char	**str_arr, char *c);

int validate_grid(int	rows, int	fd, char *c, int *start)
{
	int lenght;
	int		i;
	*start = ft_strlen(&c[0]) + 1;//read from start
	lenght = ft_strlen(&c[*start]);
	printf("start: %d\n", *start);
	printf("lenght line 0: %d\n", lenght);
	i = 0;
	while(i < rows)	
	{
		printf("lenght line %d: %d\n", i, ft_strlen(&c[*start + (lenght * i) + i]));// start + lenght x i. + i to include \n's
		if((ft_strlen(&c[*start + (lenght * i) + i])) != lenght)
		{
			falloc(0, c);
			close(fd);
			return (1);
		}
		i++;
	}
	return (0);
}

char	**parse_and_make_grid(int argc, char *argv[], int *grid_not_ok)
{
	char	*c;
	char	**str_arr;
	int		bytes;
	int 	start;
	int		rows;
	int		i;
	int		cols;
	int		fd = open(*argv, O_RDONLY);

	c = (char*)malloc(1000);
    if (fd == -1)
		perror("Error opening file");
	bytes = read (fd, c, 1000);// read until end
	rows = c[0] - '0';
	cols = (bytes - 5 - (rows - 1)) / rows;//only the gridbytes divided by the rows, you get cols
	if(validate_grid(rows, fd, c, &start))
		return (0);
	str_arr = (char**)malloc((rows + 1) * sizeof(char*));// rows + 1 to keap heap happy
	i  = 0;
	while(i < rows)
	{	
		str_arr[i] = (char*)malloc(cols + 1);//mallocate memory amount cols + \0 // cols + 1 to keap heap happy
		if(str_arr[i] == NULL)
			break ;
		ft_strncpy(str_arr[i], &c[start + (i * cols + i)], cols);//copying each line starting from 2nd(each char of col + total line breaks(i))
		printf("%s\n", str_arr[i]);
		i++;
	}
	close(fd);
	falloc(0, c);
	i = 0;
	return (str_arr);
}


int main(int argc, char *argv[])
{	
	char	**str_arr;
	int	grid_not_ok;
	int i;
	bytes = read (2, c, 1000)
	i = 1;
	while(argv[i])
	{
		str_arr = parse_and_make_grid(argc, &argv[i], &grid_not_ok);// malloced space, first address goes into str_arr
		if((str_arr))
		{
			//logic stuff
		}
		else
			printf("map error\n");
		if(str_arr != 0)
			falloc(str_arr, 0);// free  malloced space ifn't already
		i++;
	}
}

void falloc(char	**str_arr, char *c)
{
	int i;
	i = 0;
	if(str_arr)
	{
		while(str_arr[i])
		{	
			if(str_arr[i] != 0)
				free(str_arr[i]);
			i++;
		}
		if(str_arr)
			free(str_arr);
	}
	if(c)
		free(c);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\n' && i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\n')
	{
		i++;
	}
	return (i);
}