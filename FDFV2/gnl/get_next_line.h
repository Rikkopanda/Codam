/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:17:33 by rverhoev          #+#    #+#             */
/*   Updated: 2023/10/31 10:17:36 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include "stdlib.h"
# include "stdio.h"
# include "unistd.h"

typedef struct list
{
	char		*buffer;
	struct list	*next;
}	l_list;

char	*get_next_line(int fd);
char	*create_list(int fd, l_list **list);
char	*make_next_line(l_list **list, int size);
void	create_leftover(l_list **list, char *left_over_str);
char	*ret_next_line(l_list **list);

char	*ft_strchr(const char *s, int c);
l_list	*ft_lstnew_strdup(void *buffer);
void	gnl_lstclear(l_list **lst);
l_list	*lstlast0_lstback1(l_list **lst, l_list *new, int last0_back1);
int		find_newline(l_list *node);

#endif
