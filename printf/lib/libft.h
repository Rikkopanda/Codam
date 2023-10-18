#ifndef LIBFT_H
#define LIBFT_H

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>

typedef struct s_list
{
void *content;
struct s_list *next;
} t_list;

//			MEM
void *ft_calloc(size_t nmemb, size_t size);
void *ft_memcpy(void* dest, const void* src, size_t n);
void *ft_memset(void *s, int c, size_t n);
void *ft_memchr(const void *str, int c, size_t n);
void *ft_memmove(void *dest, const void *src, size_t n);
void ft_bzero(void *s, size_t n);
int ft_memcmp(const void *b1, const void *b2, size_t len);

//			STRING Functions
size_t ft_strlen(const char *s);
void ft_strcpy(char *dest, const char *src);
char *ft_strdup(const char *s);
char **ft_split(const char *s, char c);
char *ft_strjoin(char const *s1, char const *s2);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char *ft_substr(char const *s, unsigned int start, size_t len);
int ft_atoi(const char *str);
char *ft_itoa(int n);
void ft_putchar(char c);
size_t ft_strlcat(char *dst, const char *src, size_t size);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_strncmp(const char *s1, const char *s2, unsigned int n);
char	*ft_strcat(char *dest, char *src);
void ft_striteri(char *s, void (*f)(unsigned int, char*));
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncat(char *dest, char *src, size_t nb);
char *strnstr(const char *big,	const char *little, size_t len);
char *ft_strtrim(char const *s1, char const *set);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char *ft_strnstr(const char *big,	const char *little, size_t len);

//			FD Functions

void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putendl_fd(char *s, int fd);

//			IS Functions

int		ft_isalnum(int c);
int ft_isalpha(int);
int		ft_isprint(int c);
int ft_isascii(int c);
int ft_isdigit(int c);
int check_char_set(char chr, char *set);

//			TO	...

int		ft_toupper(int c);
int		ft_tolower(int c);


//			LISTS

void ft_lstdelone(t_list *lst, void (*del)(void*));
void ft_delete(void *content);
void ft_lstclear(t_list **lst, void (*del)(void*));
int ft_lstsize(t_list *lst);
void	ft_lstiter(t_list *lst, void (*f)(void *));
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_lstadd_front(t_list **lst, t_list *new);
void	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list *ft_lstnew(void *content);
t_list *ft_lstlast(t_list *lst);


#endif