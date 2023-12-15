#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define SHM_NAME "/counter_shared_memory"
#define SHM_SIZE sizeof(int)

void countup(int *cnt_ptr, int start, int end) {
    for (int i = start; i < end; i++)
        (*cnt_ptr)++;
    printf("%d\n", *cnt_ptr);
}

int main(void) {
    int shm_fd;
    int *shared_counter;

    // Create shared memory
    shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, SHM_SIZE);
    shared_counter = mmap(NULL, SHM_SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);

    // Initialize the shared counter
    *shared_counter = 0;
    pid_t p;
    p = fork();

    if (p == 0) {
        // Child process
        countup(shared_counter, 0, 1000);
    } else {
        // Parent process
        countup(shared_counter, 0, 1000);
        wait(0); // Wait for the child process to finish
    }
    printf("Final Count: %d\n", *shared_counter);
    // Clean up shared memory
    munmap(shared_counter, SHM_SIZE);
    close(shm_fd);
    shm_unlink(SHM_NAME);
    return 0;
}