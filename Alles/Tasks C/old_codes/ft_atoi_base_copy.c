/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:43:00 by rverhoev          #+#    #+#             */
/*   Updated: 2023/08/01 07:48:54 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	start_initial_substring(char *str, char *base) 
{
	int	resultaat;
	int	i;
	int	j;
	int	count;

	resultaat = 0;
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		j = 0;
		count = 0;
		while (base[j] != '\0')
		{
			if (str[i] == base[j])
				count = 1;
			j++;
		}
		if (!count)
			break;
		i++;
	}
	str[i] = '\0';
	return (0);
}//makes a new string(puts \0 at end) of foundend numbers (correct number base)

int	ft_atoi(char *str, char *base, int *min)
{
	int j;
	int i;

	i = 0;
	j = 0;
	*min = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' && min == 0)
			i++;
		if (str[i] == '-')
			*min = *min + 1;
		while (base[j] != '\0')
		{
			if (str[i] == base[j])
			{
				start_initial_substring(&str[i], base);
				return (i);
			}	
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
//changes i to index of point starting the initial string. 
//initial string contains only correct base numbers,
//because start_initial_sub puts a \0 when it sees other characters

int	check_args(char *base, int base_len)
{
	int	j;

	j = base_len;
	if (base_len <= 1)
		return (1);
	while (0 <= base_len)
	{
		while (0 <= j)
		{
			if (j != base_len)
			{
				if (base[base_len] == base[j])
					return (1);
			}
			if (base[base_len] == '+' || base[base_len] == '-')
				return (1);
			j--;
		}
		base_len--;
		j = base_len + 1;
	}
	return (0);
}

int	sub_string_to_int(char *str, char *base, int *min, int base_len)
{
	int i;
	int	j;
	int	dec_nbr;
	int str_len;
	int	nbr;

	str_len = 0;
	while (str[i] != '\0')
		str_len++;
	nbr = 0;
	dec_nbr = 0;
	i  = ft_atoi(str, base, min);
	while (i <= str_len)
	{
		j = 0;
		while (j <= base_len)
		{
			if (str[i] == base[j])
				nbr = j++;
			j++;
		}
		dec_nbr = dec_nbr * base_len + nbr;
		i++;
	}
	return (dec_nbr);
}
//1232
int	ft_atoi_base(char *str, char *base)
{
	int	dec_nbr;
	int	min;
	int	base_len;
	int	i;

	base_len = 0;
	while (base[i] != '\0')
		base_len++;
	if (check_args(base, base_len))
		return (0);
	dec_nbr = sub_string_to_int(str, base, &min, base_len);
	if (((min % 2) == 0) || (min == 0))
		return (dec_nbr);
	return (-dec_nbr);
}
//changes i to start, gives str from start terminator at end if non-base
int	main(void)
{
	char test[] = " +-+-1101";
	char hex[] = "0123456789ABCDEF";

	printf("%d", ft_atoi_base(test, "01")); 
}
