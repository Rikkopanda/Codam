

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int  i;
	char *s1;
	
	s1 = (char *)s;
	i = 0;
	if(c > 256)
		c = c - 256;
	while(s1[i] != '\0')
	{
		if(s1[i] == c)
		{
			s1 = &s1[i];
			return (s1);
		}
		i++;
	}
	if(s1[i] == c)
			return (&s1[i]);
	return (NULL);
}

t_list *ft_lstnew(void *buffer)
{
	t_list *rtn;

	rtn = (t_list *)malloc(sizeof(t_list));
	if(!rtn)
		return (NULL);
	(*rtn).buffer = buffer;
	(*rtn).next = NULL;
	return (rtn);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	if(!lst || !new)
		return ;
	if(*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

t_list *ft_lstlast(t_list *lst)
{
	t_list *current;

	if(lst == NULL)
		return (0);
	current = lst;
	//printf("find last, i = %d\n", i);
	while(current->next != NULL)
	{
		current = current->next;
		//printf("find last, i = %d\n", i);
	}
		
	return (current);
}


char *ft_strdup(const char *s)
{
	int len;
	char *new_str;
	char *str;

	str = (char *)s;
	len = ft_strlen(str);
	new_str = (char *)malloc(sizeof(char) * len + 1);
	ft_strcpy(new_str, str);
	// 10 bytes (incl \n) +
	return (new_str);
}

size_t ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

void ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
		
	dest[i] = '\0';
}

void ft_lstclear(t_list **lst)
{
	t_list *tmp;

	if (!lst || !*lst)
		return ;
	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			ft_lstdelone(*lst);
			*lst = tmp;
		}
	}
	lst = 0;
}

void ft_lstdelone(t_list *lst)
{
	if(!lst)
		return ;
	free(lst->buffer);
	free(lst);
	lst = 0;
}