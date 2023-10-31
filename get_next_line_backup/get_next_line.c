
#include "get_next_line.h"

#include <fcntl.h>
//#include <time.h>

int malloced;
int freeed;

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
	//printf("hello sizefunc\n");
	while(node != NULL)
	{
		while(node->buffer[i])
		{
			if(node->buffer[i] == '\n')
				end_found = 1;
			i++;
			//printf("size total str = %d\n", size);
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
	char *bigstring;

	bigstring = calloc(sizeof(char) , size + 1);
	end_found = 0;
	i = 0;
	str_i = 0;
	node = *list;
	
	//printf("hello\n");
	while(node != NULL)
	{
		while(node->buffer[i])
		{
			if(node->buffer[i] == '\n')
				end_found = 1;
			
			bigstring[str_i] = node->buffer[i];
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
	bigstring[str_i] = '\0';
	return (bigstring);
}


char *ret_next_line(t_list **list)
{
	char *next_line;
	int size;

	next_line = NULL;
	size = size_of_total_str(list);
	//printf("left %s", (*list)->buffer);
	//printf("size total str = %d\n", size);
	if(size > 1)
		next_line = make_next_line(list, size);
	//printf("new line %s", next_line);
	return (next_line);
}

char *create_list(int fd, t_list **list)
{
	int bytesread;
	char *buff_str;
	t_list *new_node;
	t_list *last_node;
	//printf("size = %d\n", BUFFER_SIZE);

	buff_str = calloc(sizeof(char), BUFFER_SIZE + 1);
	last_node = *list;
	while(find_newline(last_node))//go to last of list and find
	{
		bytesread = read(fd, buff_str, BUFFER_SIZE);
		//printf("%s", buff_str);
		if(!bytesread)
			break ;//free&return
		new_node = ft_lstnew_strdup(buff_str);//malloc lstbuffer & lst
		if(!new_node)
			break ;//free&return
		ft_lstadd_back(list, new_node);//add to back if there is list, else make *lst = new
		last_node = ft_lstlast(*list);
	}
	return(buff_str);
}

void create_leftover(t_list **list, char *left_over_str)
{
	t_list *new_node;
	t_list *last_node;
	int i;
	i = 0;
	//printf("\nleftover\n");
	last_node = *list;
	left_over_str = ft_strchr(left_over_str , '\n') + 1;
	//printf("\nleftover =  %s", left_over_str);
	while(1)
	{
		//left_over_str = ft_strchr(left_over_str , '\n') + 1;
		//printf("%s", left_over_str);
		new_node = ft_lstnew_strdup(&left_over_str[i]);// doesnt trim after \n but ok
		while(left_over_str[i] != '\n' && left_over_str[i])
			i++;
		if(!left_over_str[i] || !left_over_str[i + 1])// in case last char in buff = \n or last = \0
			break;
		i++;
		//printf("\na\n");
		//i++;
		if(!new_node)
			break ;//free&return
		ft_lstadd_back(list, new_node);//add to back if there is list, else make *lst = new
		//last_node = ft_lstlast(*list);
		//printf("left %s", new_node->buffer);
	}
	//printf("first after leftover %s", (*list)->next->next->buffer);
	//size_of_total_str(list);
}

char *get_next_line(int fd)
{
	static t_list *list = NULL; // first node
	char *last_buff;
	char *next_line;

	next_line = NULL;
	if(fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if(read(fd, next_line, 0) < 0)
		return (NULL);
	last_buff = create_list(fd, &list);
	next_line = ret_next_line(&list);// read untill newline.
	ft_lstclear(&list);//clear all untill first newline, then make first node the subsequent node if after newline excists.
	//printf("first buffer %s", list->buffer);
	//printf("new ? %s", list->buffer);
	if(ft_strchr(last_buff , '\n') && *(ft_strchr(last_buff , '\n') + 1))
		create_leftover(&list, last_buff);// fill whole newlines into seperate nodes. if createlist gave a leftover.
	//ft_lstclear(&list, left_over);
	//ft_lstclear(&list);
	free(last_buff);
	return (next_line);
}

void putstr(char *putstr)
{
	int size;
	size = 0;
	while(putstr[size])
		size++;
	//char null[] = "\n";
	write(1, putstr, size);
}
int main()
{
	char *next_line;
	int fd;
	int fd2;

	//clock_t tic = clock();
	fd = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	next_line = (char *)1;
	while(next_line != NULL)
	{	
		next_line = get_next_line(fd);
		if(next_line != NULL)
			putstr(next_line);
		free(next_line);
		//next_line = get_next_line(fd);
		//if(next_line != NULL)
		//	putstr(next_line);
		//free(next_line);
		//next_line = get_next_line(fd2);
		//if(next_line != NULL)
		//	putstr(next_line);
		//free(next_line);

		//next_line = get_next_line(fd);
		//if(next_line != NULL)
		//	putstr(next_line);
	}   
	//clock_t toc = clock();
    //printf("\nElapsed: %f seconds\n", (double)(toc - tic) / CLOCKS_PER_SEC);
	close(fd);
	close(fd2);
}

