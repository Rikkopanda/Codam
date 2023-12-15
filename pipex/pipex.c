

#include "pipex.h"

char *read_fd(int fd)
{
	char *totalbuf;
    char *next_line;
	char *tmp_str;
    int j;

    j = 0;
    totalbuf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	totalbuf[0] = '\0';
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

void parse_args(args_data *args, char **argv, int argc)
{
	(*args).argssplit = malloc(sizeof(char **) * argc); //enough for extra null
	int i;

	i = 1;
	while(i < argc)
	{
		(*args).argssplit[i - 1] = ft_split(argv[i], ' ');
		i++;
	}
	(*args).argssplit[i - 1] = NULL;
}

void free_args(args_data *args)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while((*args).argssplit[i] != NULL)
	{
		while((*args).argssplit[i][j] != NULL)
		{
			free((*args).argssplit[i][j]);
			j++;
		}
		free((*args).argssplit[i][j]);
		j = 0;
		free((*args).argssplit[i]);
		i++;
	}
	free((*args).argssplit[i]);
	free((*args).argssplit);
}

void write_from_parent_to_cmd(int pipe_send_to_cmd[2], int pipe_send_back[2], char *buf)
{
	close(pipe_send_to_cmd[READ]); // Close the read end of the pipe in the parent
	write(pipe_send_to_cmd[WRITE], buf, strlen(buf));
	close(pipe_send_to_cmd[WRITE]);
	close(pipe_send_back[WRITE]);
	free(buf);
	buf = 0;
}

void receive(int sent_pipe[2], int receive_pipe[2], char **buf)
{
	close(sent_pipe[WRITE]);
	close(sent_pipe[READ]);
	close(receive_pipe[WRITE]);
	*buf = read_file(NULL, receive_pipe[READ]);
	close(receive_pipe[READ]);
}

void write_out_pluscleanup(args_data *args, char *buf)
{
	int status;
	wait(&status);
	int fd = open((*args).argssplit[3][0], O_WRONLY | O_CREAT | O_TRUNC);
	write(fd, buf, ft_strlen(buf));
	close(fd);
	free(buf);
	free_args(args);
}

// argv[1],argv[2],argv[3],argv[4], NULL
// < file | cmd1 | cmd2 > file2
// zelfde als(als shell command):
// < file cmd1 | cmd2 > file2 (vanwege <)
int main(int argc, char **argv)
{
	char *buf;
	int pipeA[2];
	int pipeB[2];
	int pipeC[2];
	args_data args;
	pid_t p;

	if(argc != 5)
		return (0);
	parse_args(&args, argv, argc);
	buf = read_file(argv[1], -1);
	pipe(pipeA);
	pipe(pipeB);
	p = fork();
	if (p == 0)
		cmd(pipeA, pipeB, &args, 1);
	write_from_parent_to_cmd(pipeA, pipeB, buf);
	pipe(pipeC);
	p = fork();
	if (p == 0)
		cmd(pipeB, pipeC, &args, 2);
	receive(pipeB, pipeC, &buf);
	write_out_pluscleanup(&args, buf);
}
// printf("%s\n", buf);
// printf("read buf = %s\n", buf);
// waitpid(p, &status, 0);// child grep waits for a write to pfds[]
