#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int main(int argc, char *argv[])
{
	char	*c;
	char	**str_arr;
	int		bytes;
	int		rows;
	int		i;
	int		cols;
	int		fd = open(argv[1], O_RDONLY);

	i  = 0;
	c = (char*)malloc(1000);
	if(argc != 2)
		return (0);
    if (fd == -1)
		perror("Error opening file");
	bytes = read (fd, c, 1000);// read until

	rows = c[0] - 48;
	cols = (bytes - 5 - (rows - 1)) / rows;
	
	str_arr = (char**)malloc(rows * sizeof(char*));
	while(i < rows)
	{
		str_arr[i] = (char*)malloc(cols + 1);
		ft_strncpy(str_arr[i], &c[5 + i * cols] ,cols);
		printf("%s", str_arr[i]);
// c[] start on beginning of line up to cols characters
		i++;
	}

	// printf("%s\n", c);
	printf("read return: %d\n", bytes);
	printf("rows: %d\n", rows);
	printf("cols: %d\n", cols);
	close(fd);
	i = 0;
	while(i < rows)
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
	free(c);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
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