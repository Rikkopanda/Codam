
#ifndef PRACTICE_PIPEX_H
#define PRACTICE_PIPEX_H

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h> 
#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include <sys/wait.h>

#define WRITE 1
#define READ 0

void cmd1(int *pipe_send_to_cmd[2], int *pipe_send_back[2], char **argv);

#endif