

#include "practice_pipex.h"

int main(int argc, char **argv)
{
	int fd[2];

	if(argc > 1)
		if(!strcmp(argv[1], "clear"))
		{
			FILE *test = fopen("tricky.txt", "w");
			fclose(test);
			return (0);
		}
	int file_desc = open("tricky.txt", O_WRONLY | O_APPEND); 

    // here the newfd is the file descriptor of stdout (i.e. 1) 
    dup2(file_desc, 1);
	pid_t mainpid = getpid();
	printf("main procces (pid) %d\n", mainpid);
	pid_t p = fork();
	// argv[1] = malloc(sizeof(char) * strlen(" -l") + 1);
	// strcpy(argv[1], " -l");
	// argv[2] = NULL;
	if(!p)
		execvp("cat", &argv[1]);
	pid_t cpid = wait(NULL); /* reaping parent */
    printf("Parent pid = %d\n", getpid());
    printf("Child pid proccess ended = %d\n", cpid);
	if (p < 0)
		return (perror("Fork: "), 0);
	char buf[1025];
	char data[] = "hello..sample data";
	int n;

	pipe(fd);
	argv[1] = malloc(sizeof(char) * strlen("tricky.txt") + 1);
	argv[2] = malloc(sizeof(char) * strlen(ft_itoa(file_desc)));
	strcpy(argv[1], "tricky.txt");
	strcpy(argv[2], ft_itoa(file_desc));
	if (p)
		write(fd[1], data, strlen(data));
	// fork();
	if(read(fd[0], buf, 0) != -1)
	{
		n = read(fd[0], buf, 1024);
		buf[n] = '\0';
		printf("read %d bytes from the pipe: \"%s\"\n", n, buf);
	}	
	else
		perror("read");
	exit(0);

	return 0;
}
