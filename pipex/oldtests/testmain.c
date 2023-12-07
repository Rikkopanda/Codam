

#include "pipex.h"

int main(int argc, char **argv)
{
	int fd[2];
	pipe(fd);
	int pid1 = fork();

	if (pid1 == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execlp("ls", "ls", "-l", NULL);
	}

	int pid2 = fork();

	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		// dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
		execlp("cat", "cat", NULL);
	}
	// char *buf;
	// buf = ft_calloc(10, 10);

	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);

	return 0;
}
