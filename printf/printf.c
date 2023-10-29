

#include <unistd.h>
#include "lib/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>

//print all  types of data
//	"text text %(datatype1) text %(datatype2)" , variableof1 variableof2
//%[flags][width][.precision][length]specifier
//	%-+ #0	(hvlcharsprinten)*voorgaand arg		

char *write_address(void *ptr);
char hex_char(long long nbr);
void	*ft_realloc(void *ptr, size_t newsize);

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct alltags{
	char *pre_str;
	int precision; 
	char *FOUND_FLAGS;
	char FLAGS[10];
	char ALL_SPECIFIERS[30];
	char PRECIS_SPECIFIERS[10];
 	char LEN_L_SPECIFIERS[21];//longdouble
	char LEN_I_SPECIFIERS[21];//longint
	char LEN_h_SPECIFIERS[21];//shortint
};
//L: arg = long double voor e, E, f, g, G
//l: arg = long int voor i, d, o, u, x and X


void ft_putstr(char *s)
{
	write(1, s, ft_strlen(s));
}

char *f_char_str(va_list args)
{
	char *ret_ptr;
	
	ret_ptr = malloc(sizeof(char) * 2);
	if(ret_ptr == NULL)
			return(NULL);
	ret_ptr[0] = va_arg(args, int);
	ret_ptr[1] = '\0';
	return(ret_ptr);
}

void convert_to_nbr_str(char *nbr_str, unsigned int num, int cap, int nbrbase , int who_invokes)
{
	static int static_index = 0;
	char base_str[17];

	if(who_invokes == 0)
		static_index = 0;
	if(nbrbase == 8)
		ft_strcpy(base_str, "01234567");
	else if(cap == 1)
		ft_strcpy(base_str, "0123456789ABCDEF");
	else if(cap == 0)
		ft_strcpy(base_str, "0123456789abcdef");
	//printf("\nstr = %s\n", base_str);
	if(num >= nbrbase)
	{
		convert_to_nbr_str(nbr_str, num / nbrbase, cap, nbrbase, 1);
		convert_to_nbr_str(nbr_str, num % nbrbase, cap, nbrbase, 1);
	}
	if(num < nbrbase)
	{
		nbr_str[static_index] = base_str[num];
		static_index++;
		
		//printf("\nstatic nbr = %d\n", static_index);
		return ;
	}
}

char *f_nbrbase(va_list args, int cap, int nbrbase)
{
	
	char *nbr_str;
	unsigned int num;

	nbr_str = (char *)ft_calloc(sizeof(char), 12);
	if(nbr_str == NULL)
			return(NULL);
	num = va_arg(args, unsigned int);
	if(num == 0)
	{
		write(1, "0", 1);
		return (NULL);
	}
	convert_to_nbr_str(nbr_str, num, cap, nbrbase, 0);
	//printf("in octaaal!: %s\n", nbr_str);
	return(nbr_str);
}

char *f_putfnbr(double number, int precisie)
{
	int integers;
	char *fnbr_str;
	char after_point_str[20];
	char ptr_char;
	int i;

	//printf("\n nbr in f_ %f\n" , number);
	integers = (int)number;
	fnbr_str = ft_itoa(integers);
	i = 0;
	after_point_str[i++] = '.';
	while(i <= precisie)
	{
		number = number - integers;
		number = number * 10;
		integers = (int)number;
		after_point_str[i] = integers + 48;
		i++;
	}
	after_point_str[i] = '\0';
	ft_strcat(fnbr_str, after_point_str);
	
	return(fnbr_str);
}

void init_tagrules(struct alltags *tagrules)
{
	ft_strcpy(tagrules->FLAGS, "# +-0.*");
	tagrules->FOUND_FLAGS = malloc(sizeof(char) * 10);
	ft_strcpy(tagrules->FOUND_FLAGS, "");
	ft_strcpy(tagrules->ALL_SPECIFIERS, "cdieEfgGosuxXPn");
	tagrules->precision = 5;//standard
	tagrules->pre_str = NULL;
}
//L: arg = long double, voor e, E, f, g, G
//l: arg = long int, voor i, d, o, u, x and X
//h: arg = short int, voor i, d, o, u, x and X.

char parse_tags_preced(const char *format, struct alltags *tagrules, va_list args, int *i)
{
	int incr_i;
	//char ret_chr;
	while (format[*i] == ' ')
			(*i)++;
	if(format[*i] == '#')
	{	
		(*i)++;
		while (format[*i] == ' ')
			(*i)++;
		return('#');
	}
	if(format[*i] == '.')
	{
		(*i)++;
		if(format[*i] == '*')
		{
			tagrules->precision = va_arg(args, int);
			(*i)++;
			return ('*');
		}
		else
			tagrules->precision = format[*i] - 48;//fix catch edge cases still!  ft_atoi(&format[*i])
		incr_i = ft_strlen(ft_itoa(tagrules->precision));
		*i = *i + incr_i;
		return ('n');
	}
}


