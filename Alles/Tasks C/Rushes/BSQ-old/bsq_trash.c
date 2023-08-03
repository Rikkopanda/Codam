#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);



char **parse_and_make_grid(int argc, char *argv[], char	**c)
{
	int		bytes;
	int		rows;
	int		i;
	int		cols;
	int		fd = open(argv[1], O_RDONLY);
	char	**str_arr;

	*c = (char*)malloc(1000);
    if (fd == -1)
		perror("Error opening file");
	bytes = read (fd, *c, 1000);// read until
	rows = *c[0] - '0';
	cols = (bytes - 5 - (rows - 1)) / rows;//only the gridbytes divided by the rows, you get cols
	str_arr = (char**)malloc((rows) * sizeof(char*));
	i  = 0;
	while(i < rows)
	{
		str_arr[i] = (char*)malloc(cols + 1);//mallocate memory amount cols + \0 // cols + 1 to keap heap happy
		if(str_arr[i] == NULL)
			break ;
		ft_strncpy(str_arr[i], &(*c)[5 + (i * cols + i)], cols);//copying each line starting from 2nd(each char of col + total line breaks(i))
		i++;
	}
	free(c);
	close(fd);
	return(str_arr);
}

int main(int argc, char *argv[])
{
	char	**str_arr;
	int		i;
	char	*c;
	
	if(argc != 2)
		return (0);
	parse_and_make_grid(argc, argv, &c, str_arr);
	i = 0;
	while(str_arr[i] != 0)
	{
		free(str_arr[i]);
		i++;
	}
	free(str_arr);
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