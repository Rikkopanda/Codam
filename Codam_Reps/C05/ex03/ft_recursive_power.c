/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 19:45:20 by rverhoev          #+#    #+#             */
/*   Updated: 2023/07/24 12:54:22 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi(char *str);

int	start_initial_substring(char *str);

int	ft_iterative_factorial(int nb);

int	ft_recursive_power(int nb, int power)
{
	int	i;
	int	pow;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	pow = 1;
	i = 0;
	
	pow = ft_recursive_power(nb, power / 2);// maakt ook even getal ervan
	// min een macht
	if((power % 2) != 0)
		return nb * pow * pow; // keert nb * 1 * 1

	return (pow * pow);
}

int	main(int argc, char **argv)
{
	int	result;
	int	input;
	int	input2;

	if (argc != 3)
		return (1);
	input = ft_atoi(argv[1]);
	input2 = ft_atoi(argv[2]);
	result = ft_recursive_power(input, input2);
	printf("%d", result);
}

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
