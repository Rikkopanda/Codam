

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main()
{
	
	pid_t mainpid = getpid();
	printf("main procces (pid) %d\n", mainpid);
	pid_t p = fork();

	// 	printf("child procces (pid) %d\n", getpid());
	// printf("p = %d\n", p);
	// if(p == 0)
	// 	printf("child procces (pid) %d\n", getpid());
	// printf("p = %d\n", p);
	fork();
	fork();
	fork();
	if(p == 0)
		printf("child procces (pid) %d\n", getpid());
	// printf("p = %d\n", p);
	// if(p != mainpid)
	// 	printf("child procces (pid) %d\n", getpid());
	// printf("Hello from pid: %d p = %d\n", getpid(), p);

	//printf(" %d \n", p);	
	return 0;
}
