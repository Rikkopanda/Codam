/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:45:20 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/24 19:00:26 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str);

int	start_initial_substring(char *str);

int	ft_iterative_factorial(int nb)
{
	int (index),(result);

	index = 1;
	result = 1;
	index++;
	while(index <= nb)
	{
		result = result * index;
		index++;
	}
	if (nb == 0)
		return (0);
	return (result);
}

int main(int argc, char **argv)
{
	int result;
	int input;

	if (argc != 2)
		return (1);
	input = ft_atoi(argv[1]);
	result = ft_iterative_factorial(input);
	printf("%d", result);
}
// || ((2147483647 / nb) < nb) ||
// 	 	((-2147483648 / -nb) < -nb)) for overflow

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
	int	einde;

	result = 0;
	einde = 0;
	i = 0;
	min = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
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