char *make_joined(char *pre_str, char *print_str)
{
	char *new_str;
	char *tmp_str;
	int strlen;

	strlen =  ft_strlen(pre_str) + ft_strlen(print_str) + 1;
	tmp_str = ft_calloc(sizeof(char), ft_strlen(print_str) + 1);
	ft_strcpy(tmp_str, print_str);
	free(print_str);
	print_str = 0;
	new_str = ft_strjoin(pre_str, tmp_str);
	//printf("new = %s ", new_str);
	return(new_str);
}

void f_join_str(char specifier, char *original_str, struct alltags *tagrules)
{
	char *pre_str;

	pre_str = ft_calloc(sizeof(char) , ft_strlen(original_str) + 5);
	if(ft_strchr(tagrules->FOUND_FLAGS, '#'))
	{
		char str[] = "0X";
		if(specifier == 'o')
			ft_strcpy(pre_str, "0");
		else if(specifier == 'x')
			ft_strcpy(pre_str, "0x");
		else if(specifier == 'X')
			ft_strcpy(pre_str, str);
		strcat(pre_str, original_str);
		ft_putstr_fd(pre_str, 1);
	}
	else
		ft_putstr_fd(original_str, 1);
	free(pre_str);
}

//new_str = make_joined(pre_str, print_str);
//new_str = ft_strjoin(pre_str, original_str);
//printf("\n str %s\n" , print_str);
//printf("new = %s ", print_str);
//printf("\n precision atoi %d\n" ,tagrules->precision);
//printf("\n char atoi %c\n" ,format[*i]);
//printf("\n str atoi %s\n" , &format[*i]);
//printf("\n incr_i %d\n" , incr_i);

int checkflagcases(struct alltags *tagrules, va_list args)
{
	int i;

	i = 0;
	while (tagrules->FOUND_FLAGS[i] && tagrules->FOUND_FLAGS[i] != '.')
		i++;
	if(tagrules->FOUND_FLAGS[i] == '.')
		i++;
	if(tagrules->FOUND_FLAGS[i] == '*')
		tagrules->precision = va_arg(args, int);
		
	return (0);
}

char parse_and_specify(const char *format, int *i, struct alltags *tagrules, va_list args)
{
	char *retval;
	int j;
	
	retval = NULL;
	while(format[*i] == ' ')
		*i = *i + 1;
	j = 0;
	while(ft_strchr(tagrules->FLAGS, format[*i]) != NULL)
	{	
		tagrules->FOUND_FLAGS[j] = format[*i];
		*i = *i + 1;
		j++;
	}
	if(format[*i] >= '0' && format[*i] <= '9')
		tagrules->precision = atoi(&format[*i]);
	while(format[*i] >= '0' && format[*i] <= '9')
		*i = *i + 1;
	tagrules->FOUND_FLAGS[j] = '\0';
	if(checkflagcases(tagrules, args));
		return (-1);
	if(ft_strchr(tagrules->ALL_SPECIFIERS, format[*i]) == NULL)
		return (-1);
	return (format[*i]);
}
	//printf("|p%dp|", tagrules->precision);
	//printf("|%c|", format[*i]);
//int yeeeaaahhhh(char specifier, char *print_str, va_list args)
//{
//}

char *unsigneditoa(va_list args)
{
	double u; 
	char *print_str;
	int s; 
	s = va_arg(args, unsigned int);
	printf(" a%da ", s);
	if(s < 0)
		u = 4294967295 - -s + 1;
	else
		u = s;
	//if(incoming < 0)
	//	incoming = incoming + UINT_MAX + 1;
	printf(" a%fa ", u);
	print_str = f_putfnbr(u, 0);
	return(print_str);
}

