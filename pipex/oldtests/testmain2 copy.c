
#include "pipex.h"

typedef struct data
{
    int pipefds[2];
    int status;
    char *totalbuf;
    int bytesread;
    pid_t p;
    pid_t genesispid;
} std_data;


char *ft_strcat_realloc(char *dst, char *src)
{
    if(dst != NULL)
    {
        char tmpstr[ft_strlen(dst) + 1];
        strcpy(tmpstr, dst);
        dst = realloc(dst, ft_strlen(dst) + ft_strlen(src) + 1);
        strcpy(dst, tmpstr);
        ft_strcat(dst, src);
    }
    else
    {
        dst = malloc(ft_strlen(src) + 1);
        strcpy(dst, src);
    }
    return (dst);
}

void pump_str(std_data *data)
{
    char *buf;
    buf = malloc(sizeof(char) * 10 + 1);
    data->totalbuf = NULL;
    while(read(data->pipefds[0], buf, 0) >= 0)
    {
        data->bytesread = read(data->pipefds[0], buf, 10);
        buf[data->bytesread] = '\0';
        // printf("buf = %s\n", data->buf);
        data->totalbuf = ft_strcat_realloc(data->totalbuf, buf);
    }
    free(buf);
}

int read_n_write(std_data *data)
{

    pump_str(data);
    write(data->pipefds[1], data->totalbuf, sizeof(char) * ft_strlen(data->totalbuf));
    printf("process 2 child %d\n", data->p);
    printf("process 2 %d\n", getpid());
    // close(pipefds[0]);
    // close(pipefds[1]);
    free(data->totalbuf);
    data->totalbuf = 0;
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
    int terminatedpid;

    if(getpid() == data.genesispid)
    {
        data.p = fork();

        if(!data.p)
        {
            dup2(data.pipefds[1], STDOUT_FILENO);
            close(data.pipefds[1]);
            execlp("ls", "ls", "-l", NULL);
        }
    }

    data.status = 0;
    while((terminatedpid = wait(&data.status)) > 0)
    {
        printf("process %d exited status %d\n", terminatedpid, data.status);
        // pump_str(&data);
        // data.buf = malloc(sizeof(char) * 20 + 1);
        // data.bytesread = read(data.pipefds[0], data.buf, 20);
        // data.buf[data.bytesread] = '\0';
        // printf("buf2= %s\n", data.totalbuf);
        // free(data.totalbuf);
        // data.totalbuf = 0;
    }
    return (0);
}

// void wait_all_n_read_pipe(std_data *data)
// {

// }