

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

typedef struct split_args
{
	char *argv2[3];       
	char **argv3tmp;


}	args_data;

void parse_args(args_data *args, char **argv)
{
	args->argv3tmp = ft_split(argv[2], ' ');
	args->argv2[0] = args->argv3tmp[0];
	args->argv2[1] = args->argv3tmp[1];
	args->argv2[2] = NULL;
}

int main(int argc, char **argv)
{
	if(argc != 5)
		return (0);
	// argv[1],argv[2],argv[3],argv[4], NULL
	// < file | cmd1 | cmd2 > file2
	// zelfde als(als shell command):
	// < file cmd1 | cmd2 > file2 (vanwege <)

	char *buf;
	int pipeA[2];
	int pipeB[2];
	int pipeC[2];
	int status;
	char path[20];
	char *argv2[3];       
	char **argv3tmp;

	buf = read_file(argv[1], -1);
	//printf("%s\n", buf);
	pipe(pipeA);
	pipe(pipeB);
	pid_t p = fork();
	if (p == 0) { // Child process
		cmd1(&pipeA, &pipeB, argv);
	}
	// Parent process
	close(pipeA[READ]); // Close the read end of the pipe in the parent
	write(pipeA[WRITE], buf, strlen(buf));
	close(pipeA[WRITE]);
	close(pipeB[WRITE]); 
	// sleep(10);
	pipe(pipeC);
	p = fork();
	if (p == 0) { // Child process
		dup2(pipeB[READ], STDIN_FILENO);
		close(pipeB[READ]);
		close(pipeB[WRITE]); // Close the write end of the pipe in the child
		close(pipeC[READ]);
		dup2(pipeC[WRITE], STDOUT_FILENO);
		close(pipeC[WRITE]); 
		// sleep(10);
		char *envp[] = {"PATH=/bin:/usr/bin", NULL};     
		argv3tmp = ft_split(argv[3], ' ');
		argv2[0] = argv3tmp[0];
		argv2[1] = argv3tmp[1];
		argv2[2] = NULL;		
		ft_strcpy(path, "/bin/");
		execve(ft_strcat(path, argv2[0]), argv2, envp);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	close(pipeB[READ]);
	close(pipeC[WRITE]);
	buf = read_file(NULL, pipeC[READ]);
	close(pipeC[READ]);
	// printf("read buf = %s\n", buf);
	// waitpid(p, &status, 0);// child grep waits for a write to pfds[]
	wait(&status);
	int fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC);
	write(fd, buf, ft_strlen(buf));
	close(fd);
	free(buf);
}
