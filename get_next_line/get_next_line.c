
#include "get_next_line.h"

#include <fcntl.h>

#ifndef BUFF_SIZE
#define BUFF_SIZE 10
#endif



int find_newline(t_list *node)
{
	int i;

	i = 0;
	if(node == NULL)
		return (1);
	else
	{
		while(node->buffer[i] != '\0')
		{
			if(node->buffer[i] == '\n' || node->buffer[i] == EOF)
			{
				printf("found in %s\n", node->buffer);
				return (0);
			}
			i++;
		}
	}
	return (1);
}

//void append(t_list **list, char *buf)
//{
//	t_list *new_node;
//	t_list *last_node;

//	new_node = malloc(sizeof(t_list));	
//	last_node = ft_lstlast(*list);

//	new_node->buffer = malloc(sizeof(char) * BUFF_SIZE + 1);
//	if(last_node == *list)
//		*list = new_node;
//	else
//	{
//		(*list)->next = new_node;
//	}
//}

void print_list(t_list **list)
{
	t_list *print;
	print = *list;
	int i;

	i = 0;
	while(print != NULL)
	{
		printf("%s\n", print->buffer);
		print = print->next;
		i++;
	}
}

void clear_after_newline(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] == '\n')
		{
			i++;
			while(str[i] != '\0')
			{
				str[i] = '\0';
				i++;
			}
			return ;
		}
		i++;
	}
}

void create_list(int fd, t_list **list)
{
	int bytesread;
	char *buff_ini;
	t_list *new_node;
	t_list *last_node;
	char *after_newlinestr;

	buff_ini = malloc(sizeof(char) * BUFF_SIZE + 1);
	last_node = *list;
	after_newlinestr = NULL;
	while(find_newline(last_node))//go to last of list and find
	{
		bytesread = read(fd, buff_ini, BUFF_SIZE);
		buff_ini[BUFF_SIZE] = '\0';
		
		if(ft_strchr(buff_ini, '\n') != NULL)
		{
			after_newlinestr = ft_strdup(ft_strchr(buff_ini, '\n'));
			clear_after_newline(buff_ini);
			new_node = ft_lstnew(ft_strdup(buff_ini));
		}
		else
			new_node = ft_lstnew(ft_strdup(buff_ini));
		ft_lstadd_back(list, new_node);
		last_node = ft_lstlast(*list);
		if(after_newlinestr != NULL)
			new_node->next = ft_lstnew(after_newlinestr);

		printf("\nbytes read %d\n", bytesread);
		//ft_lstadd_back(list, );
		//printf("reading line until newline or NULL\n");
		//printf("%s", (*list)->buffer);
	}
	print_list(list);
}

int size_of_total_str(t_list **list)
{
	t_list *node;
	int i;
	int size;
	int end_found;

	end_found = 0;
	size = 1;
	i = 0;
	node = *list;
	while(node != NULL)
	{
		while(node->buffer[i])
		{
			if(node->buffer[i] == '\n')
				end_found = 1;
			//write(1, &node->buffer[i], 1);
			i++;
			if(end_found)
				break;
		}
		size = size + i;
		if(end_found)
			break;
		i = 0;
		node = node->next;
	}

	return (size);
}

char *make_next_line(t_list **list, int size)
{
	t_list *node;
	int i;
	int str_i;
	int end_found;
	char *bigassstring;

	bigassstring = malloc(sizeof(char) * size);
	end_found = 0;
	i = 0;
	str_i = 0;
	node = *list;
	while(node != NULL)
	{
		while(node->buffer[i])
		{
			if(node->buffer[i] == '\n')
				end_found = 1;
			bigassstring[str_i] = node->buffer[i];
			i++;
			str_i++;
			if(end_found)
				break;
		}
		i = 0;
		if(end_found)
			break;
		node = node->next;
	}
	bigassstring[str_i] = '\0';
	return (bigassstring);
}


char *ret_next_line(t_list **list)
{
	char *next_line;
	int i;
	int size;

	next_line = NULL;

	size = size_of_total_str(list);

	next_line = make_next_line(list, size);

	printf("size nextstr= %d", size);

	return (next_line);
}

char *get_next_line(int fd)
{
	static t_list *list = NULL; // first node
	char *next_line;
	//list = malloc(sizeof(t_list));
	//list->buffer = malloc(sizeof(char)  *BUFF_SIZE + 1);

	if(fd < 0 || BUFF_SIZE <= 0 || read(fd, &next_line, 0) < 0)
		return (NULL);
	
	create_list(fd, &list);

	next_line = ret_next_line(&list);

	ft_lstclear(&list);

	return (next_line);
}

int main()
{
	char *next_line;
	int fd;

	fd = open("file.txt", O_RDONLY);
	next_line = get_next_line(fd);
	printf("\nline = %s\n", next_line);
	next_line = get_next_line(fd)     ;
	printf("\nline = %s\n", next_ line);
	next_line = get_next_line(fd) ;
	printf("\nline = %s\n", next_line);           


	close(fd);
}

