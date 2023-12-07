
#include "pipex.h"

typedef struct data
{
    int pipefds[2];
    int status;
    char *buf;
    int bytesread;
    pid_t p;
    pid_t genesispid;
} std_data;


char *ft_strcat_realloc(char *dst, char *src)
{
    char tmpstr[ft_strlen(dst)];
    strcpy(tmpstr, dst);
    ft_realloc(dst, ft_strlen(dst));
    strcpy(dst, tmpstr);
    ft_strcat(dst, src);
}

int read_n_write(std_data *data)
{
    data->buf = malloc(sizeof(char) * 10 + 1);
    data->bytesread = read(data->pipefds[0], data->buf, 10);
    data->buf[data->bytesread] = '\0';
    printf("buf = %s\n", data->buf);
    data->buf = ft_strcat_realloc(data->buf, "man\n");
    write(data->pipefds[1], data->buf, sizeof(char) * ft_strlen(data->buf));
    printf("process 2 child %d\n", data->p);
    printf("process 2 %d\n", getpid());
    close(data->pipefds[0]);
    close(data->pipefds[1]);
    free(data->buf);
}

void wait_all_n_read_pipe(std_data *data)
{
    int terminatedpid;

    while((terminatedpid = wait(&data->status)) >= 0)
    {
        printf("process %d exited status %d\n", terminatedpid, data->status);
        data->buf = malloc(sizeof(char) * 20 + 1);
        data->bytesread = read(data->pipefds[0], data->buf, 20);
        data->buf[data->bytesread] = '\0';
        printf("buf2= %s\n", data->buf);
        free(data->buf);
    }
}

int main(int argc, char **argv)
{

    // sleep(10);
    std_data data;
    data.genesispid = getpid();
    printf("process 1 %d\n", data.genesispid);

    pipe(data.pipefds);

    data.p = fork();

    if(data.p)
    {
       printf("process 1 child %d\n", data.p);
       write(data.pipefds[1], "hello", sizeof(char) * ft_strlen("hello"));
    }
    if(!data.p)
    {
        read_n_write(&data);
        exit(1);
    }

    if(getpid() == data.genesispid)
    {
        data.p = fork();
        if(!data.p)
        {
            dup2(data.pipefds[1], 1);
            // close(data.pipefds[1]);
            execlp("ls", "ls", "-l", NULL);
        }
    }
    wait_all_n_read_pipe(&data);
    if(getpid() == data.genesispid)
    {
        data.p = fork();
        if(!data.p)
        {
            dup2(data.pipefds[1], 1);
            // dup2(1, data.pipefds[1]);
            // close(data.pipefds[1]);
            printf("\njhelloo\n");
            // execvp("sp1_exe", argv);
        }
    }
    data.status = 0;
    wait_all_n_read_pipe(&data);
    return (0);
}

