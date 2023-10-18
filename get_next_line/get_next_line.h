
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H


#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"

typedef struct list
{
	char *buffer;
	struct list *next;
}	t_list;

char	*ft_strchr(const char *s, int c);
t_list *ft_lstnew(void *buffer);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
t_list *ft_lstlast(t_list *lst);
char *ft_strdup(const char *s);
size_t ft_strlen(const char *s);
void ft_strcpy(char *dest, const char *src);
void ft_lstclear(t_list **lst);
void ft_lstdelone(t_list *lst);

#endif