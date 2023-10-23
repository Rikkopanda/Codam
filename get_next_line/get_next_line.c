
#include "get_next_line.h"

#include <fcntl.h>
#include <time.h>

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
	int size;

	next_line = NULL;
	size = size_of_total_str(list);
	if(size > 1)
		next_line = make_next_line(list, size);
	return (next_line);
}

void create_list(int fd, t_list **list)
{
	int bytesread;
	char *buff_str;
	t_list *new_node;
	t_list *last_node;

	buff_str = calloc(sizeof(char) , BUFF_SIZE + 1);
	last_node = *list;
	while(find_newline(last_node))//go to last of list and find
	{
		bytesread = read(fd, buff_str, BUFF_SIZE);
		if(!bytesread)
			break ;
		new_node = ft_lstnew_strdup(buff_str);
		ft_lstadd_back(list, new_node);
		last_node = ft_lstlast(*list);
	}
	free(buff_str);
	buff_str = 0;
}

char *get_next_line(int fd)
{
	t_list *list = NULL; // first node
	char *next_line;

	next_line = NULL;
	if(fd < 0 || BUFF_SIZE <= 0 || read(fd, next_line, 0) < 0)
		return (NULL);
	create_list(fd, &list);
	next_line = ret_next_line(&list);
	ft_lstclear(&list);
	return (next_line);
}

//void putstr(char *putstr)
//{
//	int size;
//	size = strlen(putstr) + 1;
//	write(1, putstr, size);
//}
int main()
{
	char *next_line;
	int fd;
	int fd2;
	int tmp;
	//clock_t tic = clock();
	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	next_line = (char *)1;
	while(next_line != NULL)
	{	
		next_line = get_next_line(fd);
		if(next_line != NULL)
			putstr(next_line);
		next_line = get_next_line(fd2);
		if(next_line != NULL)
			putstr(next_line);

	}     
	//clock_t toc = clock();
    //printf("\nElapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	close(fd);
	close(fd2);
}

