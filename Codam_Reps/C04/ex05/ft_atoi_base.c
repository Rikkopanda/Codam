/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:43:00 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/26 12:03:40 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*start_initial_substring(char *str, char *base)
{
	int	i;
	int j;
	int	einde;

	einde = 0;
	i = 0;
	j = 0;
	
	while (str[i] != '\0' && einde == 0)
	{
		while(base[j] != '\0' && einde == 0)
		{
			if(str[i] != base[j])
			{
				einde = 1;
				str[i] = '\0';
				return (str);
			}
			
			j++;
		}
		j = 0;
		i++;
	}
	return (str);
}

char	*ft_atoi(char *str, char *base)
{
	int	i;
	int	min;
	int	einde;
	int j;

	einde = 0;
	i = 0;
	min = 0;
	while (str[i] != '\0' && einde == 0)
	{
		j = 0;
		while(base[j] != '\0' && einde == 0)//check if a basenr is equal and if its initial
		{
			if(str[i] == base[j])
			{
				str = start_initial_substring(&str[i], base);//deciding end of and adding /0
				einde = 1;
			}
			j++;
		}
		j = 0;
		i++;
	}
	
	return (str);
}
//returns address of index starting the initial string

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
	int i;
	printf("%s\n", str);
	str = ft_atoi(str, base);// becomes new address
	printf("%s", str);
	i = 0;
	dec_nbr = 0;
	base_len = ft_strlen(base);
	str_len = ft_strlen(str) - 1;//index should be
	while(i <= str_len)
	{
		j = 0;
		while(j <= base_len)
		{
			if(str[i] == base[j])
				nbr = j;
			j++;
		}
		dec_nbr += nbr* ft_iterative_power(base_len, str_len - i);
		i++;
	}
	return(dec_nbr);
}


int	main(void)
{
	char test[] = "aaaA31";
	// char decimal[] = "0123456789";
	char hex[] = "0123456789ABCDEF";
	// char octal[] = "01234567";
	//char binary[] = "01";
	printf("%d\n", ft_atoi_base(test, hex));
}

