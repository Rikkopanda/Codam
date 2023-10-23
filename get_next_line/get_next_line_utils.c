

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

t_list *ft_lstnew_strdup(void *buffer)
{
	int len;
	char *new_str;
	char *str;
	size_t i;
	t_list *rtn;

	i = 0;
	str = buffer;
	while(str[i])
		i++;
	len = i;
	new_str = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	while(str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	rtn = (t_list *)malloc(sizeof(t_list));
	if(!rtn)
		return (NULL);
	(*rtn).buffer = new_str;
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
	while(current->next != NULL)
		current = current->next;
		
	return (current);
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
			free((*lst)->buffer);
			free((*lst));
			*lst = 0;
			*lst = tmp;
		}
	}
	lst = 0;
}
