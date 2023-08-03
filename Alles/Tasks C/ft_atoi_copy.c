/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rverhoev <rverhoev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:11:05 by rverhoev          #+#    #+#             */
/*   Updated: 2023/08/02 22:04:30 by rverhoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	start_initial_substring(char *str)
{
	int	resultaat;
	int	i;
	int	einde;

	einde = 0;
	resultaat = 0;
	i = 0;
	while (str[i] != '\0' && einde == 0)
	{
		if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
			einde = 1;
		resultaat = resultaat * 10 + str[i] - '0';
		i++;
	}
	return (resultaat);
}

int	ft_atoi(char *str)
{
	int	i;
	int	min;

	i = 0;
	min = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' && min == 0)
			i++;
		if (str[i] == '-')
			min++;
		if (!((str[i] >= '0' && str[i] <= '9') || 
				str[i] == '-' || (str[i] == '+')))
			return (0);
		if (str[i] >= '0' && str[i] <= '9')
		{
			if (((min % 2) == 0) || (min == 0))
				return (start_initial_substring(&str[i]));
			return (-(start_initial_substring(&str[i])));
		}
		i++;
	}
	return (0);
}
// vind eerste nummer
// lees totdat i+1 geen nummer meer is
// nummer = oude nummer * 10 + nieuwe
int main(void)
{
	int ret;
	char str[] = "   --0001-";
	ret = ft_atoi(str);
	printf("The ft_atoi substring is: %d\n", ret);
	return(0);
}
