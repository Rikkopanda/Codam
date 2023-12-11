
#include "pipex.h"

void cmd1(int *pipe_send_to_cmd[2], int *pipe_send_back[2], char **argv)
{
	char path[20];

	dup2(*pipe_send_to_cmd[READ], STDIN_FILENO);
	close(*pipe_send_to_cmd[READ]);
	close(*pipe_send_to_cmd[WRITE]); // Close the write end of the pipe in the child
	close(*pipe_send_back[READ]);
	dup2(*pipe_send_back[WRITE], STDOUT_FILENO);
	close(*pipe_send_back[WRITE]);
	char *envp[] = {"PATH=/bin:/usr/bin", NULL};
	
	ft_strcpy(path, "/bin/");
	execve(ft_strcat(path, argv2[0]), argv2, envp);
	perror("execve");
	exit(EXIT_FAILURE);
}
