
#include "get_next_line.h"

#include <fcntl.h>
#include <time.h>
#ifndef BUFF_SIZE
#define BUFF_SIZE 2
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
				return (0);
			i++;
		}
	}
	return (1);
}

void print_list(t_list **list)
{
	t_list *print;
	print = *list;
	int i;

	i = 0;
	while(print != NULL)
	{
		//printf("%s\n", print->buffer);
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

void create_list(int fd, t_list **list, char *after_newline)
{
	int bytesread;
	char *buff_str;
	t_list *new_node;
	t_list *last_node;
	int i;

	buff_str = calloc(sizeof(char) , BUFF_SIZE);
	last_node = *list;
	after_newline = NULL;
	while(find_newline(last_node))//go to last of list and find
	{
		bytesread = read(fd, buff_str, 1);
		if(!bytesread)
			break ;
		new_node = ft_lstnew(ft_strdup(buff_str));
		ft_lstadd_back(list, new_node);
		last_node = ft_lstlast(*list);
	}
	free(buff_str);
	buff_str = 0;
}
//printf("\tbuff %s\t", buff_ini);
//				printf("\tt_strdup %s\t", after_newline);
//printf("%s", (*list)->buffer);
//printf("%s", new_node->next = ft_lstnew(after_newlinestr));
//printf("\nbytes read %d\n", bytesread);
//ft_lstadd_back(list, );
//printf("reading line until newline or NULL\n");

	////i = 0;
	//	//while(i < 10)
	//	//{
	//		bytesread = read(fd, buff_str, 1);
	//		if(!bytesread)
	//			break ;
	//		//printf(" %d ", bytesread);
	//	//	strcat(buff_str, buff_str);
	//	//	i++;
	//	//}
	//	//printf("%s-", buff_str);
	//	//if(ft_strchr(buff_str, '\n') != NULL && ft_strlen(ft_strchr(buff_str, '\n')))
	//	//{
	//	//	after_newline = ft_strdup(ft_strchr(buff_str, '\n') + 1);
	//	//	clear_after_newline(buff_str);
	//	//	new_node = ft_lstnew(ft_strdup(buff_str));
	//	//}
	//	//else
	//		new_node = ft_lstnew(ft_strdup(buff_str));
	//	ft_lstadd_back(list, new_node);
	//	last_node = ft_lstlast(*list);

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
	if(size > 1)
		next_line = make_next_line(list, size);
	return (next_line);
}
//printf("size nextstr= %d", size);
//void free_it(char *after_newline)
//{
//	free(after_newline);
//	after_newline = 0;
//}

void make_new_list(t_list **list, char *after_newlinestr)
{
	char *place_str;

	place_str = ft_strdup(after_newlinestr);
	*list = ft_lstnew(place_str);
	free(after_newlinestr);
	after_newlinestr = 0;
}

char *get_next_line(int fd)
{
	t_list *list = NULL; // first node
	char *next_line;
	char *after_newline;

	if(fd < 0 || BUFF_SIZE <= 0 || read(fd, next_line, 0) > 0)
		return (NULL);

	create_list(fd, &list, after_newline);

	next_line = ret_next_line(&list);

	ft_lstclear(&list);
	
	return (next_line);
}

void ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}//met '\0?

int main()
{
	char *next_line;
	int fd;
	clock_t tic = clock();
	fd = open("file.txt", O_RDONLY);
	
	while(next_line != NULL)
	{
		next_line = get_next_line(fd);
		if(next_line != NULL)
			ft_putstr_fd(next_line, 1);
	}     
	clock_t toc = clock();
    printf("\nElapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	close(fd);
}

