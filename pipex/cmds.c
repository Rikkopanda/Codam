
#include "pipex.h"

void cmd(int pipe_send_to_cmd[2], int pipe_send_back[2], args_data *args, int i)
{
	char path[20];
	const char *envp[] = {"PATH=/bin:/usr/bin", NULL};

	dup2(pipe_send_to_cmd[READ], STDIN_FILENO);
	close(pipe_send_to_cmd[READ]);
	close(pipe_send_to_cmd[WRITE]); // Close the write end of the pipe in the child
	close(pipe_send_back[READ]);
	dup2(pipe_send_back[WRITE], STDOUT_FILENO);
	close(pipe_send_back[WRITE]);
	ft_strcpy(path, "/bin/");
	execve(ft_strcat(path, (*args).argssplit[i][0]), (*args).argssplit[i], (char **)envp);
	perror("execve");
	exit(EXIT_FAILURE);
}