int ft_format(const char *format, char *print_str, va_list args, int *i)
{
	(*i)++;
	print_str = NULL;
	char flags[] = "-+ #";
	char width[] = "-+ #";
	int case_preced;
	struct alltags tagsrules;
	int j;
	char *ret_chars;
	char specifier;
	j = 0;
	init_tagrules(&tagsrules);
	ret_chars = ft_calloc(sizeof(char), 7);
	specifier = parse_and_specify(format, i, &tagsrules, args);
	if(check_char_set('*', tagsrules.FOUND_FLAGS))
		va_arg(args, int);
	if(format[*i] == 'd')
		print_str = ft_itoa(va_arg(args, int));
	else if(format[*i] == 's')
		print_str = ft_strdup(va_arg(args, char *));
	else if(format[*i] == 'c')
		print_str = f_char_str(args);
	else if(format[*i] == 'u')
		print_str = unsigneditoa(args);
	else if(format[*i] == 'o')
		print_str = f_nbrbase(args, 1, 8);//preceding cases
	else if(format[*i] == 'x')
		print_str = f_nbrbase(args, 0, 16);//preceding cases
	else if(format[*i] == 'X')
		print_str = f_nbrbase(args, 1, 16);//preceding cases
	else if(format[*i] == 'f')
		print_str = f_putfnbr(va_arg(args, double), tagsrules.precision);
	else if(format[*i] == 'p')
		print_str = write_address(va_arg(args, void *));
	if(print_str == NULL)
			return(1);
	if(ft_strlen(tagsrules.FOUND_FLAGS) > 0)
		f_join_str(format[*i], print_str, &tagsrules);
	else
		ft_putstr_fd(print_str, 1);
	free(print_str);
	free(ret_chars);
	print_str = 0;
	return (1);
}

void ft_printf(const char *str, ...)
{
	va_list args;
	int i;
	int sum;
	register char *print_str;
	i = 0;
	sum = 0;
	va_start(args, str);
	int print_bool;
	
	while(str[i] != '\0')
	{
		print_bool = 0;
		if(str[i] == '%')
		{
			ft_format(str, print_str, args, &i);
			va_arg(args, int);
			i++;
		}
		write(1, &str[i], 1);
		i++;
	}
	va_end(args);
}

char hex_char(long long nbr)
{
	char hex;
	char *hex_base = "0123456789abcdef";

	hex = hex_base[nbr];
	//printf("nbr = %d\n", nbr);
	return (hex);
}

char *write_address(void *ptr)
{
	int i;
	uintptr_t p;
	char *str;
	int j;
	long long test;

	test = (long long)ptr;
	j = 0;
	str = calloc(sizeof(char), 20);
	p = (uintptr_t)ptr;
	i = (sizeof(p) << 3) - 4; // 60

	while(i >= 0) // shift to get 
	{
		str[j] = hex_char((p >> i) & 15);
		// / 16 * 15 -> 16 * 14 -> 16 * 13 -> 16 * 12 -> 16 * 11
		//	% 15
		i = i - 4;
		j++;
	}
	return (str);
}
	//printf("size p %d\n", sizeof(p));
	//printf("size voidptr %d\n", sizeof(ptr));
	//printf(" i %d\n", i);
	//printf("address %d\n", test);
int main()
{
	double een = 3147;
	float twee = 12000;
	een = een - 0.333333;
	twee = twee - 0.333333;
	char test = 'a';
	int u = -23;


	ft_printf("\n\ttesting: u %   u \n", u);
	printf("O \ttesting: u %   u \n", u);

	//ft_printf("\n\ttesting: .n %   .12f \n", een);
	//printf("O \ttesting: .n %.12f \n", een);
	//ft_printf("\ttesting: .* %  .*faaaa \n", 4, een);
	//printf("O \ttesting: .* %  .*faaaa \n", 4, een);

	//ft_printf("\n\ttesting: %p hmmmmm\n", &een);
	//printf("O \ttesting: %p hmmmmm\n", &een);

	//ft_printf("\n\ttesting:X %  #X hmmmmm\n", een);
	//printf("O \ttesting:X %     #X hmmmmm\n", een);

	//ft_printf("\ttesting:x %x hmmmmm\n", een);
	//printf("O \ttesting:x %x hmmmmm\n", een);

	//ft_printf("\n\ttesting: %c hmmmmm\n", 'c');
	//ft_printf("\ttesting: %s hmmmmm\n", "waaaauw");

	//ft_printf("\n\t test octal:o %o hmmmmm\n", &een);
	//printf("O \t test octal:o %o hmmmmm\n", &een);

	//ft_printf("\n\t test octal:o %o hmmmmm\n", &een);
	//printf("O \t test octal:o %o hmmmmm\n", &een);
}











//int main()
//{
//	clock_t start, end;
//	double cpu_time_used;
//	start = clock();

//	//ft_printf("testing", 5, 2, 5, 6, 7, 8);
//	ft_printf("testing:%s", "1");
	

//	end = clock();
//	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
//	printf("cpu time %f seconds", cpu_time_used);
//}
void	*ft_realloc(void *ptr, size_t newsize)
{
	char	*newptr;
	size_t	cursize;

	if (ptr == 0)
		return (malloc(newsize));
	cursize = sizeof(ptr);
	if (newsize <= cursize)
		return (ptr);
	newptr = malloc(newsize);
	ft_memcpy(ptr, newptr, cursize);
	free(ptr);
	return (newptr);
}