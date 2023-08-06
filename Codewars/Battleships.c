//#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


void ValidateMap(char **BattleMap)
{




}


int main(int argc, char **argv)
{
	if(argc != 2)
		return (0);
	int		fd = open(argv[1], O_RDONLY);
	
	char *buffer;
	buffer = malloc(1000);
	bytes = read(fd, buffer, 1000)

	c = (char*)malloc(1000);

	i  = 0;
	
	
	close(fd)
}