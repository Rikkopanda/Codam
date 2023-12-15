
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void countup(int *cnt_ptr, int start, int end) {
    for (int i = start; i < end; i++)
        (*cnt_ptr)++;
    printf("%d\n", *cnt_ptr);
}

int main(void) {
    int *parent_cnt_ptr;
    int *child_cnt_ptr;

    parent_cnt_ptr = malloc(sizeof(int));
    child_cnt_ptr = malloc(sizeof(int));

    pid_t p;
    p = fork();
    if (p == 0) {
        // Child process
        countup(child_cnt_ptr, 0, 1000);
    } else {
        // Parent process
        countup(parent_cnt_ptr, 0, 1000);
        wait(0); // Wait for the child process to finish
    }
    printf("Parent Count: %d\n", *parent_cnt_ptr);
    printf("Child Count: %d\n", *child_cnt_ptr);
    free(parent_cnt_ptr);
    free(child_cnt_ptr);
    return 0;
}
// void countup(int *cnt_ptr)
// {
// 	for(int i = 0; i < 100000; i++)
// 		*cnt_ptr = *cnt_ptr + 1;
// 	// printf("indexptr  %p\n", i);
// 	printf("%d\n", *cnt_ptr);
// }

// int main(void)
// {
// 	int *cnt_ptr;

// 	cnt_ptr = malloc(sizeof(int));

// 	pid_t p;
// 	p = fork();
// 	if(p == 0)
// 	{
// 		countup(cnt_ptr);
// 		exit(0);
// 	}
// 	else
// 	{
// 		wait(0);
// 		countup(cnt_ptr);
// 	}
// 	printf("cntptr %p\n", cnt_ptr);	
// 	printf("%d\n", *cnt_ptr);
// }
