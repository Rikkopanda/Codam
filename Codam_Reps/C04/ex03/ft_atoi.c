/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:11:05 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/28 11:58:43 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	start_initial_substring(char *str)
{
	int	resultaat;
	int	i;
	int	digit;
	int	einde;

	einde = 0;
	resultaat = 0;
	i = 0;
	while (str[i] != '\0' && einde == 0)
	{
		if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
			einde = 1;
		digit = str[i] - '0';
		resultaat = resultaat * 10 + digit;
		i++;
	}
	return (resultaat);
}

int	ft_atoi(char *str)
{
	int	i;
	int	min;
	int	result;

	result = 0;
	i = 0;
	min = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && result == 0)
			i++;
		if (str[i] == '-' && result == 0)
			min++;
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (result == 0)
				result = start_initial_substring(&str[i]);
		}
		i++;
	}
	if (!((min % 2) == 0))
		result = -result;
	return (result);
}
// vind eerste nummer
// lees totdat i+1 geen nummer meer is
// nummer = oude nummer * 10 + nieuwe
int main(void)
{
	int ret;
	char str[] = "++++---123aa23";
	
	ret = ft_atoi(str);
	printf("The ft_atoi substring is: %d\n", ret);
	
	return(0);
}
