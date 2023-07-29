/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:43:00 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/27 19:04:05 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


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
void	print_number(char *array, int i)
{
	while (i >= 0)
	{
		write(1, &array[i], 1);
		i--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_length;
	int		rest;
	int		i;
	int		begin_nummer;
	char	array[12];

	if (check_args(base))
		return ;
	begin_nummer = nbr;
	i = 0;
	base_length = ft_strlen(base);
	while (nbr >= base_length)
	{
		rest = nbr % base_length;
		nbr = nbr / base_length;
		array[i] = base[rest];// array[0] = base[14]
		i++;
	}
	if (nbr <= base_length)
		array[i] = base[nbr];
	print_number(array, i);
}
// 					i			0		1	2	3
// 					nbr			22		11	5	2
// 					rest		0		1	1	0
// -\0 len			baselen		2		2	2	2
// 					array		0		1	1	0
// 					newnum		11		5	2	0
//					while		x		1	0	0
// array[int_length] = '\0';
// base string
// int arr
// rest = nr % baselen
// nr = nr / len
// arr[x++]	= base[rest] (rest is int getal kleiner dan basemax)
int	main(void)
{
	int test;
	// char decimal[] = "0123456789";
	char hex[] = "0123456789ABCDEF";
	char octal[] = "0123467";
	//char binary[] = "01";

	test = 222;
	ft_putnbr_base(test, octal);
	//ft_putnbr_base(test, hex);
}