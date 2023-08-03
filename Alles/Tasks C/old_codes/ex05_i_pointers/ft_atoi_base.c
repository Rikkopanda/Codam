/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:43:00 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/30 10:46:07 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void start_initial_substring(char *str, char *base) 
{
	int	resultaat;
	int	i;
	int	j;
	int count;

	resultaat = 0;
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{	
		j = 0;
		count = 0;
		while(base[j] != '\0')
		{
			if(str[i] == base[j])
				count = 1;
			j++;
		}
		if (!count)
			break;
		i++;
	}
	str[i] = '\0';
}//makes a new string(puts \0 at end) of foundend numbers (correct number base)

void	ft_atoi(char *str, char *base, int *min, int *i)
{
	int j;

	*i = 0;
	j = 0;
	*min = 0;
	while (str[*i] != '\0')
	{
		while (str[*i] == ' ' && min == 0)
			*i = *i + 1;
		if (str[*i] == '-')
			*min = *min + 1;
		
		while(base[j] != '\0')
		{
			if(str[*i] == base[j])
			{
				printf("in atoi%d  ", *i);
				//return (start_initial_substring(&str[*i], base));
				return ;
			}
		
		j++;
		}
		j = 0;
		// if (!(str[*i] == '-' || str[*i] == '+'))
		// 	return ;
		*i = *i + 1;
	}
}
//changes i to index of point starting the initial string. 
//initial string contains only correct base numbers,
//because start_initial_sub puts a \0 when it sees other characters
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	check_args(char *base)
{
	int	len;
	int	j;

	len = ft_strlen(base);
	j = len;
	if (len <= 1)
		return (1);
	while (0 <= len)
	{
		while (0 <= j)
		{
			if (j != len)
			{
				if (base[len] == base[j])
					return (1);
			}
			if (base[len] == '+' || base[len] == '-')
				return (1);
			j--;
		}
		len--;
		j = len + 1;
	}
	return (0);
}
int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	pow;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	pow = 1;
	i = 0;
	while (i < power)
	{
		pow = pow * nb;
		i++;
	}
	return (pow);
}

int	ft_atoi_base(char *str, char *base)
{
	int base_len;
	int str_len;
	int dec_nbr;
	int nbr;
	int j;
	int min;
	int i;
	check_args(base);
	//printf("%s\n", str);
	ft_atoi(str, base, &i, &min);//changes i to start, gives str from start terminator at end if non-base
	//also changes min if minus 
	dec_nbr = 0;
	base_len = ft_strlen(base);
	str_len = ft_strlen(str) - 1;//index should be
	printf("%d", i);
	//printf("%s", &str[i]);
	// while(i <= str_len)
	// {
	// 	j = 0;
	// 	while(j <= base_len)
	// 	{
	// 		if(str[i] == base[j])
	// 			nbr = j;
	// 		j++;
	// 	}
	// 	dec_nbr = dec_nbr + nbr * ft_iterative_power(base_len, str_len - i);
	// 	i++;
	// }
	return(dec_nbr);
}


int	main(void)
{
	char test[] = " -A31";
	// char decimal[] = "0123456789";
	char hex[] = "0123456789ABCDEF";
	// char octal[] = "01234567";
	//char binary[] = "01";
	ft_atoi_base(test, hex);
}

