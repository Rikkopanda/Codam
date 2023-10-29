

#include <stdlib.h>
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while(lst)
	{
		f(lst->content);
		printf("1 %s\n", (char *)lst->content);
		lst = lst->next;
	}
}

//void function3(void *content)
//{
//	//char *str = malloc(sizeof(char) * 5);
//	//ft_strcpy(str, "test");
//	free(content);
//}
//int main()
//{
//	t_list *head;

//	head = ft_lstnew("head0");
//	head->next = ft_lstnew("head1");
//	head->next->next = ft_lstnew("head1");

//	printf("1 %s\n", (char *)head->content);
//	ft_lstiter(head, function1);
//	printf("1 %s\n", (char *)head->content);

//}