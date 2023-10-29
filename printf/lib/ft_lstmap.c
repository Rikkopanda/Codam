

#include <stdlib.h>
#include "libft.h"

//cc ft_lstmap.c ft_lstnew.c ft_delete.c ft_strcpy.c ft_lstclear.c ft_lstdelone.c ft_lstadd_back.c ft_memcpy.c ft_lstlast.c ft_strlen.c

void	*hmmmmm(t_list *lst, t_list *lst2, void (*del)(void *))
{
	del(lst->content);
	ft_lstclear(&lst2, del);
	return (NULL);
}
void	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *lst2;
	t_list *node;
	t_list *made_content;
	int first;

	first = 1;
	if (!f || !lst || !del)
		return (NULL);
	while(lst)
	{
		made_content = f(lst->content);
		node = ft_lstnew(made_content);
		if(first == 1)
			lst2 = node;
		if(!node)
			return (hmmmmm(lst, lst2, del));
		lst->content = made_content;
		if(first == 0)
			ft_lstadd_back(&lst2, node);
		lst = lst->next;
		first = 0;
	}
	return(lst2);
}
//printf("1 %s\n", (char *)lst->content);


void *function1(void *content)
{
	char str[] = "test\0";
	content = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	ft_memcpy(content, str, 6);
	return (content);
}

//int main()
//{
//	t_list *head;
//	t_list *lsthead2;

//	head = ft_lstnew("head0");
//	head->next = ft_lstnew("head1");
//	head->next->next = ft_lstnew("head1");
//	head->next->next->next = NULL;

//	printf("before %s\n", (char *)head->content);

//	lsthead2 = ft_lstmap(head, &function1, ft_delete);

//	printf("after %s\n", (char *)lsthead2->content);
////	ft_lstclear(&lsthead2, ft_delete);
////	ft_lstclear(&head, ft_delete);
//}