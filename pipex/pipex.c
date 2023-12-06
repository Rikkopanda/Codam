

#include "pipex.h"

char *read_fd(int fd)
{
	char *totalbuf;
    char *next_line;
    int j;
    j = 0;
    totalbuf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	totalbuf[0] = '\0';
	char *tmp_str;
	tmp_str = malloc(1); //because realloc needs a malloced pointer
	while(1)
	{
        next_line = get_next_line(fd);
        if(next_line == NULL)
            break ;
		tmp_str = realloc(tmp_str, ft_strlen(totalbuf) + 1);
		ft_strcpy(tmp_str, totalbuf);
		totalbuf = realloc(totalbuf, ft_strlen(totalbuf) + ft_strlen(next_line) + 1);
		ft_strcat(totalbuf, next_line);
        free(next_line);
		next_line = 0;
	}
	free(tmp_str);
	free(next_line);
	return (totalbuf);
}

char *read_file(char *path, int fd)
{
	char *str;
	if(fd < 0)
	{
		fd = open(path, O_RDONLY);
		str = read_fd(fd);
		close(fd);
	}
	else
		str = read_fd(fd);
	return(str);
}

int main(int argc, char **argv)
{
	//if(argc != 5)
	//	return (0);

	// argv[1],argv[2],argv[3],argv[4], NULL
	// < file | cmd1 | cmd2 > file2
	// zelfde als(als shell command):
	// < file cmd1 | cmd2 > file2 (vanwege <)

	char *buf;
	int pipefds[2];

	buf = read_file(argv[1], -1);
    //printf("%s\n", buf);

	pipe(pipefds);
	pid_t p = fork();

	if(p)
		write(pipefds[1], buf, ft_strlen(buf));
	if(!p)
	{
		free(buf);
		dup2(pipefds[0], STDIN_FILENO);
		//dup2(pipefds[1], STDOUT_FILENO);
		close(pipefds[0]);
		//close(pipefds[1]);
		execlp("grep", "grep", "test", NULL);
		//execve()
		exit(0);
	}
	free(buf);

	//dup2(pipefds[0], STDIN_FILENO);
	//close(pipefds[0]);
	//buf = read_file(NULL, pipefds[0]);
	//free(buf);
	int status;
	//waitpid(p, &status, 0);
	//int fdpipe[2];
	//pipe(fdpipe);
	//int p = fork();
}
