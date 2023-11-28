
#include <fcntl.h>
#include <unistd.h>
#include "../libft/libft.h"

#define READ_SIZE 10


// rra rrb rrr      ra rb rr     pb pa    sa sb

typedef struct c_lst{
    char ra[3];
    char rb[3];
    char rr[3];
    char rra[4];
    char rrb[4];
    char rrr[4];
    char pa[3];
    char pb[3];
    char sa[3];
    char sb[3];

}  cmds;


// commands = malloc(sizeof(char *) * 10);
// if(!commands)
//     return (-1)
// while(i < 3)
//     commands[i++] = malloc(sizeof(char) * 4)
int init_command_names(cmds *commands)
{
    ft_strcpy(commands->ra, "ra");
    ft_strcpy(commands->rb, "rb");
    ft_strcpy(commands->rb, "rr");
    ft_strcpy(commands->rra, "rra");
    ft_strcpy(commands->rrb, "rrb");
    ft_strcpy(commands->rrr, "rrr");
    ft_strcpy(commands->pa, "pa");
    ft_strcpy(commands->pa, "pb");
    ft_strcpy(commands->sa, "sa");
    ft_strcpy(commands->sb, "sb");
    return (0);
}

int main(int argc, char **argv)
{
    char buffer[4000];
    char *total
    int bytesread;
    int i;
    char **commands;
    cmds commands;

    // save_list();
    // GNL

    // read_commands();
    // GNL

    // try_commands();
    // in sequence

    // check_list();

    i = 0;
    // while(1)
    // {
    //     bytesread = (int)read(0, &buffer[i], READ_SIZE);
    //     buffer[i + bytesread] = '\0';
    //     if(bytesread < READ_SIZE)
    //         break;
    //     i += READ_SIZE;
    // }

    

}

